---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebraic-structure/magma.hpp
    title: algebraic-structure/magma.hpp
  - icon: ':heavy_check_mark:'
    path: algebraic-structure/monoid.hpp
    title: algebraic-structure/monoid.hpp
  - icon: ':heavy_check_mark:'
    path: algebraic-structure/util.hpp
    title: algebraic-structure/util.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: segment-tree/lazy-segment-tree-util.hpp
    title: "\u3088\u304F\u4F7F\u3046 Lazy Segment Tree"
  - icon: ':heavy_check_mark:'
    path: segment-tree/lazy-segment-tree.hpp
    title: Lazy Segment Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/segment-tree/LC_range_affine_range_sum.test.cpp
    title: verify/segment-tree/LC_range_affine_range_sum.test.cpp
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
    \ ? x : y; }\n};\n#line 3 \"algebraic-structure/monoid.hpp\"\n\n#ifdef __cpp_concepts\n\
    template <class M>\nconcept Monoid = Magma<M> && requires {\n  { M::e() } -> same_as<typename\
    \ M::value_type>;\n};\n#endif\n\ntemplate <class T>\nstruct AddMonoid {\n  using\
    \ value_type = T;\n  static T op(T x, T y) { return x + y; }\n  static T e() {\
    \ return T(0); }\n};\ntemplate <class T>\nstruct MulMonoid {\n  using value_type\
    \ = T;\n  static T op(T x, T y) { return x * y; }\n  static T e() { return T(1);\
    \ }\n};\ntemplate <class T, T id>\nstruct MaxMonoid {\n  using value_type = T;\n\
    \  static T op(T x, T y) { return x > y ? x : y; }\n  static T e() { return id;\
    \ }\n};\ntemplate <class T, T id>\nstruct MinMonoid {\n  using value_type = T;\n\
    \  static T op(T x, T y) { return x < y ? x : y; }\n  static T e() { return id;\
    \ }\n};\n#line 3 \"algebraic-structure/monoid-action.hpp\"\n\n#ifdef __cpp_concepts\n\
    template <class A>\nconcept MonoidAction = Monoid<typename A::value_monoid> &&\
    \ Monoid<typename A::operator_monoid> && requires(typename A::value_monoid::value_type\
    \ x, typename A::operator_monoid::value_type f) {\n  typename A::value_monoid;\n\
    \  typename A::operator_monoid;\n  { A::mapping(f, x) } -> same_as<typename A::value_monoid::value_type>;\n\
    };\n#endif\n"
  code: "#pragma once\n#include \"algebraic-structure/monoid.hpp\"\n\n#ifdef __cpp_concepts\n\
    template <class A>\nconcept MonoidAction = Monoid<typename A::value_monoid> &&\
    \ Monoid<typename A::operator_monoid> && requires(typename A::value_monoid::value_type\
    \ x, typename A::operator_monoid::value_type f) {\n  typename A::value_monoid;\n\
    \  typename A::operator_monoid;\n  { A::mapping(f, x) } -> same_as<typename A::value_monoid::value_type>;\n\
    };\n#endif\n"
  dependsOn:
  - algebraic-structure/monoid.hpp
  - algebraic-structure/magma.hpp
  - algebraic-structure/util.hpp
  isVerificationFile: false
  path: algebraic-structure/monoid-action.hpp
  requiredBy:
  - segment-tree/lazy-segment-tree-util.hpp
  - segment-tree/lazy-segment-tree.hpp
  timestamp: '2026-06-28 15:32:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/segment-tree/LC_range_affine_range_sum.test.cpp
documentation_of: algebraic-structure/monoid-action.hpp
layout: document
redirect_from:
- /library/algebraic-structure/monoid-action.hpp
- /library/algebraic-structure/monoid-action.hpp.html
title: algebraic-structure/monoid-action.hpp
---
