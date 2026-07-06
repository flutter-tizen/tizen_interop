# tizen_interop 개선 계획 (재검증 버전)

본 문서는 `tizen_interop` 프로젝트의 바인딩 생성 파이프라인·런타임 구조에 대한 개선안을 담는다. 1차 제안을 **실제 코드와 ffigen/symgen 구현을 근거로 다시 비판적으로 검증**해 작성한 버전이다. 1차 제안 중 일부는 잘못된 가정에서 출발했으므로 본 문서에서 **철회·수정·강화** 표시를 명확히 한다.

- 기준 시점: Tizen 10.0 바인딩
- 기준 도구: ffigen 11.0 (현재 사용), ffigen 20.1 (업그레이드 후보)
- 기준 코드 경로는 모두 `/home/jun/dev/os/f-project/tizen_interop` 하위

---

## 0. 목표 재확인

1. 불필요한 부분 제거, 본질만 남김.
2. 앱에서 API 호출 시 실행 지연 최소화.
3. 신규 API / 신규 Tizen 버전 추가 비용을 낮춤.

이 중 **2번(런타임 지연)은 현재 구조가 이미 거의 최적**에 가깝다는 점을 먼저 확정한다 (§1 참조). 따라서 본 개선안의 실질적 ROI는 **3번(관리 비용) → 1번(불필요 축소)** 순서로 크다.

---

## 1. 재검증: 런타임 지연은 이미 최적화되어 있다

`lib/src/lookup_provider.dart` / `lib/<v>/tizen.dart`를 검토한 결과, 다음은 **이미 잘 되어 있어 손대지 않는다**:

- `tizen.dart`의 각 `tizenXxx` getter가 `_tizenXxx ??= ...` 패턴으로 **최초 접근 시에만** `Tizen*` 인스턴스를 만든다 → 안 쓰는 모듈의 클래스·심볼맵 초기화 비용이 0이다.
- `LookupProvider.lookup()`이 심볼 → 라이브러리 매핑을 캐시하고 **같은 `.so`는 프로세스 내 1회만** `DynamicLibrary.open` 한다 (`lookup_provider.dart:30`).
- 각 API 함수포인터가 `late final _xxxPtr = _lookup(...)` 이라 **첫 호출 시에만** 심볼 해석, 이후 0 오버헤드.

즉 "앱 API 호출 지연"을 **구조 개편으로 더 줄일 여지는 매우 작다**. 추가로 줄이려면 링크 수준 최적화(다음 §6)를 써야 하는데 이는 별도 트레이드오프가 있다. 1차 제안서의 "런타임 최적화" 관련 아이템은 대부분 **placebo에 가깝다**는 것이 재검증의 결론.

---

## 2. 1차 제안 항목 재검증

