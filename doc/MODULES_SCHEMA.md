# modules.yaml 스키마 (트랙 B)

`configs/<version>/modules.yaml`은 **하나의 파일에서** 기존 3종을 전부 산출한다:

1. `configs/<version>/symgen.yaml`
2. `configs/<version>/entrypoints.h` (+ 모듈별 `entrypoints_*.h` 더미)
3. `configs/<version>/ffigen_*.yaml` (모듈당 1개, 총 100+개)

## 1. 검증 목표

**byte-for-byte YAML 동등성은 목표가 아니다.**
- 기존 `ffigen_*.yaml`에는 중복·포매팅·섹션 주석 등 스타일이 섞여 있음
- 재생성된 YAML은 규칙적인 포매팅을 쓰되, ffigen이 이 YAML을 입력으로 만들어내는 **최종 `generated_bindings_*.dart`가 byte-for-byte 동일**하면 검증 통과로 간주

재검증 지표:
- `diff -r lib/src/bindings/10.0/ <이전-백업>` → 모든 dart 파일 변경 없음
- `dart analyze lib/10.0/tizen.dart` → 에러·경고 수 변화 없음
- `example/integration_test` → 모든 테스트 통과

## 2. 스키마

모든 키는 snake_case. 선택적 키는 `?` 접미사로 표시.

### 2.1 Top-level

```yaml
version: "10.0"                               # 필수: Tizen 버전
llvm_path: /usr/lib/llvm-12                   # 필수
rootstrap_prefix: rootstraps/10.0             # 필수: '-I./<prefix>/...'에 쓰임
preamble_copyright_year: 2026                 # 필수: ffigen preamble 연도. 혼재 상태를 이 값으로 통일
symgen_copyright_year: 2026                   # 선택: symgen preamble 연도. 생략 시 preamble_copyright_year 사용

description_template?: "Dart bindings for Tizen {dashed} APIs."
# 기본 "Dart bindings for Tizen {dashed} APIs."
# {dashed}은 모듈명의 하이픈 형태 (capi_appfw_app_common → capi-appfw-app-common)

common_compiler_opts:                         # 모든 ffigen에 공통 (순서 유지)
  - "-m32"
  - "-Wno-incomplete-setjmp-declaration"

common_include_dirs:                          # rootstrap 아래의 include 경로
  tizen:                                      # 주석: "# include Tizen API directories"
    - usr/include/
    - usr/include/appcore-agent/
    # ... 약 40개
  efl:                                        # 주석: "# include EFL directories"
    - usr/include/ecore-imf-1/
    # ...
  glib:                                       # 주석: "# include glib directories"
    - usr/include/glib-2.0/
    - usr/lib/glib-2.0/include/

enum_rename_default:                          # 모든 모듈에 적용되는 기본 enum rename
  "_+(.*)": "$1"

entrypoints:                                  # entrypoints.h 섹션 구조
  - section: Account
    includes:
      - header: account.h
      - header: oauth2.h
      - header: old_api.h  # deprecated       # deprecated 표시는 YAML 주석으로 (생성물에는 미반영)
      # ...
  - section: Application Framework
    includes: [...]
  # ...

modules:                                      # 모듈 목록 (아래 2.2)
  - name: accounts_svc
    library: libaccounts-svc.so.0
    headers: [account.h]
  # ...
```

### 2.2 모듈 엔트리

```yaml
- name: <snake_case>                          # 필수. libfoo-bar-baz → foo_bar_baz 규칙을 직접 따름.
  library: <lib filename>                     # 필수 (no_library=true인 경우 제외). ex: libcapi-appfw-app-common.so.0
  headers: [account.h, ...]                   # 필수. include-directives에 '**/foo.h' 형식으로 펼쳐짐

  no_library?: false                          # 기본 false. true이면 symgen.yaml target-libraries에 안 들어감. time 전용.
  description?: <str>                         # override (기본 description_template 사용)
  preamble_year?: <int>                       # override (기본 top-level 값 사용)

  include_directives_override?: [...]         # include-directives를 완전히 직접 지정. openal 같은 glob 케이스.
                                              # 미지정 시 headers에서 '**/<header>' 자동 생성.

  extra_compiler_opts?: [-DAL_ALEXT_PROTOTYPES]

  # 다른 모듈의 타입을 재사용 (library-imports + type-map[pattern A] 자동 생성)
  imports?:
    - from: capi_appfw_app_control            # 대상 모듈명 (필수)
      as?: app_control                        # library-imports alias. 생략 시 from과 동일.
      typedefs?: [app_control_h]              # 재사용할 타입명 (key=c-type=dart-type)
      structs?: [...]
      unions?: [...]
      typedef_renames?:                       # 이름을 다른 이름으로 매핑 (recorder의 예외 케이스)
        recorder_video_data_s: camera_preview_data_s
      struct_renames?: {...}

  # dart:ffi 기본 타입으로 매핑 (time_t, pid_t 등)
  primitive_typedefs?:
    time_t:   {c: Long, d: int}
    __time_t: {c: Long, d: int}

  # enum rename 추가 규칙 (enum_rename_default에 merge)
  enum_renames?:
    vc_audio_channel_e: _vc_audio_channel_e

  # macros.exclude
  macro_excludes?: [ML_TIZEN_CAM_VIDEO_SRC]

  # 더미 entrypoint 생성 (콜백/핸들 강제 노출용)
  # 각 타입에 대해 void _force_generate_<type>(<type> x) {} 를 자동 생성
  force_types?: [app_event_handler_h, app_event_cb]

  # 더미 entrypoint에 extern 함수 선언 추가 (storage 전용)
  extern_decls?:
    - "int storage_get_internal_memory_size64(struct statvfs_size* buf)"
    - "int storage_get_external_memory_size64(struct statvfs_size* buf)"
```

