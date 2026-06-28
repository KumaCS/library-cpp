---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebraic-structure/magma.hpp
    title: algebraic-structure/magma.hpp
  - icon: ':heavy_check_mark:'
    path: algebraic-structure/util.hpp
    title: algebraic-structure/util.hpp
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
  bundledCode: "#line 2 \"algebraic-structure/util.hpp\"\n#ifdef __cpp_concepts\n\
    #define REQUIRES(...) requires __VA_ARGS__\n#else\n#define REQUIRES(...)\n#endif\n\
    #line 3 \"algebraic-structure/magma.hpp\"\n\n#ifdef __cpp_concepts\ntemplate <class\
    \ M>\nconcept Magma = requires(typename M::value_type x, typename M::value_type\
    \ y) {\n  typename M::value_type;\n  { M::op(x, y) } -> same_as<typename M::value_type>;\n\
    };\n#endif\n\ntemplate <class T>\nstruct AddMagma {\n  using value_type = T;\n\
    \  static T op(T x, T y) { return x + y; }\n};\ntemplate <class T>\nstruct MulMagma\
    \ {\n  using value_type = T;\n  static T op(T x, T y) { return x * y; }\n};\n\
    template <class T, T id>\nstruct MaxMagma {\n  using value_type = T;\n  static\
    \ T op(T x, T y) { return x > y ? x : y; }\n};\ntemplate <class T, T id>\nstruct\
    \ MinMagma {\n  using value_type = T;\n  static T op(T x, T y) { return x < y\
    \ ? x : y; }\n};\n#line 3 \"data-structure/sparse-table.hpp\"\n\ntemplate <class\
    \ M>\nREQUIRES(Magma<M>)\nstruct SparseTable {\n  using T = typename M::value_type;\n\
    \n private:\n  int n;\n  vector<vector<T>> st;\n\n public:\n  SparseTable() {}\n\
    \  SparseTable(const vector<T> &arr) {\n    n = arr.size();\n    int log = 1;\n\
    \    while (n >> log) log++;\n    st = vector<vector<T>>(log);\n    st[0] = vector<T>(arr.begin(),\
    \ arr.end());\n    for (int k = 1; k < log; k++) {\n      auto stp = st[k - 1];\n\
    \      auto sti = vector<T>(n - (1 << k) + 1);\n      for (int i = 0; i < (int)sti.size();\
    \ i++)\n        sti[i] = M::op(stp[i], stp[i + (1 << (k - 1))]);\n      st[k]\
    \ = sti;\n    }\n  }\n  T prod(int l, int r)  // [l,r)\n  {\n    assert(0 <= l\
    \ && l < r && r <= n);\n    int j = 0;\n    while ((2 << j) <= r - l) j++;\n \
    \   return M::op(st[j][l], st[j][r - (1 << j)]);\n  }\n};\n"
  code: "#pragma once\n#include \"algebraic-structure/magma.hpp\"\n\ntemplate <class\
    \ M>\nREQUIRES(Magma<M>)\nstruct SparseTable {\n  using T = typename M::value_type;\n\
    \n private:\n  int n;\n  vector<vector<T>> st;\n\n public:\n  SparseTable() {}\n\
    \  SparseTable(const vector<T> &arr) {\n    n = arr.size();\n    int log = 1;\n\
    \    while (n >> log) log++;\n    st = vector<vector<T>>(log);\n    st[0] = vector<T>(arr.begin(),\
    \ arr.end());\n    for (int k = 1; k < log; k++) {\n      auto stp = st[k - 1];\n\
    \      auto sti = vector<T>(n - (1 << k) + 1);\n      for (int i = 0; i < (int)sti.size();\
    \ i++)\n        sti[i] = M::op(stp[i], stp[i + (1 << (k - 1))]);\n      st[k]\
    \ = sti;\n    }\n  }\n  T prod(int l, int r)  // [l,r)\n  {\n    assert(0 <= l\
    \ && l < r && r <= n);\n    int j = 0;\n    while ((2 << j) <= r - l) j++;\n \
    \   return M::op(st[j][l], st[j][r - (1 << j)]);\n  }\n};\n"
  dependsOn:
  - algebraic-structure/magma.hpp
  - algebraic-structure/util.hpp
  isVerificationFile: false
  path: data-structure/sparse-table.hpp
  requiredBy:
  - tree/lowest-common-ancestor.hpp
  - tree/distance.hpp
  - tree/lca-auxiliary-tree.hpp
  timestamp: '2026-06-28 15:41:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/tree/LC_lowest_common_ancestor.test.cpp
  - verify/data-structure/LC_staticrmq.test.cpp
documentation_of: data-structure/sparse-table.hpp
layout: document
redirect_from:
- /library/data-structure/sparse-table.hpp
- /library/data-structure/sparse-table.hpp.html
title: data-structure/sparse-table.hpp
---
