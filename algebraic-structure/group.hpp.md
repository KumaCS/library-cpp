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
    path: union-find/persistent-potentialized-union-find.hpp
    title: Persistent Potentialized Union Find
  - icon: ':heavy_check_mark:'
    path: union-find/potentialized-union-find.hpp
    title: "\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304D Union Find"
  _extendedVerifiedWith:
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
    \ }\n};\n#line 3 \"algebraic-structure/group.hpp\"\n\n#ifdef __cpp_concepts\n\
    template <class G>\nconcept Group = Monoid<G> && requires(typename G::value_type\
    \ x) {\n  { G::inv(x) } -> same_as<typename G::value_type>;\n};\n#endif\n\ntemplate\
    \ <class T>\nstruct AddGroup {\n  using value_type = T;\n  static T op(T x, T\
    \ y) { return x + y; }\n  static T e() { return T(0); }\n  static T inv(T x) {\
    \ return -x; }\n};\ntemplate <class T>\nstruct MulGroup {\n  using value_type\
    \ = T;\n  static T op(T x, T y) { return x * y; }\n  static T e() { return T(1);\
    \ }\n  static T inv(T x) { return T(1) / x; }\n};\n"
  code: "#pragma once\n#include \"algebraic-structure/monoid.hpp\"\n\n#ifdef __cpp_concepts\n\
    template <class G>\nconcept Group = Monoid<G> && requires(typename G::value_type\
    \ x) {\n  { G::inv(x) } -> same_as<typename G::value_type>;\n};\n#endif\n\ntemplate\
    \ <class T>\nstruct AddGroup {\n  using value_type = T;\n  static T op(T x, T\
    \ y) { return x + y; }\n  static T e() { return T(0); }\n  static T inv(T x) {\
    \ return -x; }\n};\ntemplate <class T>\nstruct MulGroup {\n  using value_type\
    \ = T;\n  static T op(T x, T y) { return x * y; }\n  static T e() { return T(1);\
    \ }\n  static T inv(T x) { return T(1) / x; }\n};\n"
  dependsOn:
  - algebraic-structure/monoid.hpp
  - algebraic-structure/magma.hpp
  - algebraic-structure/util.hpp
  isVerificationFile: false
  path: algebraic-structure/group.hpp
  requiredBy:
  - union-find/persistent-potentialized-union-find.hpp
  - union-find/potentialized-union-find.hpp
  timestamp: '2026-06-28 15:32:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/union-find/LC_unionfind_with_potential.test.cpp
documentation_of: algebraic-structure/group.hpp
layout: document
redirect_from:
- /library/algebraic-structure/group.hpp
- /library/algebraic-structure/group.hpp.html
title: algebraic-structure/group.hpp
---
