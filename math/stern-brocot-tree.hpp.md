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
    \ Node binary_search(T n, F f) {\n    Node res;\n    while (true) {\n      if\
    \ (!f(res.a, res.b)) {\n        T ok = 0, ng = min(res.la > 0 ? (n - res.ra) /\
    \ res.la : n, res.lb > 0 ? (n - res.rb) / res.lb : n) + 1;\n        while (ng\
    \ - ok > 1) {\n          T mid = (ok + ng) / 2;\n          (!f(mid * res.la +\
    \ res.ra, mid * res.lb + res.rb) ? ok : ng) = mid;\n        }\n        if (ok\
    \ == 0) return res;\n        res.go_left(ok);\n      } else {\n        T ok =\
    \ 0, ng = min(res.ra > 0 ? (n - res.la) / res.ra : n, res.rb > 0 ? (n - res.lb)\
    \ / res.rb : n) + 1;\n        while (ng - ok > 1) {\n          T mid = (ok + ng)\
    \ / 2;\n          (f(res.la + mid * res.ra, res.lb + mid * res.rb) ? ok : ng)\
    \ = mid;\n        }\n        if (ok == 0) return res;\n        res.go_left(ok);\n\
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
    \ binary_search(T n, F f) {\n    Node res;\n    while (true) {\n      if (!f(res.a,\
    \ res.b)) {\n        T ok = 0, ng = min(res.la > 0 ? (n - res.ra) / res.la : n,\
    \ res.lb > 0 ? (n - res.rb) / res.lb : n) + 1;\n        while (ng - ok > 1) {\n\
    \          T mid = (ok + ng) / 2;\n          (!f(mid * res.la + res.ra, mid *\
    \ res.lb + res.rb) ? ok : ng) = mid;\n        }\n        if (ok == 0) return res;\n\
    \        res.go_left(ok);\n      } else {\n        T ok = 0, ng = min(res.ra >\
    \ 0 ? (n - res.la) / res.ra : n, res.rb > 0 ? (n - res.lb) / res.rb : n) + 1;\n\
    \        while (ng - ok > 1) {\n          T mid = (ok + ng) / 2;\n          (f(res.la\
    \ + mid * res.ra, res.lb + mid * res.rb) ? ok : ng) = mid;\n        }\n      \
    \  if (ok == 0) return res;\n        res.go_left(ok);\n      }\n    }\n  }\n};\n\
    \n/**\n * @brief Stern-Brocot Tree\n * @docs docs/math/stern-brocot-tree.md\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: math/stern-brocot-tree.hpp
  requiredBy: []
  timestamp: '2025-10-26 03:52:03+09:00'
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
- `SternBrocotTreeNode::binary_search<F>(T n, F f)` : `f(a,b)` が `true` かつ分母が $n$ 以下の最小のノードを返す．
  - $f(a,b)$ は $a/b$ について単調であることが必要．