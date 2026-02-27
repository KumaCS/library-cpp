---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: tree/distance.hpp
    title: "\u6728\u4E0A\u306E\u8DDD\u96E2"
  - icon: ':warning:'
    path: tree/lca-auxiliary-tree.hpp
    title: "LCA \u30D9\u30FC\u30B9\u306E Auxiliary Tree"
  - icon: ':heavy_check_mark:'
    path: tree/lowest-common-ancestor.hpp
    title: Lowest Common Ancestor
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data-structure/LC_staticrmq.test.cpp
    title: verify/data-structure/LC_staticrmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/tree/LC_lowest_common_ancestor.test.cpp
    title: verify/tree/LC_lowest_common_ancestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/sparse-table.hpp\"\n\ntemplate <class T,\
    \ T (*op)(T, T)>\nstruct SparseTable {\n private:\n  int n;\n  vector<vector<T>>\
    \ st;\n\n public:\n  SparseTable() {}\n  SparseTable(const vector<T> &arr) {\n\
    \    n = arr.size();\n    int log = 1;\n    while (n >> log) log++;\n    st =\
    \ vector<vector<T>>(log);\n    st[0] = vector<T>(arr.begin(), arr.end());\n  \
    \  for (int k = 1; k < log; k++) {\n      auto stp = st[k - 1];\n      auto sti\
    \ = vector<T>(n - (1 << k) + 1);\n      for (int i = 0; i < sti.size(); i++)\n\
    \        sti[i] = op(stp[i], stp[i + (1 << (k - 1))]);\n      st[k] = sti;\n \
    \   }\n  }\n  T prod(int l, int r)  // [l,r)\n  {\n    assert(0 <= l && l < r\
    \ && r <= n);\n    int j = 0;\n    while ((2 << j) <= r - l) j++;\n    return\
    \ op(st[j][l], st[j][r - (1 << j)]);\n  }\n};\n"
  code: "#pragma once\n\ntemplate <class T, T (*op)(T, T)>\nstruct SparseTable {\n\
    \ private:\n  int n;\n  vector<vector<T>> st;\n\n public:\n  SparseTable() {}\n\
    \  SparseTable(const vector<T> &arr) {\n    n = arr.size();\n    int log = 1;\n\
    \    while (n >> log) log++;\n    st = vector<vector<T>>(log);\n    st[0] = vector<T>(arr.begin(),\
    \ arr.end());\n    for (int k = 1; k < log; k++) {\n      auto stp = st[k - 1];\n\
    \      auto sti = vector<T>(n - (1 << k) + 1);\n      for (int i = 0; i < sti.size();\
    \ i++)\n        sti[i] = op(stp[i], stp[i + (1 << (k - 1))]);\n      st[k] = sti;\n\
    \    }\n  }\n  T prod(int l, int r)  // [l,r)\n  {\n    assert(0 <= l && l < r\
    \ && r <= n);\n    int j = 0;\n    while ((2 << j) <= r - l) j++;\n    return\
    \ op(st[j][l], st[j][r - (1 << j)]);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/sparse-table.hpp
  requiredBy:
  - tree/lowest-common-ancestor.hpp
  - tree/distance.hpp
  - tree/lca-auxiliary-tree.hpp
  timestamp: '2026-02-28 01:08:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data-structure/LC_staticrmq.test.cpp
  - verify/tree/LC_lowest_common_ancestor.test.cpp
documentation_of: data-structure/sparse-table.hpp
layout: document
redirect_from:
- /library/data-structure/sparse-table.hpp
- /library/data-structure/sparse-table.hpp.html
title: data-structure/sparse-table.hpp
---
