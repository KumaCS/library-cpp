---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebraic-structure/util.hpp
    title: algebraic-structure/util.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algebraic-structure/group.hpp
    title: algebraic-structure/group.hpp
  - icon: ':heavy_check_mark:'
    path: algebraic-structure/monoid-action.hpp
    title: algebraic-structure/monoid-action.hpp
  - icon: ':heavy_check_mark:'
    path: algebraic-structure/monoid.hpp
    title: algebraic-structure/monoid.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/sparse-table.hpp
    title: data-structure/sparse-table.hpp
  - icon: ':warning:'
    path: data-structure/wavelet-matrix-with-segment-tree.hpp
    title: data-structure/wavelet-matrix-with-segment-tree.hpp
  - icon: ':heavy_check_mark:'
    path: math/floor-monoid-product.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u7248 Floor Sum"
  - icon: ':warning:'
    path: math/polynomial-floor-sum.hpp
    title: "\u591A\u9805\u5F0F\u7248 floor sum"
  - icon: ':heavy_check_mark:'
    path: segment-tree/dual-segment-tree.hpp
    title: Dual Segment Tree
  - icon: ':warning:'
    path: segment-tree/lazy-segment-tree-util.hpp
    title: "\u3088\u304F\u4F7F\u3046 Lazy Segment Tree"
  - icon: ':heavy_check_mark:'
    path: segment-tree/lazy-segment-tree.hpp
    title: Lazy Segment Tree
  - icon: ':warning:'
    path: segment-tree/persistent-segment-tree.hpp
    title: Persistent Segment Tree
  - icon: ':warning:'
    path: segment-tree/segment-tree-util.hpp
    title: "\u3088\u304F\u4F7F\u3046 Segment Tree"
  - icon: ':heavy_check_mark:'
    path: segment-tree/segment-tree.hpp
    title: Segment Tree
  - icon: ':warning:'
    path: tree/distance.hpp
    title: "\u6728\u4E0A\u306E\u8DDD\u96E2"
  - icon: ':warning:'
    path: tree/lca-auxiliary-tree.hpp
    title: "LCA \u30D9\u30FC\u30B9\u306E Auxiliary Tree"
  - icon: ':heavy_check_mark:'
    path: tree/lowest-common-ancestor.hpp
    title: Lowest Common Ancestor
  - icon: ':warning:'
    path: union-find/persistent-potentialized-union-find.hpp
    title: Persistent Potentialized Union Find
  - icon: ':heavy_check_mark:'
    path: union-find/potentialized-union-find.hpp
    title: "\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304D Union Find"
  - icon: ':warning:'
    path: verify/data-structure/LC_point_add_rectangle_sum.wavelet_matrix.cpp
    title: verify/data-structure/LC_point_add_rectangle_sum.wavelet_matrix.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data-structure/LC_staticrmq.test.cpp
    title: verify/data-structure/LC_staticrmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/math/LC_sum_of_floor_of_linear.monoid.test.cpp
    title: verify/math/LC_sum_of_floor_of_linear.monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/segment-tree/LC_point_add_range_sum.test.cpp
    title: verify/segment-tree/LC_point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/segment-tree/LC_point_set_range_composite.test.cpp
    title: verify/segment-tree/LC_point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/segment-tree/LC_range_affine_point_get.test.cpp
    title: verify/segment-tree/LC_range_affine_point_get.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/segment-tree/LC_range_affine_range_sum.test.cpp
    title: verify/segment-tree/LC_range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/tree/LC_lowest_common_ancestor.test.cpp
    title: verify/tree/LC_lowest_common_ancestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/union-find/LC_unionfind_with_potential.test.cpp
    title: verify/union-find/LC_unionfind_with_potential.test.cpp
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
    \ ? x : y; }\n};\n"
  code: "#pragma once\n#include \"algebraic-structure/util.hpp\"\n\n#ifdef __cpp_concepts\n\
    template <class M>\nconcept Magma = requires(typename M::value_type x, typename\
    \ M::value_type y) {\n  typename M::value_type;\n  { M::op(x, y) } -> same_as<typename\
    \ M::value_type>;\n};\n#endif\n\ntemplate <class T>\nstruct AddMagma {\n  using\
    \ value_type = T;\n  static T op(T x, T y) { return x + y; }\n};\ntemplate <class\
    \ T>\nstruct MulMagma {\n  using value_type = T;\n  static T op(T x, T y) { return\
    \ x * y; }\n};\ntemplate <class T, T id>\nstruct MaxMagma {\n  using value_type\
    \ = T;\n  static T op(T x, T y) { return x > y ? x : y; }\n};\ntemplate <class\
    \ T, T id>\nstruct MinMagma {\n  using value_type = T;\n  static T op(T x, T y)\
    \ { return x < y ? x : y; }\n};"
  dependsOn:
  - algebraic-structure/util.hpp
  isVerificationFile: false
  path: algebraic-structure/magma.hpp
  requiredBy:
  - algebraic-structure/monoid-action.hpp
  - algebraic-structure/monoid.hpp
  - algebraic-structure/group.hpp
  - verify/data-structure/LC_point_add_rectangle_sum.wavelet_matrix.cpp
  - segment-tree/lazy-segment-tree-util.hpp
  - segment-tree/segment-tree-util.hpp
  - segment-tree/lazy-segment-tree.hpp
  - segment-tree/segment-tree.hpp
  - segment-tree/dual-segment-tree.hpp
  - segment-tree/persistent-segment-tree.hpp
  - tree/lowest-common-ancestor.hpp
  - tree/distance.hpp
  - tree/lca-auxiliary-tree.hpp
  - union-find/persistent-potentialized-union-find.hpp
  - union-find/potentialized-union-find.hpp
  - math/floor-monoid-product.hpp
  - math/polynomial-floor-sum.hpp
  - data-structure/sparse-table.hpp
  - data-structure/wavelet-matrix-with-segment-tree.hpp
  timestamp: '2026-06-28 15:32:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/segment-tree/LC_range_affine_range_sum.test.cpp
  - verify/segment-tree/LC_point_set_range_composite.test.cpp
  - verify/segment-tree/LC_point_add_range_sum.test.cpp
  - verify/segment-tree/LC_range_affine_point_get.test.cpp
  - verify/tree/LC_lowest_common_ancestor.test.cpp
  - verify/union-find/LC_unionfind_with_potential.test.cpp
  - verify/math/LC_sum_of_floor_of_linear.monoid.test.cpp
  - verify/data-structure/LC_staticrmq.test.cpp
documentation_of: algebraic-structure/magma.hpp
layout: document
redirect_from:
- /library/algebraic-structure/magma.hpp
- /library/algebraic-structure/magma.hpp.html
title: algebraic-structure/magma.hpp
---
