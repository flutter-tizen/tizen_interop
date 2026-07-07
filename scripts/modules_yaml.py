#!/usr/bin/env python3
# Shared I/O layer for configs/<version>/modules.yaml.
#
# Provides an ordered, trailing-comment-preserving load/dump cycle that
# reproduces the committed files byte-for-byte, plus small naming helpers
# shared by update_modules.py and resolve_type_dups.py.

from __future__ import annotations

import os
import re
from collections import OrderedDict

import yaml

ROOT = os.path.dirname(os.path.dirname(os.path.realpath(__file__)))

# Trailing comment on a value line, e.g. "  - header: mv_face.h  # deprecated".
# Conservative: requires whitespace before '#' and no quote characters in the
# line (the entire measured corpus is plain "- header: x.h  # word" shapes).
_COMMENT_RE = re.compile(r'^(?P<key>.*\S)\s+(?P<comment>#.*)$')


class OrderedLoader(yaml.SafeLoader):
    pass


def _ordered_construct_mapping(loader, node):
    loader.flatten_mapping(node)
    return OrderedDict(loader.construct_pairs(node))


OrderedLoader.add_constructor(
    yaml.resolver.BaseResolver.DEFAULT_MAPPING_TAG, _ordered_construct_mapping
)


def _ordered_dict_representer(dumper, data):
    return dumper.represent_mapping('tag:yaml.org,2002:map', data.items())


yaml.add_representer(OrderedDict, _ordered_dict_representer)


def _split_comment(line: str):
    """Return (line_without_comment, comment) or (line, None)."""
    if '#' not in line:
        return line, None
    if '"' in line or "'" in line:
        # No quoted scalar in the corpus carries a trailing comment; refuse to
        # guess rather than mis-split.
        return line, None
    m = _COMMENT_RE.match(line)
    if not m:
        return line, None
    return m.group('key'), m.group('comment')


def load(path: str):
    """Load modules.yaml preserving key order and trailing comments.

    Returns (cfg, comments) where comments is an ordered list of
    (line_without_comment, comment) pairs, consumed in order by dump().
    """
    with open(path) as f:
        text = f.read()
    comments = []
    for line in text.splitlines():
        key, comment = _split_comment(line)
        if comment is not None:
            comments.append((key, comment))
    cfg = yaml.load(text, Loader=OrderedLoader)
    return cfg, comments


def dumps(cfg, comments=None) -> str:
    """Dump cfg in the canonical style, re-injecting trailing comments."""
    out = yaml.dump(cfg, sort_keys=False, default_flow_style=False,
                    allow_unicode=True, width=200)
    if not comments:
        return out
    pending = list(comments)
    lines = out.splitlines()
    for i, line in enumerate(lines):
        for j, (key, comment) in enumerate(pending):
            if line == key:
                lines[i] = f'{line}  {comment}'
                pending.pop(j)
                break
    if pending:
        lost = ', '.join(f'{c!r} on {k!r}' for k, c in pending[:5])
        raise ValueError(
            f'{len(pending)} trailing comment(s) could not be re-attached '
            f'(their anchor lines no longer exist): {lost}')
    return '\n'.join(lines) + '\n'


def dump(cfg, comments, path: str):
    text = dumps(cfg, comments)
    with open(path, 'w') as f:
        f.write(text)


def roundtrip_check(path: str) -> bool:
    """True if load()+dumps() reproduces the file byte-for-byte."""
    with open(path) as f:
        original = f.read()
    cfg, comments = load(path)
    return dumps(cfg, comments) == original


# -- naming helpers -----------------------------------------------------------

def lib_to_module_name(libname: str) -> str:
    """libcapi-appfw-app-common.so.0 -> capi_appfw_app_common"""
    name = libname
    if name.startswith('lib'):
        name = name[3:]
    name = re.sub(r'(\.so)(\.[0-9]+)*$', '', name)
    return name.replace('-', '_')


def soname_of(base: str, files: list[str]) -> str:
    """Pick the soname to record in modules.yaml for a library.

    base is the unversioned name ('libfoo.so'); files are all matching
    filenames in the rootstrap. Committed entries use the runtime soname:
    the highest major version, in its shortest form ('libfoo.so.1' over
    'libfoo.so.1.3.3', but 'libfoo.so.0.1' when no single-major file
    exists). Falls back to base when only the unversioned symlink exists.
    """
    versioned = []
    for f in files:
        m = re.fullmatch(re.escape(base) + r'((?:\.\d+)+)', f)
        if m:
            parts = tuple(int(p) for p in m.group(1)[1:].split('.'))
            versioned.append((parts, f))
    if not versioned:
        return base
    top_major = max(v[0][0] for v in versioned)
    in_major = [v for v in versioned if v[0][0] == top_major]
    # shortest version tuple wins (the actual soname); tie-break on value
    in_major.sort(key=lambda v: (len(v[0]), v[0]))
    return in_major[0][1]


