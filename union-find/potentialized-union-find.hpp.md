---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebraic-structure/group.hpp
    title: algebraic-structure/group.hpp
  - icon: ':heavy_check_mark:'
    path: algebraic-structure/magma.hpp
    title: algebraic-structure/magma.hpp
  - icon: ':heavy_check_mark:'
    path: algebraic-structure/monoid.hpp
    title: algebraic-structure/monoid.hpp
  - icon: ':heavy_check_mark:'
    path: algebraic-structure/util.hpp
    title: algebraic-structure/util.hpp
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
    \ }\n  static T inv(T x) { return T(1) / x; }\n};\n#line 3 \"union-find/potentialized-union-find.hpp\"\
    \n\ntemplate <class G>\nREQUIRES(Group<G>)\nstruct PotentializedUnionFind {\n\
    \  using T = typename G::value_type;\n\n private:\n  vector<int> a;\n  vector<T>\
    \ p;\n\n public:\n  PotentializedUnionFind(int n) : a(n, -1), p(n, G::e()) {}\n\
    \  int find(int v) {\n    if (a[v] < 0) return v;\n    int r = find(a[v]);\n \
    \   p[v] = G::op(p[v], p[a[v]]);\n    return a[v] = r;\n  }\n  int size(int v)\
    \ { return -a[find(v)]; }\n  bool same(int u, int v) { return find(u) == find(v);\
    \ }\n  // p[u]-p[v]=w\n  bool unite(int u, int v, T w) {\n    int x = find(u),\
    \ y = find(v);\n    if (x == y) return p[u] == G::op(p[v], w);\n    w = G::op(G::op(w,\
    \ G::inv(p[u])), p[v]);\n    if (a[x] < a[y]) {\n      p[y] = G::op(p[x], G::inv(w));\n\
    \      a[x] += a[y];\n      a[y] = x;\n    } else {\n      p[x] = G::op(p[y],\
    \ w);\n      a[y] += a[x];\n      a[x] = y;\n    }\n    return true;\n  }\n  //\
    \ p[u]-p[v]\n  T diff(int u, int v) {\n    find(u);\n    find(v);\n    return\
    \ G::op(p[u], G::inv(p[v]));\n  }\n};\n/**\n * @brief \u30DD\u30C6\u30F3\u30B7\
    \u30E3\u30EB\u4ED8\u304D Union Find\n * @docs docs/union-find/potentialized-union-find.md\n\
    \ */\n"
  code: "#pragma once\n#include \"algebraic-structure/group.hpp\"\n\ntemplate <class\
    \ G>\nREQUIRES(Group<G>)\nstruct PotentializedUnionFind {\n  using T = typename\
    \ G::value_type;\n\n private:\n  vector<int> a;\n  vector<T> p;\n\n public:\n\
    \  PotentializedUnionFind(int n) : a(n, -1), p(n, G::e()) {}\n  int find(int v)\
    \ {\n    if (a[v] < 0) return v;\n    int r = find(a[v]);\n    p[v] = G::op(p[v],\
    \ p[a[v]]);\n    return a[v] = r;\n  }\n  int size(int v) { return -a[find(v)];\
    \ }\n  bool same(int u, int v) { return find(u) == find(v); }\n  // p[u]-p[v]=w\n\
    \  bool unite(int u, int v, T w) {\n    int x = find(u), y = find(v);\n    if\
    \ (x == y) return p[u] == G::op(p[v], w);\n    w = G::op(G::op(w, G::inv(p[u])),\
    \ p[v]);\n    if (a[x] < a[y]) {\n      p[y] = G::op(p[x], G::inv(w));\n     \
    \ a[x] += a[y];\n      a[y] = x;\n    } else {\n      p[x] = G::op(p[y], w);\n\
    \      a[y] += a[x];\n      a[x] = y;\n    }\n    return true;\n  }\n  // p[u]-p[v]\n\
    \  T diff(int u, int v) {\n    find(u);\n    find(v);\n    return G::op(p[u],\
    \ G::inv(p[v]));\n  }\n};\n/**\n * @brief \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\
    \u4ED8\u304D Union Find\n * @docs docs/union-find/potentialized-union-find.md\n\
    \ */\n"
  dependsOn:
  - algebraic-structure/group.hpp
  - algebraic-structure/monoid.hpp
  - algebraic-structure/magma.hpp
  - algebraic-structure/util.hpp
  isVerificationFile: false
  path: union-find/potentialized-union-find.hpp
  requiredBy: []
  timestamp: '2026-06-28 15:41:08+09:00'
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

`PotentializedUnionFind<G>` として使う．
`G` は `value_type`, `op(x,y)`, `e()`, `inv(x)` を持つ群を表す型．
加法の場合は `AddGroup<T>` を使えばよい．

- `find(v)`：頂点 $v$ を含む連結成分の代表頂点を返す．
- `size(v)`：頂点 $v$ を含む連結成分の頂点数を返す．
- `same(u, v)`：頂点 $u,v$ が同じ連結成分に含まれるかを返す．
- `unite(u, v, w)`：$p_u-p_v=w$ という情報を追加する．それまでの情報と矛盾しないかを返す．
- `diff(u, v)`：$p_u-p_v$ に対応する値を返す．

## アルゴリズム

Union Find の内部において $p_v$ から $v$ を含む連結成分の根の $p$ の値を減じたものを管理する．
