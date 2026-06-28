---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/persistent-array.hpp
    title: Persistent Array
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/union-find/LC_persistent_unionfind.test.cpp
    title: verify/union-find/LC_persistent_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/union-find/persistent-union-find.md
    document_title: Persistent Union Find
    links: []
  bundledCode: "#line 2 \"union-find/persistent-union-find.hpp\"\n\n#line 2 \"data-structure/persistent-array.hpp\"\
    \n\ntemplate <class T, int B = 8>\nstruct PersistentArray {\n  struct Node {\n\
    \    T val;\n    Node* child[B] = {};\n    Node() {}\n    Node(const T& v) : val(v)\
    \ {}\n  };\n  Node* root;\n  vector<Node*> snapshots;\n  PersistentArray() : root(nullptr)\
    \ {}\n  T get(Node* t, int k) { return k == 0 ? t->val : get(t->child[k % B],\
    \ k / B); }\n  T get(const int& k) { return get(root, k); }\n  pair<Node*, T*>\
    \ mutable_get(Node* t, int k) {\n    t = t ? new Node(*t) : new Node();\n    if\
    \ (k == 0) return {t, &t->val};\n    auto p = mutable_get(t->child[k % B], k /\
    \ B);\n    t->child[k % B] = p.first;\n    return {t, p.second};\n  }\n  T* mutable_get(const\
    \ int& k) {\n    auto ret = mutable_get(root, k);\n    root = ret.first;\n   \
    \ return ret.second;\n  }\n  Node* build(Node* t, const T& val, int k) {\n   \
    \ if (!t) t = new Node();\n    if (k == 0) {\n      t->val = val;\n      return\
    \ t;\n    }\n    t->child[k % B] = build(t->child[k % B], val, k / B);\n    return\
    \ t;\n  }\n  void build(const vector<T>& v) {\n    root = nullptr;\n    for (int\
    \ i = 0; i < v.size(); i++) root = build(root, v[i], i);\n  }\n  int take_snapshot()\
    \ {\n    snapshots.push_back(root);\n    return snapshots.size() - 1;\n  }\n \
    \ void apply_snapshot(int k) {\n    root = snapshots[k];\n  }\n};\n\n/**\n * @brief\
    \ Persistent Array\n * @docs docs/val-structure/persistent-array.md\n */\n#line\
    \ 4 \"union-find/persistent-union-find.hpp\"\n\nstruct PersistentUnionFind {\n\
    \ private:\n  PersistentArray<int, 8> a;\n\n public:\n  PersistentUnionFind(int\
    \ n) { a.build(vector<int>(n, -1)); }\n  int find(int x) { return a.get(x) < 0\
    \ ? x : find(a.get(x)); }\n  int size(int x) { return -a.get(find(x)); }\n  bool\
    \ same(int x, int y) { return find(x) == find(y); }\n  bool unite(int x, int y)\
    \ {\n    x = find(x), y = find(y);\n    if (x == y) return false;\n    if (a.get(x)\
    \ > a.get(y)) swap(x, y);\n    *a.mutable_get(x) += a.get(y);\n    *a.mutable_get(y)\
    \ = x;\n    return true;\n  }\n  int take_snapshot() { return a.take_snapshot();\
    \ }\n  void apply_snapshot(int k) { a.apply_snapshot(k); }\n};\n/**\n * @brief\
    \ Persistent Union Find\n * @docs docs/union-find/persistent-union-find.md\n */\n"
  code: "#pragma once\n\n#include \"data-structure/persistent-array.hpp\"\n\nstruct\
    \ PersistentUnionFind {\n private:\n  PersistentArray<int, 8> a;\n\n public:\n\
    \  PersistentUnionFind(int n) { a.build(vector<int>(n, -1)); }\n  int find(int\
    \ x) { return a.get(x) < 0 ? x : find(a.get(x)); }\n  int size(int x) { return\
    \ -a.get(find(x)); }\n  bool same(int x, int y) { return find(x) == find(y); }\n\
    \  bool unite(int x, int y) {\n    x = find(x), y = find(y);\n    if (x == y)\
    \ return false;\n    if (a.get(x) > a.get(y)) swap(x, y);\n    *a.mutable_get(x)\
    \ += a.get(y);\n    *a.mutable_get(y) = x;\n    return true;\n  }\n  int take_snapshot()\
    \ { return a.take_snapshot(); }\n  void apply_snapshot(int k) { a.apply_snapshot(k);\
    \ }\n};\n/**\n * @brief Persistent Union Find\n * @docs docs/union-find/persistent-union-find.md\n\
    \ */"
  dependsOn:
  - data-structure/persistent-array.hpp
  isVerificationFile: false
  path: union-find/persistent-union-find.hpp
  requiredBy: []
  timestamp: '2026-06-28 15:41:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/union-find/LC_persistent_unionfind.test.cpp
documentation_of: union-find/persistent-union-find.hpp
layout: document
redirect_from:
- /library/union-find/persistent-union-find.hpp
- /library/union-find/persistent-union-find.hpp.html
title: Persistent Union Find
---
永続 Union Find．

$n$ 頂点 $0$ 辺のグラフに対して連結性を管理し，各状態を snapshot として保存できる．
過去の状態に戻してから更新することで，永続的な Union Find として使える．

- `find(v)`：頂点 $v$ を含む連結成分の代表頂点を返す．
- `size(v)`：頂点 $v$ を含む連結成分の頂点数を返す．
- `same(u, v)`：頂点 $u,v$ が同じ連結成分に含まれるかを返す．
- `unite(u, v)`：辺 $uv$ を追加する．すでに同じ連結成分なら `false`，そうでなければ `true` を返す．
- `take_snapshot()`：現在の状態を保存し，その番号を返す．
- `apply_snapshot(k)`：`take_snapshot` で保存した状態 `k` に戻す．

永続化には `PersistentArray` を用いているため，path compression は行わない．
union by size により根付き木の高さを抑える．
