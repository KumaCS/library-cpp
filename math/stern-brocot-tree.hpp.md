---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/math/LC_stern_brocot_tree.test.cpp
    title: verify/math/LC_stern_brocot_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/stern-brocot-tree.md
    document_title: Stern-Brocot Tree
    links: []
  bundledCode: "#line 2 \"math/stern-brocot-tree.hpp\"\n\ntemplate <class T>\nstruct\
    \ SternBrocotTreeNode {\n  using Node = SternBrocotTreeNode;\n  T la, lb, a, b,\
    \ ra, rb;\n  vector<T> seq;\n  SternBrocotTreeNode() : la(0), lb(1), a(1), b(1),\
    \ ra(1), rb(0) {}\n  SternBrocotTreeNode(T x, T y) : SternBrocotTreeNode() {\n\
    \    assert(x > 0 && y > 0);\n    T g = gcd(x, y);\n    x /= g, y /= g;\n    bool\
    \ is_right = true;\n    while (x > 0 && y > 0) {\n      T d = x / y;\n      x\
    \ -= d * y;\n      if (is_right)\n        go_right(d - (x == 0 ? 1 : 0));\n  \
    \    else\n        go_left(d - (x == 0 ? 1 : 0));\n      swap(x, y);\n      is_right\
    \ = !is_right;\n    }\n  }\n  SternBrocotTreeNode(pair<T, T> p) : SternBrocotTreeNode(p.first,\
    \ p.second) {}\n  SternBrocotTreeNode(const vector<T> seq_) {\n    for (auto&\
    \ v : seq_) {\n      assert(v != 0);\n      if (v > 0)\n        go_right(v);\n\
    \      else\n        go_left(v);\n    }\n    assert(seq == seq_);\n  }\n  pair<T,\
    \ T> get() const { return {a, b}; }\n  pair<T, T> lower_bound() const { return\
    \ {la, lb}; }\n  pair<T, T> upper_bound() const { return {ra, rb}; }\n\n  void\
    \ go_left(const T d = 1) {\n    if (d <= 0) return;\n    if (seq.empty() || seq.back()\
    \ > 0) seq.push_back(0);\n    seq.back() -= d;\n    ra += la * d, rb += lb * d;\n\
    \    a = la + ra, b = lb + rb;\n  }\n  void go_right(const T d = 1) {\n    if\
    \ (d <= 0) return;\n    if (seq.empty() || seq.back() < 0) seq.push_back(0);\n\
    \    seq.back() += d;\n    la += ra * d, lb += rb * d;\n    a = la + ra, b = lb\
    \ + rb;\n  }\n  T depth() const {\n    T d = 0;\n    for (auto& v : seq) d +=\
    \ abs(v);\n    return d;\n  }\n  static Node lca(const Node& x, const Node& y)\
    \ {\n    Node res;\n    for (int i = 0; i < min(x.seq.size(), y.seq.size()); i++)\
    \ {\n      T d1 = x.seq[i], d2 = y.seq[i];\n      if ((d1 > 0) != (d2 > 0)) break;\n\
    \      if (d1 > 0)\n        res.go_right(min(d1, d2));\n      else\n        res.go_left(min(-d1,\
    \ -d2));\n      if (d1 != d2) break;\n    }\n    return res;\n  }\n  bool go_parent(T\
    \ d = 1) {\n    if (d <= 0) return true;\n    while (d > 0) {\n      if (seq.empty())\
    \ return false;\n      T d1 = min(d, abs(seq.back()));\n      if (seq.back() >\
    \ 0) {\n        la -= ra * d1, lb -= rb * d1;\n        seq.back() -= d1;\n   \
    \   } else {\n        ra -= la * d1, rb -= lb * d1;\n        seq.back() += d1;\n\
    \      }\n      a = la + ra, b = lb + rb;\n      if (seq.back() <= 0) seq.pop_back();\n\
    \      d -= d1;\n    }\n    return true;\n  }\n  template <class F>\n  static\
    \ Node binary_search(T n, F f) {\n    assert(0 <= n);\n    Node m;\n    if (n\
    \ == 0) return {m.lower_bound(), m.upper_bound()};\n    auto over = [&](bool return_value)\
    \ {\n      auto [p, q] = m.get();\n      return max(m.a, m.b) > n || f(p, q) ==\
    \ return_value;\n    };\n    if (f(0, 1)) return {m.lower_bound(), m.lower_bound()};\n\
    \    for (int go_left = over(true); true; go_left ^= 1) {\n      if (go_left)\
    \ {\n        T a = 1;\n        for (; true; a *= 2) {\n          m.go_left(a);\n\
    \          if (over(false)) {\n            m.go_parent(a);\n            break;\n\
    \          }\n        }\n        for (a /= 2; a != 0; a /= 2) {\n          m.go_left(a);\n\
    \          if (over(false)) m.go_parent(a);\n        }\n        m.go_left(1);\n\
    \        if (max(m.get().first, m.get().second) > n)\n          return {m.lower_bound(),\
    \ m.upper_bound()};\n      } else {\n        T a = 1;\n        for (; true; a\
    \ *= 2) {\n          m.go_right(a);\n          if (over(true)) {\n           \
    \ m.go_parent(a);\n            break;\n          }\n        }\n        for (a\
    \ /= 2; a != 0; a /= 2) {\n          m.go_right(a);\n          if (over(true))\
    \ m.go_parent(a);\n        }\n        m.go_right(1);\n        if (max(m.get().first,\
    \ m.get().second) > n)\n          return {m.lower_bound(), m.upper_bound()};\n\
    \      }\n    }\n  }\n};\n\n/**\n * @brief Stern-Brocot Tree\n * @docs docs/math/stern-brocot-tree.md\n\
    \ */\n"
  code: "#pragma once\n\ntemplate <class T>\nstruct SternBrocotTreeNode {\n  using\
    \ Node = SternBrocotTreeNode;\n  T la, lb, a, b, ra, rb;\n  vector<T> seq;\n \
    \ SternBrocotTreeNode() : la(0), lb(1), a(1), b(1), ra(1), rb(0) {}\n  SternBrocotTreeNode(T\
    \ x, T y) : SternBrocotTreeNode() {\n    assert(x > 0 && y > 0);\n    T g = gcd(x,\
    \ y);\n    x /= g, y /= g;\n    bool is_right = true;\n    while (x > 0 && y >\
    \ 0) {\n      T d = x / y;\n      x -= d * y;\n      if (is_right)\n        go_right(d\
    \ - (x == 0 ? 1 : 0));\n      else\n        go_left(d - (x == 0 ? 1 : 0));\n \
    \     swap(x, y);\n      is_right = !is_right;\n    }\n  }\n  SternBrocotTreeNode(pair<T,\
    \ T> p) : SternBrocotTreeNode(p.first, p.second) {}\n  SternBrocotTreeNode(const\
    \ vector<T> seq_) {\n    for (auto& v : seq_) {\n      assert(v != 0);\n     \
    \ if (v > 0)\n        go_right(v);\n      else\n        go_left(v);\n    }\n \
    \   assert(seq == seq_);\n  }\n  pair<T, T> get() const { return {a, b}; }\n \
    \ pair<T, T> lower_bound() const { return {la, lb}; }\n  pair<T, T> upper_bound()\
    \ const { return {ra, rb}; }\n\n  void go_left(const T d = 1) {\n    if (d <=\
    \ 0) return;\n    if (seq.empty() || seq.back() > 0) seq.push_back(0);\n    seq.back()\
    \ -= d;\n    ra += la * d, rb += lb * d;\n    a = la + ra, b = lb + rb;\n  }\n\
    \  void go_right(const T d = 1) {\n    if (d <= 0) return;\n    if (seq.empty()\
    \ || seq.back() < 0) seq.push_back(0);\n    seq.back() += d;\n    la += ra * d,\
    \ lb += rb * d;\n    a = la + ra, b = lb + rb;\n  }\n  T depth() const {\n   \
    \ T d = 0;\n    for (auto& v : seq) d += abs(v);\n    return d;\n  }\n  static\
    \ Node lca(const Node& x, const Node& y) {\n    Node res;\n    for (int i = 0;\
    \ i < min(x.seq.size(), y.seq.size()); i++) {\n      T d1 = x.seq[i], d2 = y.seq[i];\n\
    \      if ((d1 > 0) != (d2 > 0)) break;\n      if (d1 > 0)\n        res.go_right(min(d1,\
    \ d2));\n      else\n        res.go_left(min(-d1, -d2));\n      if (d1 != d2)\
    \ break;\n    }\n    return res;\n  }\n  bool go_parent(T d = 1) {\n    if (d\
    \ <= 0) return true;\n    while (d > 0) {\n      if (seq.empty()) return false;\n\
    \      T d1 = min(d, abs(seq.back()));\n      if (seq.back() > 0) {\n        la\
    \ -= ra * d1, lb -= rb * d1;\n        seq.back() -= d1;\n      } else {\n    \
    \    ra -= la * d1, rb -= lb * d1;\n        seq.back() += d1;\n      }\n     \
    \ a = la + ra, b = lb + rb;\n      if (seq.back() <= 0) seq.pop_back();\n    \
    \  d -= d1;\n    }\n    return true;\n  }\n  template <class F>\n  static Node\
    \ binary_search(T n, F f) {\n    assert(0 <= n);\n    Node m;\n    if (n == 0)\
    \ return {m.lower_bound(), m.upper_bound()};\n    auto over = [&](bool return_value)\
    \ {\n      auto [p, q] = m.get();\n      return max(m.a, m.b) > n || f(p, q) ==\
    \ return_value;\n    };\n    if (f(0, 1)) return {m.lower_bound(), m.lower_bound()};\n\
    \    for (int go_left = over(true); true; go_left ^= 1) {\n      if (go_left)\
    \ {\n        T a = 1;\n        for (; true; a *= 2) {\n          m.go_left(a);\n\
    \          if (over(false)) {\n            m.go_parent(a);\n            break;\n\
    \          }\n        }\n        for (a /= 2; a != 0; a /= 2) {\n          m.go_left(a);\n\
    \          if (over(false)) m.go_parent(a);\n        }\n        m.go_left(1);\n\
    \        if (max(m.get().first, m.get().second) > n)\n          return {m.lower_bound(),\
    \ m.upper_bound()};\n      } else {\n        T a = 1;\n        for (; true; a\
    \ *= 2) {\n          m.go_right(a);\n          if (over(true)) {\n           \
    \ m.go_parent(a);\n            break;\n          }\n        }\n        for (a\
    \ /= 2; a != 0; a /= 2) {\n          m.go_right(a);\n          if (over(true))\
    \ m.go_parent(a);\n        }\n        m.go_right(1);\n        if (max(m.get().first,\
    \ m.get().second) > n)\n          return {m.lower_bound(), m.upper_bound()};\n\
    \      }\n    }\n  }\n};\n\n/**\n * @brief Stern-Brocot Tree\n * @docs docs/math/stern-brocot-tree.md\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: math/stern-brocot-tree.hpp
  requiredBy: []
  timestamp: '2026-06-28 14:52:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/math/LC_stern_brocot_tree.test.cpp