| 번호 | 항목 | 1차 판단 | 검증 후 판단 | 근거 |
|---|---|---|---|---|
| P1-1 | ffigen 병렬 실행 | 5-8배 단축 | **유효** (단 기대치 하향) | `dart run ffigen`은 매번 Dart VM cold start + libclang 로드 → CPU보다 fork/IO가 병목. 실측 필요. |
| P1-2 | YAML 공통부 템플릿 감량 | ~1,500라인 | **유효, 단 구현 방법 수정** | ffigen은 YAML anchor 미지원 확인 (strings.dart). 따라서 "생성기가 메모리에서 완성된 YAML을 만들거나 stdin 주입"이 유일한 길. `dart run ffigen --config=<path>`만 지원 → **temp file로 넘겨야 함**. "stdin 직접 주입"은 불가. 1차 제안서 수정. |
| P1-3 | `Tizen*(DynamicLibrary)` 생성자 제거 | dead code | **조건부 유효, 주의 필요** | ffigen 11의 **표준 출력**이라 설정으로 끌 수 없음 → post-process 필요. 또한 이 생성자가 `tizen.dart`에서 `export`로 **외부에 공개되어 있어** 제거 시 **breaking change** 가능. 대체: ffigen 20의 **`@Native` 바인딩** 모드 사용 (ffigen 설정에서 `ffi-native: true`). 이 경우 두 생성자 모두 사라지고 정적 `@Native` 선언으로 바뀜. 단 `LookupProvider` 기반 라이브러리 라우팅과 호환되지 않음 (§6). |
| P1-4 | symgen 심볼맵 필터링 | 30-50% 감소 | **철회. 이미 구현되어 있음** | `packages/symgen/lib/src/generator.dart:72-98` — `_getFunctionNamesFromHeaders()`가 `headerPath` 아래 모든 `.h`를 스캔해 선언된 함수명만 심볼맵에 포함. `_getSymbols()`에서 `_headerFunctions.contains(symbol)` 체크. 1차 제안은 잘못된 추측이었다. |
| P2-5 | `modules.yaml` 단일 소스 | 3중 관리 해소 | **유효하고, 예상보다 효과 큼** | 현재 3곳에 중복 관리 중임을 재확인: (1) `symgen.yaml`의 `target-libraries`, (2) `entrypoints.h`의 `#include`, (3) 129개의 `ffigen_*.yaml` 각각의 `entry-points`/`include-directives`. 한 소스로 통합 가능. |
| P2-6 | 버전 diff `extends` | 신규 버전 수 십 줄 | **유효** | 6.0→10.0 모듈 변화 스캔 결과 대부분 +1~+5 수준. extends 구조가 자연스러움. |
| P2-7 | regex 파싱 제거 | fragile 제거 | **유효, 즉시 실행 가능** | `generate_tizen.py:69`가 `class Tizen<ver><Suffix>`를 regex로 매칭. modules.yaml을 도입하면 regex 자체 불필요. |
| P3-8 | 코어 셋만 기본 포함 | IDE 체감 개선 | **보류/권장하지 않음** | `example/integration_test/tizen_interop_test.dart`가 50+ 모듈을 실제로 호출 중. `mv_*`, `vc_*`, `yaca` 등을 "잘 안 쓰인다"고 가정한 1차 근거는 부정확. 사용자 breakage 리스크 큼. |
| P3-9 | 버전별 분리 배포 | 패키지 용량 | **보류** | pub 규약상 sub-path import는 가능하지만 "버전별 sub-package 분리"는 마이그레이션 비용이 큼. 현 구조 유지가 합리적. |
| P3-10 | `UnnamedUnion1/Struct1` 자동 제외 | `hide` 구문 제거 | **유효, 단 ffigen 11로는 제한적** | ffigen 11에는 unnamed struct·union 스킵 옵션이 명시적으로 없음. 20.1에는 `structs.exclude`/`unions.exclude` 필터는 있으나 이름이 자동 부여된 unnamed에 대한 제어는 검증 필요. 안전한 최소 개선은 **post-process로 `UnnamedUnion*/UnnamedStruct*`를 삭제하거나 rename** 하는 sed 단계 1줄. |
| P4-11 | `registerSymbols` 중복 호출 | 성능 | **철회. 무관함** | `_registeredSymbolMaps.add` 덕분에 실질 비용 0. 코드 명료성만 남고 최적화 가치는 없음. |
| P4-12 | 클로저 제거 | 클린업 | **철회** | 마이크로 최적화. 런타임 의미 없음. |

### 요약
- **철회: 3건** (P1-4, P4-11, P4-12) — 이미 해결되었거나 placebo였다.
- **유지 및 강화: 6건** (P1-1, P1-2, P2-5, P2-6, P2-7, P3-10).
- **조건부·주의: 2건** (P1-3, P3-8·P3-9).

---

## 3. 재검증 과정에서 새로 발견된 더 중요한 기회

### (신규) F1. ffigen 20의 `symbol-file` / `symbol-files`로 타입 중복 우회 제거
`scripts/README.md` §1~3("Handling Type Duplication Issues")의 수작업 `library-imports` + `type-map` 반복 대응은 ffigen의 **정식 기능으로 대체 가능**하다 (ffigen 11 README 끝부분에 명시).

- A 모듈이 공통 타입을 `output → symbol-file`로 산출
- B,C 모듈이 `import → symbol-files`로 재사용 → 자동으로 중복 없이 import 구문만 생성

이 기능을 쓰면 현 "수작업으로 `type-map`을 129개 파일에 복제"하는 패턴을 끝낼 수 있다. **단, ffigen 버전 업그레이드(11 → 18+/20)가 필요**하며, 업그레이드 자체가 전수 재생성 테스트를 요구한다. 단계적 적용 권장.

