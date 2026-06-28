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
  - icon: ':heavy_check_mark:'
    path: data-structure/persistent-array.hpp
    title: Persistent Array
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/union-find/persistent-potentialized-union-find.md
    document_title: Persistent Potentialized Union Find
    links: []
  bundledCode: "#line 2 \"union-find/persistent-potentialized-union-find.hpp\"\n\n\
    #line 2 \"data-structure/persistent-array.hpp\"\n\ntemplate <class T, int B =\
    \ 8>\nstruct PersistentArray {\n  struct Node {\n    T val;\n    Node* child[B]\
    \ = {};\n    Node() {}\n    Node(const T& v) : val(v) {}\n  };\n  Node* root;\n\
    \  vector<Node*> snapshots;\n  PersistentArray() : root(nullptr) {}\n  T get(Node*\
    \ t, int k) { return k == 0 ? t->val : get(t->child[k % B], k / B); }\n  T get(const\
    \ int& k) { return get(root, k); }\n  pair<Node*, T*> mutable_get(Node* t, int\
    \ k) {\n    t = t ? new Node(*t) : new Node();\n    if (k == 0) return {t, &t->val};\n\
    \    auto p = mutable_get(t->child[k % B], k / B);\n    t->child[k % B] = p.first;\n\
    \    return {t, p.second};\n  }\n  T* mutable_get(const int& k) {\n    auto ret\
    \ = mutable_get(root, k);\n    root = ret.first;\n    return ret.second;\n  }\n\
    \  Node* build(Node* t, const T& val, int k) {\n    if (!t) t = new Node();\n\
    \    if (k == 0) {\n      t->val = val;\n      return t;\n    }\n    t->child[k\
    \ % B] = build(t->child[k % B], val, k / B);\n    return t;\n  }\n  void build(const\
    \ vector<T>& v) {\n    root = nullptr;\n    for (int i = 0; i < v.size(); i++)\
    \ root = build(root, v[i], i);\n  }\n  int take_snapshot() {\n    snapshots.push_back(root);\n\
    \    return snapshots.size() - 1;\n  }\n  void apply_snapshot(int k) {\n    root\
    \ = snapshots[k];\n  }\n};\n\n/**\n * @brief Persistent Array\n * @docs docs/val-structure/persistent-array.md\n\
    \ */\n#line 2 \"algebraic-structure/util.hpp\"\n#ifdef __cpp_concepts\n#define\
    \ REQUIRES(...) requires __VA_ARGS__\n#else\n#define REQUIRES(...)\n#endif\n#line\
    \ 3 \"algebraic-structure/magma.hpp\"\n\n#ifdef __cpp_concepts\ntemplate <class\
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
    \ }\n  static T inv(T x) { return T(1) / x; }\n};\n#line 5 \"union-find/persistent-potentialized-union-find.hpp\"\
    \n\ntemplate <class G>\nREQUIRES(Group<G>)\nstruct PersistentPotentializedUnionFind\
    \ {\n  using T = typename G::value_type;\n\n private:\n  PersistentArray<int,\
    \ 8> a;\n  PersistentArray<T, 8> p;\n\n public:\n  PersistentPotentializedUnionFind(int\
    \ n) {\n    a.build(vector<int>(n, -1));\n    p.build(vector<T>(n, G::e()));\n\
    \  }\n  int find(int x) { return a.get(x) < 0 ? x : find(a.get(x)); }\n  T pot(int\
    \ x) {\n    int y = a.get(x);\n    return y < 0 ? p.get(x) : G::op(p.get(x), pot(y));\n\
    \  }\n  T diff(int x, int y) { return G::op(pot(x), G::inv(pot(y))); }\n  int\
    \ size(int x) { return -a.get(find(x)); }\n  bool same(int x, int y) { return\
    \ find(x) == find(y); }\n  // pot(u) - pot(v) = w\n  // return : consistent\n\
    \  bool unite(int u, int v, T w) {\n    int x = find(u), y = find(v);\n    if\
    \ (x == y) return diff(u, v) == w;\n    w = G::op(G::op(w, G::inv(pot(u))), pot(v));\n\
    \    auto ax = a.get(x);\n    auto ay = a.get(y);\n    if (ax < ay) {\n      *p.mutable_get(y)\
    \ = G::op(p.get(x), G::inv(w));\n      *a.mutable_get(x) += ay;\n      *a.mutable_get(y)\
    \ = x;\n    } else {\n      *p.mutable_get(x) = G::op(p.get(y), w);\n      *a.mutable_get(y)\
    \ += ax;\n      *a.mutable_get(x) = y;\n    }\n    return true;\n  }\n  int take_snapshot()\
    \ {\n    a.take_snapshot();\n    return p.take_snapshot();\n  }\n  void apply_snapshot(int\
    \ k) {\n    a.apply_snapshot(k);\n    p.apply_snapshot(k);\n  }\n};\n/**\n * @brief\
    \ Persistent Potentialized Union Find\n * @docs docs/union-find/persistent-potentialized-union-find.md\n\
    \ */\n"
  code: "#pragma once\n\n#include \"data-structure/persistent-array.hpp\"\n#include\
    \ \"algebraic-structure/group.hpp\"\n\ntemplate <class G>\nREQUIRES(Group<G>)\n\
    struct PersistentPotentializedUnionFind {\n  using T = typename G::value_type;\n\
    \n private:\n  PersistentArray<int, 8> a;\n  PersistentArray<T, 8> p;\n\n public:\n\
    \  PersistentPotentializedUnionFind(int n) {\n    a.build(vector<int>(n, -1));\n\
    \    p.build(vector<T>(n, G::e()));\n  }\n  int find(int x) { return a.get(x)\
    \ < 0 ? x : find(a.get(x)); }\n  T pot(int x) {\n    int y = a.get(x);\n    return\
    \ y < 0 ? p.get(x) : G::op(p.get(x), pot(y));\n  }\n  T diff(int x, int y) { return\
    \ G::op(pot(x), G::inv(pot(y))); }\n  int size(int x) { return -a.get(find(x));\
    \ }\n  bool same(int x, int y) { return find(x) == find(y); }\n  // pot(u) - pot(v)\
    \ = w\n  // return : consistent\n  bool unite(int u, int v, T w) {\n    int x\
    \ = find(u), y = find(v);\n    if (x == y) return diff(u, v) == w;\n    w = G::op(G::op(w,\
    \ G::inv(pot(u))), pot(v));\n    auto ax = a.get(x);\n    auto ay = a.get(y);\n\
    \    if (ax < ay) {\n      *p.mutable_get(y) = G::op(p.get(x), G::inv(w));\n \
    \     *a.mutable_get(x) += ay;\n      *a.mutable_get(y) = x;\n    } else {\n \
    \     *p.mutable_get(x) = G::op(p.get(y), w);\n      *a.mutable_get(y) += ax;\n\
    \      *a.mutable_get(x) = y;\n    }\n    return true;\n  }\n  int take_snapshot()\
    \ {\n    a.take_snapshot();\n    return p.take_snapshot();\n  }\n  void apply_snapshot(int\
    \ k) {\n    a.apply_snapshot(k);\n    p.apply_snapshot(k);\n  }\n};\n/**\n * @brief\
    \ Persistent Potentialized Union Find\n * @docs docs/union-find/persistent-potentialized-union-find.md\n\
    \ */\n"
  dependsOn:
  - data-structure/persistent-array.hpp
  - algebraic-structure/group.hpp
  - algebraic-structure/monoid.hpp
  - algebraic-structure/magma.hpp
  - algebraic-structure/util.hpp
  isVerificationFile: false
  path: union-find/persistent-potentialized-union-find.hpp
  requiredBy: []
  timestamp: '2026-06-28 15:41:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: union-find/persistent-potentialized-union-find.hpp