documentation_of: math/stern-brocot-tree.hpp
layout: document
redirect_from:
- /library/math/stern-brocot-tree.hpp
- /library/math/stern-brocot-tree.hpp.html
title: Stern-Brocot Tree
---
## 使い方

Stern-Brocot Tree 上のノードに対応する構造体．

- `SternBrocotTreeNode()` : $1/1$．
- `SternBrocotTreeNode(T x, T y)` : $x/y$．
- `SternBrocotTreeNode(const vector<T> seq)` : SBT 上でのパス `seq` から復元．
- `get()` : 現在のノードに対応する値．
- `lower_bound()` : 現在のノードに対応する区間の左端の値．
- `upper_bound()` : 現在のノードに対応する区間の右端の値．
- `go_left(T d = 1)` : 左の子へ $d$ 回降りる．
- `go_right(T d = 1)` : 右の子へ $d$ 回降りる．
- `depth()` : SBT 上での深さを計算．
- `go_parent(T d = 1)` : 親へ $d$ 回上がる．深さが $d$ 未満なら $1/1$ で停止して `false` を返す．
- `SternBrocotTreeNode::lca(x, y)` : `x`, `y` の LCA を計算．
- `SternBrocotTreeNode::binary_search<F>(T n, F f)` : 分母が $n$ 以下の既約分数で，`f(a,b)` が `false` のうち最大，`f(a,b)` が `true` のうち最小のものをそれぞれ求める．
  - $f(a,b)$ は $a/b$ について単調であることが必要．