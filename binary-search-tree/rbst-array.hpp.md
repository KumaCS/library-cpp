---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: binary-search-tree/rbst-base.hpp
    title: "Randomized Binary Search Tree (\u57FA\u5E95\u30AF\u30E9\u30B9)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/binary-search-tree/UNIT_rbst_array.test.cpp
    title: verify/binary-search-tree/UNIT_rbst_array.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u633F\u5165/\u524A\u9664\u306E\u53EF\u80FD\u306A\u914D\u5217\
      \ (\u4E71\u629E\u4E8C\u5206\u63A2\u7D22\u6728)"
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
    \u5E95\u30AF\u30E9\u30B9)\n * @docs docs/binary-search-tree/rbst-base.md\n */\n\
    #line 3 \"binary-search-tree/rbst-array.hpp\"\n\ntemplate <typename T>\nstruct\
    \ RBSTArrayNode {\n  typename RBSTBase<RBSTArrayNode>::Ptr l, r;\n  T key;\n \
    \ int cnt;\n  RBSTArrayNode(const T& t = T()) : l(), r(), key(t), cnt(1) {}\n\
    };\n\ntemplate <class T>\nstruct RBSTArray : RBSTBase<RBSTArrayNode<T>> {\n  using\
    \ Node = RBSTArrayNode<T>;\n  using base = RBSTBase<Node>;\n  using base::merge;\n\
    \  using base::split;\n  using typename base::Ptr;\n\n  RBSTArray() = default;\n\
    \  T get(Ptr& t, int k) {\n    auto x = split(t, k);\n    auto y = split(x.second,\
    \ 1);\n    T v = y.first->key;\n    t = merge(x.first, merge(y.first, y.second));\n\
    \    return v;\n  }\n  void set(Ptr& t, int k, T v) {\n    auto x = split(t, k);\n\
    \    auto y = split(x.second, 1);\n    y.first->key = v;\n    t = merge(x.first,\
    \ merge(y.first, y.second));\n  }\n\n protected:\n  Ptr update(Ptr t) override\
    \ {\n    t->cnt = 1;\n    if (t->l) t->cnt += t->l->cnt;\n    if (t->r) t->cnt\
    \ += t->r->cnt;\n    return t;\n  }\n  void push(Ptr t) override {}\n};\n\n/**\n\
    \ * @brief \u633F\u5165/\u524A\u9664\u306E\u53EF\u80FD\u306A\u914D\u5217 (\u4E71\
    \u629E\u4E8C\u5206\u63A2\u7D22\u6728)\n */\n"
  code: "#pragma once\n#include \"binary-search-tree/rbst-base.hpp\"\n\ntemplate <typename\
    \ T>\nstruct RBSTArrayNode {\n  typename RBSTBase<RBSTArrayNode>::Ptr l, r;\n\
    \  T key;\n  int cnt;\n  RBSTArrayNode(const T& t = T()) : l(), r(), key(t), cnt(1)\
    \ {}\n};\n\ntemplate <class T>\nstruct RBSTArray : RBSTBase<RBSTArrayNode<T>>\
    \ {\n  using Node = RBSTArrayNode<T>;\n  using base = RBSTBase<Node>;\n  using\
    \ base::merge;\n  using base::split;\n  using typename base::Ptr;\n\n  RBSTArray()\
    \ = default;\n  T get(Ptr& t, int k) {\n    auto x = split(t, k);\n    auto y\
    \ = split(x.second, 1);\n    T v = y.first->key;\n    t = merge(x.first, merge(y.first,\
    \ y.second));\n    return v;\n  }\n  void set(Ptr& t, int k, T v) {\n    auto\
    \ x = split(t, k);\n    auto y = split(x.second, 1);\n    y.first->key = v;\n\
    \    t = merge(x.first, merge(y.first, y.second));\n  }\n\n protected:\n  Ptr\
    \ update(Ptr t) override {\n    t->cnt = 1;\n    if (t->l) t->cnt += t->l->cnt;\n\
    \    if (t->r) t->cnt += t->r->cnt;\n    return t;\n  }\n  void push(Ptr t) override\
    \ {}\n};\n\n/**\n * @brief \u633F\u5165/\u524A\u9664\u306E\u53EF\u80FD\u306A\u914D\
    \u5217 (\u4E71\u629E\u4E8C\u5206\u63A2\u7D22\u6728)\n */"
  dependsOn:
  - binary-search-tree/rbst-base.hpp
  isVerificationFile: false
  path: binary-search-tree/rbst-array.hpp
  requiredBy: []
  timestamp: '2025-11-13 15:25:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/binary-search-tree/UNIT_rbst_array.test.cpp
documentation_of: binary-search-tree/rbst-array.hpp
layout: document
redirect_from:
- /library/binary-search-tree/rbst-array.hpp
- /library/binary-search-tree/rbst-array.hpp.html
title: "\u633F\u5165/\u524A\u9664\u306E\u53EF\u80FD\u306A\u914D\u5217 (\u4E71\u629E\
  \u4E8C\u5206\u63A2\u7D22\u6728)"
---
