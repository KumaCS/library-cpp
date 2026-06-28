---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: union-find/persistent-potentialized-union-find.hpp
    title: Persistent Potentialized Union Find
  - icon: ':heavy_check_mark:'
    path: union-find/persistent-union-find.hpp
    title: Persistent Union Find
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/union-find/LC_persistent_unionfind.test.cpp
    title: verify/union-find/LC_persistent_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/val-structure/persistent-array.md
    document_title: Persistent Array
    links: []
  bundledCode: "#line 2 \"data-structure/persistent-array.hpp\"\n\ntemplate <class\
    \ T, int B = 8>\nstruct PersistentArray {\n  struct Node {\n    T val;\n    Node*\
    \ child[B] = {};\n    Node() {}\n    Node(const T& v) : val(v) {}\n  };\n  Node*\
    \ root;\n  vector<Node*> snapshots;\n  PersistentArray() : root(nullptr) {}\n\
    \  T get(Node* t, int k) { return k == 0 ? t->val : get(t->child[k % B], k / B);\
    \ }\n  T get(const int& k) { return get(root, k); }\n  pair<Node*, T*> mutable_get(Node*\
    \ t, int k) {\n    t = t ? new Node(*t) : new Node();\n    if (k == 0) return\
    \ {t, &t->val};\n    auto p = mutable_get(t->child[k % B], k / B);\n    t->child[k\
    \ % B] = p.first;\n    return {t, p.second};\n  }\n  T* mutable_get(const int&\
    \ k) {\n    auto ret = mutable_get(root, k);\n    root = ret.first;\n    return\
    \ ret.second;\n  }\n  Node* build(Node* t, const T& val, int k) {\n    if (!t)\
    \ t = new Node();\n    if (k == 0) {\n      t->val = val;\n      return t;\n \
    \   }\n    t->child[k % B] = build(t->child[k % B], val, k / B);\n    return t;\n\
    \  }\n  void build(const vector<T>& v) {\n    root = nullptr;\n    for (int i\
    \ = 0; i < v.size(); i++) root = build(root, v[i], i);\n  }\n  int take_snapshot()\
    \ {\n    snapshots.push_back(root);\n    return snapshots.size() - 1;\n  }\n \
    \ void apply_snapshot(int k) {\n    root = snapshots[k];\n  }\n};\n\n/**\n * @brief\
    \ Persistent Array\n * @docs docs/val-structure/persistent-array.md\n */\n"
  code: "#pragma once\n\ntemplate <class T, int B = 8>\nstruct PersistentArray {\n\
    \  struct Node {\n    T val;\n    Node* child[B] = {};\n    Node() {}\n    Node(const\
    \ T& v) : val(v) {}\n  };\n  Node* root;\n  vector<Node*> snapshots;\n  PersistentArray()\
    \ : root(nullptr) {}\n  T get(Node* t, int k) { return k == 0 ? t->val : get(t->child[k\
    \ % B], k / B); }\n  T get(const int& k) { return get(root, k); }\n  pair<Node*,\
    \ T*> mutable_get(Node* t, int k) {\n    t = t ? new Node(*t) : new Node();\n\
    \    if (k == 0) return {t, &t->val};\n    auto p = mutable_get(t->child[k % B],\
    \ k / B);\n    t->child[k % B] = p.first;\n    return {t, p.second};\n  }\n  T*\
    \ mutable_get(const int& k) {\n    auto ret = mutable_get(root, k);\n    root\
    \ = ret.first;\n    return ret.second;\n  }\n  Node* build(Node* t, const T& val,\
    \ int k) {\n    if (!t) t = new Node();\n    if (k == 0) {\n      t->val = val;\n\
    \      return t;\n    }\n    t->child[k % B] = build(t->child[k % B], val, k /\
    \ B);\n    return t;\n  }\n  void build(const vector<T>& v) {\n    root = nullptr;\n\
    \    for (int i = 0; i < v.size(); i++) root = build(root, v[i], i);\n  }\n  int\
    \ take_snapshot() {\n    snapshots.push_back(root);\n    return snapshots.size()\
    \ - 1;\n  }\n  void apply_snapshot(int k) {\n    root = snapshots[k];\n  }\n};\n\
    \n/**\n * @brief Persistent Array\n * @docs docs/val-structure/persistent-array.md\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/persistent-array.hpp
  requiredBy:
  - union-find/persistent-union-find.hpp
  - union-find/persistent-potentialized-union-find.hpp
  timestamp: '2026-06-28 15:22:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/union-find/LC_persistent_unionfind.test.cpp
documentation_of: data-structure/persistent-array.hpp
layout: document
redirect_from:
- /library/data-structure/persistent-array.hpp
- /library/data-structure/persistent-array.hpp.html
title: Persistent Array
---
永続配列．

長さ $N$ の列 $A=(A_0,A_1,\dots,A_{N-1})$ を管理し，更新前の状態を保存して後から戻せるようにする．

- `build(v)`：列 `v` で初期化する．
- `get(k)`：$A_k$ を取得する．
- `mutable_get(k)`：$A_k$ へのポインタを取得する．必要な頂点だけコピーされるため，値を代入すると新しい状態が作られる．
- `take_snapshot()`：現在の状態を保存し，その番号を返す．
- `apply_snapshot(k)`：`take_snapshot` で保存した状態 `k` に戻す．

内部では添字を $B$ 進数で見た trie を永続化している．
各操作でコピーされる頂点数は $O(\log_B N)$ 個．