## 3. 파생 규칙 (생성기 내부 로직)

| 파생 대상 | 규칙 |
|---|---|
| `class_name` | `Tizen<version_nodot><PascalCase(name)>` 예: `Tizen100CapiAppfwAppCommon` |
| `output path` | `../../lib/src/bindings/<version>/generated_bindings_<name>.dart` |
| `ffigen 파일명` | `configs/<version>/ffigen_<name>.yaml` |
| `include-directive` (header → pattern) | 헤더 경로에 `/`가 없으면 `**/<header>`, 있으면 `**/<header>` 그대로 |
| `dashed name` | `name`의 `_` → `-` 치환. description·name 필드용. |
| `library alias` (imports default) | `from` 필드와 동일 |

## 4. 스키마 커버리지 증명

Tizen 10.0의 129개 모듈과 모든 예외를 이 스키마가 수용할 수 있다:

| 사례 | 파일 수 | 스키마 필드 |
|---|---|---|
| 기본 (라이브러리 + 헤더 N개) | ~73 | `name, library, headers` |
| 다른 모듈 타입 재사용 | 56 | `imports[]` |
| dart:ffi 기본 타입 매핑 (time_t 등) | 6 | `primitive_typedefs` |
| 구조체/타입 재매핑 (예외) | 1 | `imports[].typedef_renames` |
| 더미 엔트리포인트 (force_types) | 1 | `force_types` |
| 더미 엔트리포인트 (extern_decls) | 1 | `extern_decls` |
| enum rename 추가 | 10 | `enum_renames` |
| macros.exclude | 2 | `macro_excludes` |
| compiler-opts 추가 | 1 (openal) | `extra_compiler_opts` |
| 라이브러리 없는 헤더-only (time) | 1 | `no_library: true` |
| include-directives 직접 지정 (openal glob) | 1 | `include_directives_override` |

## 5. 마이그레이션 플로우

1. **import_configs.py** — 현재 `configs/<v>/*.yaml` + `entrypoints.h`를 읽어 `modules.yaml`을 산출 (버전당 1회만 실행).
2. **build_configs.py** — `modules.yaml`을 읽어 `symgen.yaml` + `entrypoints.h` (+ `entrypoints_*.h` 더미) + `ffigen_*.yaml` 129개를 재생성.
3. 재생성물에 `generate_bindings.sh` → `generate_tizen.py` 순서 기존 그대로 실행해 dart 바인딩 생성.
4. 기존 `generated_bindings_*.dart`와 diff가 0인지 확인 (§1의 지표).

## 6. 추가 간소화 가능성 (초기 스코프 밖)

- `common_include_dirs`조차 `entrypoints.h`에서 자동 도출 가능 (rootstrap 디렉토리를 스캔해서 헤더별 `-I` 경로 추정). 초기 단계에서는 명시적으로 두고, 이후 단계에서 자동화.
- `entrypoints[]` 섹션 구조도 모듈 `headers`를 카테고리 태그와 함께 두면 자동 생성 가능 (`category: Application Framework` 같은 태그).
- `enum_rename_default`와 `enum_renames`를 자동 감지(ffigen이 중복 warning을 내면 자동 추가)할 수도 있으나 ffigen 업그레이드(트랙 C) 이후로 미룸.

## 7. 비목표 (이 단계에서 건드리지 않는 것)

- 생성된 `generated_bindings_*.dart` 파일의 내용 변경.
- `LookupProvider`, `lib/<v>/tizen.dart` 구조 변경 (Task 7에서 `generate_tizen.py`의 regex를 modules.yaml 인덱스로 교체하는 것만 예외).
- ffigen 버전 업그레이드.
- 바인딩 파일 수 축소·분할.