### (신규) F2. ffigen 20의 `include-unused-typedefs`로 dummy 헤더 제거
현재 `scripts/README.md` §4가 "ffigen이 미사용 콜백 타입을 생략하므로, `_force_generate_XXX_cb(app_event_cb)` 같은 더미 함수를 담은 `entrypoints_XXX.h`를 수작업으로 두어 강제 노출"시킨다 (실물: `configs/10.0/entrypoints_capi_appfw_app_common.h`).

ffigen 20의 `include-unused-typedefs: true` 설정으로 **더미 헤더 파일들을 제거 가능**. 현재 6개 버전에 걸쳐 `entrypoints_*.h` 추가 파일이 2~3개씩 존재 → **약 12-18개 파일 및 대응 ffigen YAML 분기 로직 제거**.

### (신규) F3. `dart run ffigen`의 Dart VM 시작 비용
`dart run ffigen` 호출 자체가 1-3초의 부트스트랩을 포함한다 (패키지 해석 + VM 시작 + libclang 로드). 129회 → **누적 2-6분**이 "실제 ffigen 실행"이 아닌 기동 오버헤드. 대응 방법:

1. `dart pub global activate ffigen`으로 AOT snapshot 사용
2. 또는 ffigen을 포크/수정해 다중 config를 **단일 프로세스로 순차 처리**하는 CLI를 제공(상류 PR 후보)
3. 또는 ffigen을 `Isolate.run` 기반의 내부 API로 호출하는 헬퍼 작성

1번이 가장 저비용. **병렬화(P1-1)와 결합하면 체감 빌드 시간은 수십 초대**로 떨어질 것으로 기대.

### (신규) F4. 생성 결과 캐싱
현재 `generate_bindings.sh`는 매번 129개 전부 재생성. 실제로 변경된 모듈은 버전 간 거의 없음에도. 대응:

- 입력 해시(yaml + 관련 .h 머클 트리 + rootstrap/<v>의 해당 include 디렉토리) → 변경 없으면 skip.
- 초기 구현은 `sha256`으로 입력 해시 파일 생성, diff 나오는 모듈만 재호출하면 충분. <30줄 Python.

### (신규) F5. 큰 바인딩 파일을 줄이는 건 사실상 불가능
`capi_network_bluetooth.dart`가 13,502줄인 이유는 블루투스 API 표면 자체가 그만큼 크기 때문이며, **ffigen 설정으로는 줄일 실질 수단이 없다**. "파일 분할"은 선언 범위가 C 헤더와 일치해야 하는 ffigen 특성상 어렵다. 이 파일들은 **그대로 유지**하고, 전체 `dart analyze` 시간이 문제라면 §6(링크-레벨)에서 다룬다.

---

## 4. 수정된 실행 계획

우선순위별 3 트랙으로 재편한다.

### 트랙 A — 즉시 실행 (1~2일, 리스크 최소)

- **A1. 병렬 빌드 스크립트** (P1-1 축소본)
  - `scripts/generate_bindings.sh`를 `xargs -P$(nproc)` 또는 Python `concurrent.futures.ProcessPoolExecutor`로 치환.
  - 기대 효과: 129개 ffigen 실행의 wall time을 **4-6배** 단축 (CPU 바운드 한도). 기대치를 과장하지 않기 위해 기존 값 대신 **실측 후 갱신**하는 것을 권장.
  - 리스크: 동일 출력 경로 없음 확인됨(각 YAML `output:` 서로 다름). 병렬 안전.
- **A2. `UnnamedUnion*/UnnamedStruct*` post-process** (P3-10 축소본)
  - `scripts/generate_bindings.sh` 끝단에 Python 1개 파일(~50줄)로 생성물 스캔 → 해당 선언이 중복 노출될 만한 파일에서 rename 또는 private화(`_UnnamedUnion1`).
  - `generate_tizen.py:115`의 `hide UnnamedUnion1, UnnamedStruct1` 특례 규칙 제거 가능.
  - 리스크: 낮음. regex 쉽게 검증 가능.
- **A3. 입력 해시 기반 skip** (F4)
  - `configs/<v>/.build_cache.json`에 각 YAML + 참조된 rootstrap 서브트리의 sha256 저장. 변경 없으면 해당 ffigen 호출 skip.
  - 기대: 일상적인 재생성을 **수 초**대로 축소.

