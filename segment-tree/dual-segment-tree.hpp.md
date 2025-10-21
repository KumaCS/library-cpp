---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/segment-tree/LC_range_affine_point_get.test.cpp
    title: verify/segment-tree/LC_range_affine_point_get.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/segment-tree/dual-segment-tree.md
    document_title: Dual Segment Tree
    links: []
  bundledCode: "#line 2 \"segment-tree/dual-segment-tree.hpp\"\n\ntemplate <class\
    \ F, F (*op)(F, F), F (*e)()>\nstruct DualSegmentTree {\n private:\n  int _n,\
    \ size, log;\n  vector<F> lz;\n\n public:\n  DualSegmentTree() : DualSegmentTree(0)\
    \ {}\n  explicit DualSegmentTree(int n) : DualSegmentTree(vector<F>(n, e())) {}\n\
    \  explicit DualSegmentTree(const vector<F> &v) : _n(int(v.size())) {\n    size\
    \ = 1, log = 0;\n    while (size < _n) size <<= 1, log++;\n    lz = vector<F>(2\
    \ * size, e());\n    for (int i = 0; i < _n; i++) lz[size + i] = v[i];\n  }\n\
    \  void set(int p, F f) {\n    assert(0 <= p && p < _n);\n    p += size;\n   \
    \ for (int i = log; i > 0; i--) push(p >> i);\n    lz[p] = f;\n  }\n  F get(int\
    \ p) {\n    assert(0 <= p && p < _n);\n    p += size;\n    for (int i = log; i\
    \ > 0; i--) push(p >> i);\n    return lz[p];\n  }\n  vector<F> all_get() {\n \
    \   for (int i = 1; i < size; i++) push(i);\n    return vector<F>(lz.begin() +\
    \ size, lz.begin() + (size + _n));\n  }\n  void apply(int p, F f) {\n    assert(0\
    \ <= p && p < _n);\n    p += size;\n    for (int i = log; i > 0; i--) push(p >>\
    \ i);\n    inner_apply(p, f);\n  }\n  void apply(int l, int r, F f) {\n    if\
    \ (l >= r) return;\n    assert(0 <= l && l <= r && r <= _n);\n    l += size, r\
    \ += size;\n    for (int i = log; i > 0; i--) {\n      if (((l >> i) << i) !=\
    \ l) push(l >> i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n\
    \    while (l < r) {\n      if ((l & 1) != 0) inner_apply(l++, f);\n      if ((r\
    \ & 1) != 0) inner_apply(--r, f);\n      l >>= 1, r >>= 1;\n    }\n  }\n\n private:\n\
    \  void push(int k) {\n    inner_apply(2 * k, lz[k]);\n    inner_apply(2 * k +\
    \ 1, lz[k]);\n    lz[k] = e();\n  }\n  void inner_apply(int k, F f) { lz[k] =\
    \ op(f, lz[k]); }\n};\n\n/**\n * @brief Dual Segment Tree\n * @docs docs/segment-tree/dual-segment-tree.md\n\
    \ */\n"
  code: "#pragma once\n\ntemplate <class F, F (*op)(F, F), F (*e)()>\nstruct DualSegmentTree\
    \ {\n private:\n  int _n, size, log;\n  vector<F> lz;\n\n public:\n  DualSegmentTree()\
    \ : DualSegmentTree(0) {}\n  explicit DualSegmentTree(int n) : DualSegmentTree(vector<F>(n,\
    \ e())) {}\n  explicit DualSegmentTree(const vector<F> &v) : _n(int(v.size()))\
    \ {\n    size = 1, log = 0;\n    while (size < _n) size <<= 1, log++;\n    lz\
    \ = vector<F>(2 * size, e());\n    for (int i = 0; i < _n; i++) lz[size + i] =\
    \ v[i];\n  }\n  void set(int p, F f) {\n    assert(0 <= p && p < _n);\n    p +=\
    \ size;\n    for (int i = log; i > 0; i--) push(p >> i);\n    lz[p] = f;\n  }\n\
    \  F get(int p) {\n    assert(0 <= p && p < _n);\n    p += size;\n    for (int\
    \ i = log; i > 0; i--) push(p >> i);\n    return lz[p];\n  }\n  vector<F> all_get()\
    \ {\n    for (int i = 1; i < size; i++) push(i);\n    return vector<F>(lz.begin()\
    \ + size, lz.begin() + (size + _n));\n  }\n  void apply(int p, F f) {\n    assert(0\
    \ <= p && p < _n);\n    p += size;\n    for (int i = log; i > 0; i--) push(p >>\
    \ i);\n    inner_apply(p, f);\n  }\n  void apply(int l, int r, F f) {\n    if\
    \ (l >= r) return;\n    assert(0 <= l && l <= r && r <= _n);\n    l += size, r\
    \ += size;\n    for (int i = log; i > 0; i--) {\n      if (((l >> i) << i) !=\
    \ l) push(l >> i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n\
    \    while (l < r) {\n      if ((l & 1) != 0) inner_apply(l++, f);\n      if ((r\
    \ & 1) != 0) inner_apply(--r, f);\n      l >>= 1, r >>= 1;\n    }\n  }\n\n private:\n\
    \  void push(int k) {\n    inner_apply(2 * k, lz[k]);\n    inner_apply(2 * k +\
    \ 1, lz[k]);\n    lz[k] = e();\n  }\n  void inner_apply(int k, F f) { lz[k] =\
    \ op(f, lz[k]); }\n};\n\n/**\n * @brief Dual Segment Tree\n * @docs docs/segment-tree/dual-segment-tree.md\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: segment-tree/dual-segment-tree.hpp
  requiredBy: []
  timestamp: '2025-10-17 21:43:09+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/segment-tree/LC_range_affine_point_get.test.cpp
documentation_of: segment-tree/dual-segment-tree.hpp
layout: document
redirect_from:
- /library/segment-tree/dual-segment-tree.hpp
- /library/segment-tree/dual-segment-tree.hpp.html
title: Dual Segment Tree
---
モノイド $(T,\cdot,e)$ に対するデータ構造．

- 実際は $\cdot$ が $T\times T$ 上全体で定義されていなくても，計算で出てくる範囲で定義されていれば構わない．

長さ $N$ の $T$ の列 $A=(A_0,A_1,\dots,A_{N-1})$ に対し，空間計算量 $\Theta(N)$ のもとで以下の操作を行う．

- 区間乗算：$O(\log N)$ 時間
- 一点取得：$O(\log N)$ 時間

ただし乗算は左から掛けるものとする．

すなわち $[l,r)$ への $x$ の乗算では以下を行う．

- $i\in[l,r)$ に対し $A_i\leftarrow x\cdot A_i$ とする．

## 仕組み

通常のセグメント木では，適当な区間についてそこに含まれる要素の総積を管理していた．

双対セグメント木では，適当な区間についてそこに含まれる要素全てに共通して乗算される値を管理する．

また通常のセグメント木では下から上に値を伝播させていたが，双対セグメント木では上から下に値を伝播させる．

### 演算が可換なとき

区間乗算は通常のセグメント木での区間総積と，一点取得は通常のセグメント木での一点更新と同様にすればよい．

### 演算が非可換なとき

値を更新する前に，その親の情報を子に伝播しておく必要がある．

子への伝播を行うべき区間は，更新する区間を分割したときに端にくる区間の上にあるもののみ．

従って $O(\log N)$ 時間で行える．