layout: document
redirect_from:
- /library/union-find/persistent-potentialized-union-find.hpp
- /library/union-find/persistent-potentialized-union-find.hpp.html
title: Persistent Potentialized Union Find
---
永続ポテンシャル付き Union Find．

通常の Union Find の連結性に加えて，各頂点 $v$ に値 $p_v$ があるとして差分の情報を管理する．
各状態を snapshot として保存し，あとから過去の状態に戻せる．

`PersistentPotentializedUnionFind<G>` として使う．
`G` は `value_type`, `op(x,y)`, `e()`, `inv(x)` を持つ群を表す型．
加法の場合は `AddGroup<T>` を使えばよい．

- `find(v)`：頂点 $v$ を含む連結成分の代表頂点を返す．
- `size(v)`：頂点 $v$ を含む連結成分の頂点数を返す．
- `same(u, v)`：頂点 $u,v$ が同じ連結成分に含まれるかを返す．
- `diff(u, v)`：$p_u-p_v$ に対応する値を返す．
- `unite(u, v, w)`：$p_u-p_v=w$ という制約を追加する．既存の情報と矛盾しないかを返す．
- `take_snapshot()`：現在の状態を保存し，その番号を返す．
- `apply_snapshot(k)`：保存した状態 `k` に戻す．

永続化には `PersistentArray` を用いているため，path compression は行わない．
各操作の時間計算量は木の高さと永続配列の更新に依存する．