### 트랙 B — 관리 비용 절감 (1~2주, 리스크 중간)

- **B1. `modules.yaml` 단일 소스 도입** (P2-5)
  - 스키마 예시:
    ```yaml
    # configs/10.0/modules.yaml
    base: 9.0         # optional, 버전 간 diff 베이스
    common_include_dirs:
      - usr/include/
      - usr/include/appfw/
      # ... 공통 rootstrap include
    modules:
      - name: capi_appfw_app_common
        library: libcapi-appfw-app-common.so.0
        headers:
          - app_common.h
          - app_resource_manager.h
        extra_compiler_opts: []
      # ...
    ```
  - 이 하나로 `symgen.yaml`·`entrypoints.h`·`ffigen_*.yaml` 3종이 전부 산출된다.
  - `generate_ffigens.py`의 규모를 2/3 이상 감축할 수 있고, `scripts/README.md`의 9단계 절차가 3단계(① `modules.yaml` 편집 ② `scripts/rebuild.sh <v>` ③ 테스트)로 축소.
- **B2. `generate_tizen.py`의 regex 제거** (P2-7)
  - B1 산출물(modules.yaml)이 이미 모듈↔클래스명↔심볼맵 이름의 정답을 갖고 있으므로 regex 불필요. Python dict 한 번 순회로 출력.
- **B3. 버전 diff `extends`** (P2-6)
  - `modules.yaml`에 `base: 9.0`, `add: [...]`, `remove: [...]` 섹션 허용. 신규 버전 추가 비용을 모듈 1-2줄 수준으로 축소.
  - 유의: 실제 변경이 커지면 일반 파일로 fall back. 하드 규약이 아닌 옵션으로 둔다.

### 트랙 C — ffigen 업그레이드 (2~3주, 리스크 큼, 가치 큼)

- **C1. ffigen 11 → 18 또는 20으로 업그레이드**
  - 사전: 6개 버전 전부 회귀 테스트 필요. 변경된 생성 규칙이 있으면 `export ... hide ...` 패턴이 바뀔 수 있음.
  - 획득: `symbol-file`/`symbol-files`, `include-unused-typedefs`, `exclude-all-by-default`, `member-filter`, `ffi-native` 등.
- **C2. `scripts/README.md §1~3` 타입 중복 우회 제거** (F1)
  - C1 완료 후 `symbol-file`/`symbol-files`로 재작성. 수작업 `library-imports`·`type-map`을 모듈 메타에서 자동 산출.
- **C3. `entrypoints_*.h` 더미 헤더 제거** (F2)
  - `include-unused-typedefs: true` 도입. 검증 방법: 현재 더미 헤더로 강제 노출되던 콜백들이 여전히 생성되는지 diff.
- **C4. (선택) `ffi-native` 전환 검토**
  - Dart SDK 3.1+이 `@Native` 정식 지원. `LookupProvider`를 폐지하고 VM이 직접 로드 처리. 이 경우 **다수 `.so`를 지연 로드하는 현 설계가 깨짐** → Tizen 환경에서 모든 .so를 eager 로드할지, 아니면 assetId별 `@Native(assetId: ...)`를 쓸지 설계 결정 필요.
  - 트레이드오프가 크므로 별도 RFC 문서로 분리 권장.

---

## 5. 하지 않기로 한 결정 (보류·기각)

| 항목 | 판단 | 이유 |
|---|---|---|
| 코어셋/opt-in 서브패키지 분할 (P3-8) | 보류 | `example`이 이미 50+ 모듈 동시 사용. 다운로드 텔레메트리 없이 임의 판단 시 사용자 breakage. |
| 버전별 분리 배포 (P3-9) | 보류 | pub semver와 flutter-tizen 플러그인 생태계 영향 큼. |
| 심볼맵 초기화 최적화 (P4-11/12) | 기각 | 실측 비용 무시 가능. 코드 명료성 개선은 트랙 B에서 자연 해결. |
| 바인딩 파일 세분할 | 기각 | ffigen이 1 YAML → 1 Dart 모델. C 헤더 범위와 묶이기 때문에 추가 분할해도 관리성만 악화. |
| DynamicLibrary 생성자 제거 단독 시행 | 보류 | C4(Native 전환)의 부분 집합이 더 깔끔. 단독 시행 시 breaking change만 남고 이득이 작음. |

