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
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/segment-tree/persistent-segment-tree.md
    document_title: Persistent Segment Tree
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
    \ }\n};\n#line 3 \"segment-tree/persistent-segment-tree.hpp\"\n\ntemplate <class\
    \ M, int MAX_NODES = 20000000>\nREQUIRES(Monoid<M>)\nstruct PersistentSegmentTree\
    \ {\n  using T = typename M::value_type;\n\n  struct Node {\n    Node *l, *r;\n\
    \    T v;\n  };\n\n private:\n  int n;\n  vector<Node> nodes;\n  vector<Node*>\
    \ roots;\n  Node* make_node(const T& v) {\n    nodes.push_back(Node{nullptr, nullptr,\
    \ v});\n    return &nodes.back();\n  }\n  Node* merge(Node* l, Node* r) {\n  \
    \  nodes.push_back(Node{l, r, M::op(l->v, r->v)});\n    return &nodes.back();\n\
    \  }\n  Node* build(int l, int r, const vector<T>& v) {\n    if (l + 1 == r) return\
    \ make_node(v[l]);\n    return merge(build(l, (l + r) / 2, v), build((l + r) /\
    \ 2, r, v));\n  }\n  Node* set(Node* x, int l, int r, int p, const T& v) {\n \
    \   if (l + 1 == r) return make_node(v);\n    int m = (l + r) / 2;\n    return\
    \ p < m ? merge(set(x->l, l, m, p, v), x->r) : merge(x->l, set(x->r, m, r, p,\
    \ v));\n  }\n  Node* apply(Node* x, int l, int r, int p, const T& v) {\n    if\
    \ (l + 1 == r) return make_node(M::op(x->v, v));\n    int m = (l + r) / 2;\n \
    \   return p < m ? merge(apply(x->l, l, m, p, v), x->r) : merge(x->l, apply(x->r,\
    \ m, r, p, v));\n  }\n  T prod(Node* x, int xl, int xr, int l, int r) {\n    if\
    \ (x == nullptr) return M::e();\n    if (r <= xl || xr <= l) return M::e();\n\
    \    if (l <= xl && xr <= r) return x->v;\n    int xm = (xl + xr) / 2;\n    return\
    \ M::op(prod(x->l, xl, xm, l, r), prod(x->r, xm, xr, l, r));\n  }\n\n public:\n\
    \  PersistentSegmentTree() : PersistentSegmentTree(1) {}\n  PersistentSegmentTree(int\
    \ sz) : PersistentSegmentTree(vector<T>(sz, M::e())) {}\n  PersistentSegmentTree(const\
    \ vector<T>& v) : n(v.size()) {\n    assert(n > 0);\n    roots.reserve(300000);\n\
    \    nodes.reserve(MAX_NODES);\n    roots.push_back(build(0, n, v));\n  }\n\n\
    \  int get_recent_time() { return (int)roots.size() - 1; }\n  Node* get_root(int\
    \ time = -1) {\n    if (time == -1) return roots.back();\n    return roots[time];\n\
    \  }\n\n  T get(Node* x, int p) {\n    assert(0 <= p && p < n);\n    int l = 0,\
    \ r = n;\n    while (r - l > 1) {\n      int m = (l + r) / 2;\n      if (p < m)\
    \ {\n        x = x->l;\n        r = m;\n      } else {\n        x = x->r;\n  \
    \      l = m;\n      }\n    }\n    return x->v;\n  }\n  T get(int time, int p)\
    \ { return get(roots[time], p); }\n  T get(int p) { return get(roots.back(), p);\
    \ }\n\n  Node* set(Node* x, int p, T v) {\n    assert(0 <= p && p < n);\n    roots.push_back(set(x,\
    \ 0, n, p, v));\n    return roots.back();\n  }\n  Node* set(int time, int p, T\
    \ v) { return set(roots[time], p, v); }\n  Node* set(int p, T v) { return set(roots.back(),\
    \ p, v); }\n\n  Node* apply(Node* x, int p, T v) {\n    assert(0 <= p && p < n);\n\
    \    roots.push_back(apply(x, 0, n, p, v));\n    return roots.back();\n  }\n \
    \ Node* apply(int time, int p, T v) { return apply(roots[time], p, v); }\n  Node*\
    \ apply(int p, T v) { return apply(roots.back(), p, v); }\n\n  T all_prod(Node*\
    \ x) { return x->v; }\n  T all_prod(int time) { return roots[time]->v; }\n  T\
    \ all_prod() { return roots.back()->v; }\n\n  T prod(Node* x, int l, int r) {\n\
    \    if (l >= r) return M::e();\n    assert(0 <= l && l <= r && r <= n);\n   \
    \ return prod(x, 0, n, l, r);\n  }\n  T prod(int time, int l, int r) { return\
    \ prod(roots[time], l, r); }\n  T prod(int l, int r) { return prod(roots.back(),\
    \ l, r); }\n};\n\n/**\n * @brief Persistent Segment Tree\n * @docs docs/segment-tree/persistent-segment-tree.md\n\
    \ */\n"
  code: "#pragma once\n#include \"algebraic-structure/monoid.hpp\"\n\ntemplate <class\
    \ M, int MAX_NODES = 20000000>\nREQUIRES(Monoid<M>)\nstruct PersistentSegmentTree\
    \ {\n  using T = typename M::value_type;\n\n  struct Node {\n    Node *l, *r;\n\
    \    T v;\n  };\n\n private:\n  int n;\n  vector<Node> nodes;\n  vector<Node*>\
    \ roots;\n  Node* make_node(const T& v) {\n    nodes.push_back(Node{nullptr, nullptr,\
    \ v});\n    return &nodes.back();\n  }\n  Node* merge(Node* l, Node* r) {\n  \
    \  nodes.push_back(Node{l, r, M::op(l->v, r->v)});\n    return &nodes.back();\n\
    \  }\n  Node* build(int l, int r, const vector<T>& v) {\n    if (l + 1 == r) return\
    \ make_node(v[l]);\n    return merge(build(l, (l + r) / 2, v), build((l + r) /\
    \ 2, r, v));\n  }\n  Node* set(Node* x, int l, int r, int p, const T& v) {\n \
    \   if (l + 1 == r) return make_node(v);\n    int m = (l + r) / 2;\n    return\
    \ p < m ? merge(set(x->l, l, m, p, v), x->r) : merge(x->l, set(x->r, m, r, p,\
    \ v));\n  }\n  Node* apply(Node* x, int l, int r, int p, const T& v) {\n    if\
    \ (l + 1 == r) return make_node(M::op(x->v, v));\n    int m = (l + r) / 2;\n \
    \   return p < m ? merge(apply(x->l, l, m, p, v), x->r) : merge(x->l, apply(x->r,\
    \ m, r, p, v));\n  }\n  T prod(Node* x, int xl, int xr, int l, int r) {\n    if\
    \ (x == nullptr) return M::e();\n    if (r <= xl || xr <= l) return M::e();\n\
    \    if (l <= xl && xr <= r) return x->v;\n    int xm = (xl + xr) / 2;\n    return\
    \ M::op(prod(x->l, xl, xm, l, r), prod(x->r, xm, xr, l, r));\n  }\n\n public:\n\
    \  PersistentSegmentTree() : PersistentSegmentTree(1) {}\n  PersistentSegmentTree(int\
    \ sz) : PersistentSegmentTree(vector<T>(sz, M::e())) {}\n  PersistentSegmentTree(const\
    \ vector<T>& v) : n(v.size()) {\n    assert(n > 0);\n    roots.reserve(300000);\n\
    \    nodes.reserve(MAX_NODES);\n    roots.push_back(build(0, n, v));\n  }\n\n\
    \  int get_recent_time() { return (int)roots.size() - 1; }\n  Node* get_root(int\
    \ time = -1) {\n    if (time == -1) return roots.back();\n    return roots[time];\n\
    \  }\n\n  T get(Node* x, int p) {\n    assert(0 <= p && p < n);\n    int l = 0,\
    \ r = n;\n    while (r - l > 1) {\n      int m = (l + r) / 2;\n      if (p < m)\
    \ {\n        x = x->l;\n        r = m;\n      } else {\n        x = x->r;\n  \
    \      l = m;\n      }\n    }\n    return x->v;\n  }\n  T get(int time, int p)\
    \ { return get(roots[time], p); }\n  T get(int p) { return get(roots.back(), p);\
    \ }\n\n  Node* set(Node* x, int p, T v) {\n    assert(0 <= p && p < n);\n    roots.push_back(set(x,\
    \ 0, n, p, v));\n    return roots.back();\n  }\n  Node* set(int time, int p, T\
    \ v) { return set(roots[time], p, v); }\n  Node* set(int p, T v) { return set(roots.back(),\
    \ p, v); }\n\n  Node* apply(Node* x, int p, T v) {\n    assert(0 <= p && p < n);\n\
    \    roots.push_back(apply(x, 0, n, p, v));\n    return roots.back();\n  }\n \
    \ Node* apply(int time, int p, T v) { return apply(roots[time], p, v); }\n  Node*\
    \ apply(int p, T v) { return apply(roots.back(), p, v); }\n\n  T all_prod(Node*\
    \ x) { return x->v; }\n  T all_prod(int time) { return roots[time]->v; }\n  T\
    \ all_prod() { return roots.back()->v; }\n\n  T prod(Node* x, int l, int r) {\n\
    \    if (l >= r) return M::e();\n    assert(0 <= l && l <= r && r <= n);\n   \
    \ return prod(x, 0, n, l, r);\n  }\n  T prod(int time, int l, int r) { return\
    \ prod(roots[time], l, r); }\n  T prod(int l, int r) { return prod(roots.back(),\
    \ l, r); }\n};\n\n/**\n * @brief Persistent Segment Tree\n * @docs docs/segment-tree/persistent-segment-tree.md\n\
    \ */\n"
  dependsOn:
  - algebraic-structure/monoid.hpp
  - algebraic-structure/magma.hpp
  - algebraic-structure/util.hpp
  isVerificationFile: false
  path: segment-tree/persistent-segment-tree.hpp
  requiredBy: []
  timestamp: '2026-06-28 15:41:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segment-tree/persistent-segment-tree.hpp
layout: document
redirect_from:
- /library/segment-tree/persistent-segment-tree.hpp
- /library/segment-tree/persistent-segment-tree.hpp.html
title: Persistent Segment Tree
---
# 永続セグメント木

https://info.atcoder.jp/entry/algorithm_lectures/persistent_segment_tree

完全永続的（fully persistent）なセグメント木

https://nyaannyaan.github.io/library/segment-tree/persistent-segment-tree.hpp.html

`PersistentSegmentTree<M>` として使う．
`M` は `value_type`, `op(x,y)`, `e()` を持つモノイドを表す型．

`set`, `apply`, `get`, `prod` それぞれ以下のように 3 パターンの方法で呼び出せる

- `set(p, v)` : 最新の木で位置 `p` の値を `v` に更新した新たな木の根へのポインタを返す
- `set(time, p, v)` : 時刻 `time` の木で位置 `p` の値を `v` に更新した新たな木の根へのポインタを返す
- `set(ptr, p, v)` : 根が `ptr` の木で位置 `p` の値を `v` に更新した新たな木の根へのポインタを返す
