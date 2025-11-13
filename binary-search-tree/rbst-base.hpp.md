---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: binary-search-tree/rbst-array.hpp
    title: "\u633F\u5165/\u524A\u9664\u306E\u53EF\u80FD\u306A\u914D\u5217 (\u4E71\u629E\
      \u4E8C\u5206\u63A2\u7D22\u6728)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/binary-search-tree/UNIT_rbst_array.test.cpp
    title: verify/binary-search-tree/UNIT_rbst_array.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/binary-search-tree/rbst-base.md
    document_title: "Randomized Binary Search Tree (\u57FA\u5E95\u30AF\u30E9\u30B9\
      )"
    links: []
  bundledCode: "#line 2 \"binary-search-tree/rbst-base.hpp\"\n\ntemplate <class Node>\n\
    struct RBSTBase {\n  using Ptr = Node*;\n  template <typename... Args>\n  inline\
    \ Ptr my_new(Args... args) {\n    return new Node(args...);\n  }\n  inline void\
    \ my_del(Ptr t) { delete t; }\n  inline Ptr make_tree() const { return nullptr;\
    \ }\n\n  int size(Ptr t) const { return count(t); }\n  Ptr merge(Ptr l, Ptr r)\
    \ {\n    if (!l || !r) return l ? l : r;\n    if (int((rng() * (l->cnt + r->cnt))\
    \ >> 32) < l->cnt) {\n      push(l);\n      l->r = merge(l->r, r);\n      return\
    \ update(l);\n    } else {\n      push(r);\n      r->l = merge(l, r->l);\n   \
    \   return update(r);\n    }\n  }\n  pair<Ptr, Ptr> split(Ptr t, int k) {\n  \
    \  if (!t) return {nullptr, nullptr};\n    push(t);\n    if (k <= count(t->l))\
    \ {\n      auto s = split(t->l, k);\n      t->l = s.second;\n      return {s.first,\
    \ update(t)};\n    } else {\n      auto s = split(t->r, k - count(t->l) - 1);\n\
    \      t->r = s.first;\n      return {update(t), s.second};\n    }\n  }\n  Ptr\
    \ build(int l, int r, const vector<decltype(Node::key)>& v) {\n    if (l + 1 ==\
    \ r) return my_new(v[l]);\n    int m = (l + r) >> 1;\n    Ptr pm = my_new(v[m]);\n\
    \    if (l < m) pm->l = build(l, m, v);\n    if (m + 1 < r) pm->r = build(m +\
    \ 1, r, v);\n    return update(pm);\n  }\n  Ptr build(const vector<decltype(Node::key)>&\
    \ v) {\n    return build(0, (int)v.size(), v);\n  }\n  template <typename... Args>\n\
    \  void insert(Ptr& t, int k, const Args&... args) {\n    auto x = split(t, k);\n\
    \    t = merge(merge(x.first, my_new(args...)), x.second);\n  }\n  void erase(Ptr&\
    \ t, int k) {\n    auto x = split(t, k);\n    auto y = split(x.second, 1);\n \
    \   my_del(y.first);\n    t = merge(x.first, y.second);\n  }\n\n protected:\n\
    \  static uint64_t rng() {\n    static uint64_t x_ = 123456789ull;\n    return\
    \ x_ ^= x_ << 7, x_ ^= x_ >> 9, x_ & 0xFFFFFFFFull;\n  }\n  inline int count(const\
    \ Ptr t) const { return t ? t->cnt : 0; }\n  virtual void push(Ptr) = 0;\n  virtual\
    \ Ptr update(Ptr) = 0;\n};\n\n/**\n * @brief Randomized Binary Search Tree (\u57FA\
    \u5E95\u30AF\u30E9\u30B9)\n * @docs docs/binary-search-tree/rbst-base.md\n */\n"
  code: "#pragma once\n\ntemplate <class Node>\nstruct RBSTBase {\n  using Ptr = Node*;\n\
    \  template <typename... Args>\n  inline Ptr my_new(Args... args) {\n    return\
    \ new Node(args...);\n  }\n  inline void my_del(Ptr t) { delete t; }\n  inline\
    \ Ptr make_tree() const { return nullptr; }\n\n  int size(Ptr t) const { return\
    \ count(t); }\n  Ptr merge(Ptr l, Ptr r) {\n    if (!l || !r) return l ? l : r;\n\
    \    if (int((rng() * (l->cnt + r->cnt)) >> 32) < l->cnt) {\n      push(l);\n\
    \      l->r = merge(l->r, r);\n      return update(l);\n    } else {\n      push(r);\n\
    \      r->l = merge(l, r->l);\n      return update(r);\n    }\n  }\n  pair<Ptr,\
    \ Ptr> split(Ptr t, int k) {\n    if (!t) return {nullptr, nullptr};\n    push(t);\n\
    \    if (k <= count(t->l)) {\n      auto s = split(t->l, k);\n      t->l = s.second;\n\
    \      return {s.first, update(t)};\n    } else {\n      auto s = split(t->r,\
    \ k - count(t->l) - 1);\n      t->r = s.first;\n      return {update(t), s.second};\n\
    \    }\n  }\n  Ptr build(int l, int r, const vector<decltype(Node::key)>& v) {\n\
    \    if (l + 1 == r) return my_new(v[l]);\n    int m = (l + r) >> 1;\n    Ptr\
    \ pm = my_new(v[m]);\n    if (l < m) pm->l = build(l, m, v);\n    if (m + 1 <\
    \ r) pm->r = build(m + 1, r, v);\n    return update(pm);\n  }\n  Ptr build(const\
    \ vector<decltype(Node::key)>& v) {\n    return build(0, (int)v.size(), v);\n\
    \  }\n  template <typename... Args>\n  void insert(Ptr& t, int k, const Args&...\
    \ args) {\n    auto x = split(t, k);\n    t = merge(merge(x.first, my_new(args...)),\
    \ x.second);\n  }\n  void erase(Ptr& t, int k) {\n    auto x = split(t, k);\n\
    \    auto y = split(x.second, 1);\n    my_del(y.first);\n    t = merge(x.first,\
    \ y.second);\n  }\n\n protected:\n  static uint64_t rng() {\n    static uint64_t\
    \ x_ = 123456789ull;\n    return x_ ^= x_ << 7, x_ ^= x_ >> 9, x_ & 0xFFFFFFFFull;\n\
    \  }\n  inline int count(const Ptr t) const { return t ? t->cnt : 0; }\n  virtual\
    \ void push(Ptr) = 0;\n  virtual Ptr update(Ptr) = 0;\n};\n\n/**\n * @brief Randomized\
    \ Binary Search Tree (\u57FA\u5E95\u30AF\u30E9\u30B9)\n * @docs docs/binary-search-tree/rbst-base.md\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: binary-search-tree/rbst-base.hpp
  requiredBy:
  - binary-search-tree/rbst-array.hpp
  timestamp: '2025-11-13 15:25:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/binary-search-tree/UNIT_rbst_array.test.cpp
documentation_of: binary-search-tree/rbst-base.hpp
layout: document
redirect_from:
- /library/binary-search-tree/rbst-base.hpp
- /library/binary-search-tree/rbst-base.hpp.html
title: "Randomized Binary Search Tree (\u57FA\u5E95\u30AF\u30E9\u30B9)"
---
乱択二分探索木

実装は [https://nyaannyaan.github.io/library/rbst/rbst-base.hpp] を参考

split / merge を基にした実装．