---

## 6. 수치·리스크 요약

### 수치 (현재 상태, 2026-04-23 측정)

- 바인딩 파일: **757개 / 1,567,427 라인** (6.0~10.0 합)
- Tizen 10.0 기준: **130 파일 / 282,638 라인**, `generated_symbols.dart` 6,501 라인
- ffigen_*.yaml: 버전당 116~132 (10.0은 129)
- 공통 include 경로가 129개 YAML에 복제됨 (YAML당 ~50라인 × 129 ≈ **6,450 라인의 순수 중복**)

### 개선 기대치 (보수적)

| 지표 | 현재 | 트랙 A 후 | 트랙 A+B 후 | 트랙 A+B+C 후 |
|---|---|---|---|---|
| 한 버전 ffigen 재생성 wall time | ~10분 | ~2분 | ~1분 (캐시 적중 시 < 10초) | 동일 |
| YAML 관리 라인(버전당) | ~10,000 | ~10,000 | **~1,500** | ~1,200 |
| 신규 버전 추가 수작업 단계 | 9 | 8 | **3** | 3 |
| 타입 중복 수작업 패치 개수 | ~10/버전 | ~10 | ~10 | **~0** |
| 더미 `entrypoints_*.h` | 12~18개 | 12~18 | 12~18 | **0** |

**런타임 지연은 모든 트랙에서 변화 없음** — §1의 이유로 당연한 결과. 이 사실을 문서화해 더 이상 runtime 최적화를 실적 목표로 삼지 않는다.

### 리스크

- **트랙 A**: 병렬화 시 libclang 메모리 피크가 늘어 CI 환경에서 OOM 가능. `-P` 값을 보수적으로 설정 (예: CPU 코어 수의 절반).
- **트랙 B**: `modules.yaml` 스키마가 초기에 추측성이 됨. Tizen 11.0 나오기 전에 실증 기회 필요.
- **트랙 C**: ffigen 업그레이드로 주석·doxygen·enum renaming 세부가 달라질 가능성. diff 검증에 1~2일 추가 예상.

---

## 7. 검증 체크리스트 (실제로 개선이 되는지 확인)

구현 후 아래 항목을 전부 통과해야 "실제 유효"한 개선이다.

- [ ] `scripts/generate_bindings.sh <v>`의 실제 wall time이 이전 대비 단축 (시간 실측 로그 기록).
- [ ] `dart analyze lib/<v>/tizen.dart`의 에러·경고 수 동일 또는 감소.
- [ ] `example/integration_test/tizen_interop_test.dart` 기존 테스트 전부 통과 (모든 버전).
- [ ] `configs/<v>/` 디렉토리의 총 라인 수가 기대치만큼 감소.
- [ ] 신규 Tizen 버전을 trial-run으로 추가해 `scripts/README.md` 신 절차가 실제 성립하는지 확인.
- [ ] 기존 사용자(example 포함)의 공개 API 호출 변경 없음 확인 (공개 `Tizen*` 클래스·`tizenXxx` getter 시그니처 diff).

---

## 8. 결론

1. **런타임 지연 최소화는 이미 달성됨**(지연 lazy 전개 + 심볼맵 캐시). 여기에 더 투자하는 것은 ROI가 낮다.
2. **관리 비용 문제가 실질적인 병목**이며, 한 번의 `modules.yaml` 단일 소스 도입(트랙 B)만으로 신규 버전·모듈 추가 비용이 질적으로 감소한다.
3. ffigen 업그레이드(트랙 C)는 `scripts/README.md §1~4`의 수작업 대응을 제거하는 가장 큰 정합성 개선이며, 단독으로도 의미 있다. 단 회귀 테스트가 중요하므로 트랙 A/B와 분리해 진행.
4. "바인딩 파일·라인 수를 대폭 줄인다"는 발상은 **대체로 불가능**하다. C 헤더 표면이 그만큼이기 때문. 줄여야 하는 건 **메타 관리 표면**이다.

**권장 진행 순서**: 트랙 A → 트랙 B → (별도 RFC로) 트랙 C.
