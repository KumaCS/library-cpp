---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/union-find/LC_unionfind_with_potential.test.cpp
    title: verify/union-find/LC_unionfind_with_potential.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/union-find/potentialized-union-find.md
    document_title: "\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304D Union Find"
    links: []
  bundledCode: "#line 2 \"union-find/potentialized-union-find.hpp\"\n\ntemplate <class\
    \ T>\nstruct PotentializedUnionFind {\n private:\n  vector<int> a;\n  vector<T>\
    \ p;\n\n public:\n  PotentializedUnionFind(int n) : a(n, -1), p(n, 0) {}\n  int\
    \ find(int v) {\n    if (a[v] < 0) return v;\n    int r = find(a[v]);\n    p[v]\
    \ += p[a[v]];\n    return a[v] = r;\n  }\n  int size(int v) { return -a[find(v)];\
    \ }\n  bool same(int u, int v) { return find(u) == find(v); }\n  // p[u]-p[v]=w\n\
    \  bool unite(int u, int v, T w) {\n    int x = find(u), y = find(v);\n    if\
    \ (x == y) return p[u] - p[v] == w;\n    w -= p[u], w += p[v];\n    if (a[x] <\
    \ a[y]) {\n      p[y] = p[x] - w;\n      a[x] += a[y];\n      a[y] = x;\n    }\
    \ else {\n      p[x] = p[y] + w;\n      a[y] += a[x];\n      a[x] = y;\n    }\n\
    \    return true;\n  }\n  // p[u]-p[v]\n  T diff(int u, int v) { return p[u] -\
    \ p[v]; }\n};\n/**\n * @brief \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304D\
    \ Union Find\n * @docs docs/union-find/potentialized-union-find.md\n */\n"
  code: "#pragma once\n\ntemplate <class T>\nstruct PotentializedUnionFind {\n private:\n\
    \  vector<int> a;\n  vector<T> p;\n\n public:\n  PotentializedUnionFind(int n)\
    \ : a(n, -1), p(n, 0) {}\n  int find(int v) {\n    if (a[v] < 0) return v;\n \
    \   int r = find(a[v]);\n    p[v] += p[a[v]];\n    return a[v] = r;\n  }\n  int\
    \ size(int v) { return -a[find(v)]; }\n  bool same(int u, int v) { return find(u)\
    \ == find(v); }\n  // p[u]-p[v]=w\n  bool unite(int u, int v, T w) {\n    int\
    \ x = find(u), y = find(v);\n    if (x == y) return p[u] - p[v] == w;\n    w -=\
    \ p[u], w += p[v];\n    if (a[x] < a[y]) {\n      p[y] = p[x] - w;\n      a[x]\
    \ += a[y];\n      a[y] = x;\n    } else {\n      p[x] = p[y] + w;\n      a[y]\
    \ += a[x];\n      a[x] = y;\n    }\n    return true;\n  }\n  // p[u]-p[v]\n  T\
    \ diff(int u, int v) { return p[u] - p[v]; }\n};\n/**\n * @brief \u30DD\u30C6\u30F3\
    \u30B7\u30E3\u30EB\u4ED8\u304D Union Find\n * @docs docs/union-find/potentialized-union-find.md\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: union-find/potentialized-union-find.hpp
  requiredBy: []
  timestamp: '2025-10-24 10:50:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/union-find/LC_unionfind_with_potential.test.cpp
documentation_of: union-find/potentialized-union-find.hpp
layout: document
redirect_from:
- /library/union-find/potentialized-union-find.hpp
- /library/union-find/potentialized-union-find.hpp.html
title: "\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304D Union Find"
---
通常の Union Find のほかに列 $(p_0,p_1,\dots,p_{n-1})$ に関する情報を管理する．

- `unite(u, v, w)`：$p_u-p_v=w$ という情報が与えられる．それまでに与えられた valid な情報と矛盾しないとき valid な情報と呼ぶことにする．与えられた情報が valid な情報か否かを返す．
- `diff(u, v)`：$p_u-p_v$ の値が valid な情報から一意に定まる場合その値を，定まらない場合はその旨を報告する．

## アルゴリズム

Union Find の内部において $p_v$ から $v$ を含む連結成分の根の $p$ の値を減じたものを管理する．