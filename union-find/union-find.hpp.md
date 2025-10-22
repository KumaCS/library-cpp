---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/union-find/LC_unionfind.test.cpp
    title: verify/union-find/LC_unionfind.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/union-find/union-find.md
    document_title: Union Find
    links: []
  bundledCode: "#line 2 \"union-find/union-find.hpp\"\n\nstruct UnionFind {\n private:\n\
    \  vector<int> a;\n\n public:\n  UnionFind(int n) : a(n, -1) {}\n  int find(int\
    \ x) { return a[x] < 0 ? x : a[x] = find(a[x]); }\n  int size(int x) { return\
    \ -a[find(x)]; }\n  bool same(int x, int y) { return find(x) == find(y); }\n \
    \ bool unite(int x, int y) {\n    x = find(x), y = find(y);\n    if (x == y) return\
    \ false;\n    if (a[x] > a[y]) swap(x, y);\n    a[x] += a[y];\n    a[y] = x;\n\
    \    return true;\n  }\n  template <class F>\n  bool unite(int x, int y, F f)\
    \ {\n    x = find(x), y = find(y);\n    if (x == y) return false;\n    if (a[x]\
    \ > a[y]) swap(x, y);\n    a[x] += a[y];\n    a[y] = x;\n    f(x, y);\n    return\
    \ true;\n  }\n  vector<vector<int>> groups() {\n    vector<int> root(a.size()),\
    \ gsize(a.size());\n    for (int i = 0; i < a.size(); i++) gsize[root[i] = find(i)]++;\n\
    \    vector<vector<int>> res(a.size());\n    for (int i = 0; i < res.size(); i++)\
    \ res[i].reserve(gsize[i]);\n    for (int i = 0; i < root.size(); i++) res[root[i]].push_back(i);\n\
    \    res.erase(remove_if(res.begin(), res.end(), [&](const vector<int>& v) { return\
    \ v.empty(); }), res.end());\n    return res;\n  }\n};\n/**\n * @brief Union Find\n\
    \ * @docs docs/union-find/union-find.md\n */\n"
  code: "#pragma once\n\nstruct UnionFind {\n private:\n  vector<int> a;\n\n public:\n\
    \  UnionFind(int n) : a(n, -1) {}\n  int find(int x) { return a[x] < 0 ? x : a[x]\
    \ = find(a[x]); }\n  int size(int x) { return -a[find(x)]; }\n  bool same(int\
    \ x, int y) { return find(x) == find(y); }\n  bool unite(int x, int y) {\n   \
    \ x = find(x), y = find(y);\n    if (x == y) return false;\n    if (a[x] > a[y])\
    \ swap(x, y);\n    a[x] += a[y];\n    a[y] = x;\n    return true;\n  }\n  template\
    \ <class F>\n  bool unite(int x, int y, F f) {\n    x = find(x), y = find(y);\n\
    \    if (x == y) return false;\n    if (a[x] > a[y]) swap(x, y);\n    a[x] +=\
    \ a[y];\n    a[y] = x;\n    f(x, y);\n    return true;\n  }\n  vector<vector<int>>\
    \ groups() {\n    vector<int> root(a.size()), gsize(a.size());\n    for (int i\
    \ = 0; i < a.size(); i++) gsize[root[i] = find(i)]++;\n    vector<vector<int>>\
    \ res(a.size());\n    for (int i = 0; i < res.size(); i++) res[i].reserve(gsize[i]);\n\
    \    for (int i = 0; i < root.size(); i++) res[root[i]].push_back(i);\n    res.erase(remove_if(res.begin(),\
    \ res.end(), [&](const vector<int>& v) { return v.empty(); }), res.end());\n \
    \   return res;\n  }\n};\n/**\n * @brief Union Find\n * @docs docs/union-find/union-find.md\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: union-find/union-find.hpp
  requiredBy: []
  timestamp: '2025-10-23 01:57:19+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/union-find/LC_unionfind.test.cpp
documentation_of: union-find/union-find.hpp
layout: document
redirect_from:
- /library/union-find/union-find.hpp
- /library/union-find/union-find.hpp.html
title: Union Find
---
