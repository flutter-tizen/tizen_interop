#!/usr/bin/env python3
# Rootstrap scanner used by resolve_type_dups.py to decide type ownership.
#
# Scans rootstraps/<version>/usr for shared libraries, headers, and pkg-config
# files, and answers the two questions the duplicate-type resolver needs: does
# one pkg-config Require another, and does one header transitively #include
# another (include-graph reachability).

from __future__ import annotations

import os
import re
from collections import deque

ROOT = os.path.dirname(os.path.dirname(os.path.realpath(__file__)))

_LIB_RE = re.compile(r'^(lib[^/]+?\.so)((?:\.\d+)*)$')
_INCLUDE_RE = re.compile(r'^\s*#\s*include\s*[<"]([^>"]+)[>"]', re.MULTILINE)
_VAR_RE = re.compile(r'\$\{(\w+)\}')


class PcInfo:
    def __init__(self, name):
        self.name = name
        self.libs = []          # bare -l names, e.g. 'capi-appfw-application'
        self.requires = []      # pc names from Requires:


def _parse_pc(path: str, name: str) -> PcInfo:
    pc = PcInfo(name)
    variables = {}
    fields = {}
    with open(path, errors='replace') as f:
        for line in f:
            line = line.split('#', 1)[0].strip()
            if not line:
                continue
            if ':' in line and re.match(r'^[A-Za-z][\w.]*\s*:', line):
                k, v = line.split(':', 1)
                fields[k.strip()] = v.strip()
            elif '=' in line:
                k, v = line.split('=', 1)
                variables[k.strip()] = v.strip()

    def expand(s: str, depth=0) -> str:
        if depth > 5:
            return s
        return _VAR_RE.sub(
            lambda m: expand(variables.get(m.group(1), ''), depth + 1), s)

    for tok in expand(fields.get('Libs', '')).split():
        if tok.startswith('-l'):
            pc.libs.append(tok[2:])
    for tok in re.split(r'[,\s]+', expand(fields.get('Requires', ''))):
        # skip version constraints like '>=' '1.0'
        if tok and not re.match(r'^[<>=!]|^\d', tok):
            pc.requires.append(tok)
    return pc


class RootstrapIndex:
    def __init__(self, version: str):
        self.version = version
        self.lib_files: dict[str, list[str]] = {}   # 'libfoo.so' -> all filenames
        self.headers: set[str] = set()              # paths relative to usr/include
        self.pcs: dict[str, PcInfo] = {}
        self.pc_by_lib: dict[str, str] = {}         # 'libfoo.so' -> pc name
        self._rootstrap_dir: str | None = None      # set by scan(); enables include graph
        self._include_cache: dict[str, list[str]] = {}

    # -- construction ---------------------------------------------------------

    @classmethod
    def scan(cls, version: str, rootstrap_dir: str) -> 'RootstrapIndex':
        idx = cls(version)
        idx._rootstrap_dir = rootstrap_dir
        libdir = os.path.join(rootstrap_dir, 'usr', 'lib')
        incdir = os.path.join(rootstrap_dir, 'usr', 'include')
        pcdir = os.path.join(libdir, 'pkgconfig')

        for fn in sorted(os.listdir(libdir)) if os.path.isdir(libdir) else []:
            m = _LIB_RE.match(fn)
            if m:
                idx.lib_files.setdefault(m.group(1), []).append(fn)

        for dirpath, _dirnames, filenames in os.walk(incdir):
            rel = os.path.relpath(dirpath, incdir)
            for fn in filenames:
                if fn.endswith('.h'):
                    idx.headers.add(fn if rel == '.' else f'{rel}/{fn}')

        if os.path.isdir(pcdir):
            for fn in sorted(os.listdir(pcdir)):
                if not fn.endswith('.pc'):
                    continue
                name = fn[:-3]
                idx.pcs[name] = _parse_pc(os.path.join(pcdir, fn), name)

        for name, pc in idx.pcs.items():
            for l in pc.libs:
                base = f'lib{l}.so'
                if base in idx.lib_files:
                    idx.pc_by_lib.setdefault(base, name)
        return idx

    # -- ownership queries -----------------------------------------------------

    def pc_requires_transitively(self, a: str, b: str, depth: int = 2) -> bool:
        """True if pc `a` requires pc `b` within `depth` hops."""
        seen = {a}
        frontier = [a]
        for _ in range(depth):
            nxt = []
            for n in frontier:
                pc = self.pcs.get(n)
                for r in (pc.requires if pc else []):
                    if r == b:
                        return True
                    if r not in seen:
                        seen.add(r)
                        nxt.append(r)
            frontier = nxt
        return False

    def _includes_of(self, header: str) -> list[str]:
        """Resolved header paths included by `header` (cached)."""
        if header in self._include_cache:
            return self._include_cache[header]
        result = []
        if self._rootstrap_dir:
            path = os.path.join(self._rootstrap_dir, 'usr', 'include', header)
            try:
                with open(path, errors='replace') as f:
                    text = f.read()
            except OSError:
                text = ''
            for ref in _INCLUDE_RE.findall(text):
                if ref in self.headers:
                    result.append(ref)
                else:
                    # resolve relative to the including header's directory
                    rel = os.path.normpath(os.path.join(os.path.dirname(header), ref))
                    if rel in self.headers:
                        result.append(rel)
                    else:
                        suffix = '/' + ref
                        hits = [h for h in self.headers if h.endswith(suffix)]
                        if len(hits) == 1:
                            result.append(hits[0])
        self._include_cache[header] = result
        return result

    def _resolve(self, ref: str) -> list[str]:
        if ref in self.headers:
            return [ref]
        suffix = '/' + ref
        return [h for h in self.headers if h.endswith(suffix)]

    def include_graph_reaches(self, hdrs_a, hdrs_b, max_depth: int = 6) -> bool:
        """True if any header in hdrs_a transitively #includes one of hdrs_b.

        Requires a scanned rootstrap directory (not available from a manifest).
        """
        if not self._rootstrap_dir:
            return False
        targets = set()
        for ref in hdrs_b:
            targets.update(self._resolve(ref))
        if not targets:
            return False
        start = []
        for ref in hdrs_a:
            start.extend(self._resolve(ref))
        seen = set(start)
        queue = deque((h, 0) for h in start)
        while queue:
            h, d = queue.popleft()
            if d >= max_depth:
                continue
            for inc in self._includes_of(h):
                if inc in targets:
                    return True
                if inc not in seen:
                    seen.add(inc)
                    queue.append((inc, d + 1))
        return False
