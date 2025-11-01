---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/segment-tree/LC_point_add_range_sum.test.cpp
    title: verify/segment-tree/LC_point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/segment-tree/LC_point_set_range_composite.test.cpp
    title: verify/segment-tree/LC_point_set_range_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/segment-tree/segment-tree.md
    document_title: Segment Tree
    links: []
  bundledCode: "#line 2 \"segment-tree/segment-tree.hpp\"\n\ntemplate <class T, T\
    \ (*op)(T, T), T (*e)()>\nstruct SegmentTree {\n private:\n  int n;\n  vector<T>\
    \ d;\n  void update(int p) { d[p] = op(d[2 * p], d[2 * p + 1]); }\n\n public:\n\
    \  SegmentTree() : SegmentTree(0) {}\n  explicit SegmentTree(int sz) : SegmentTree(vector<T>(sz,\
    \ e())) {}\n  explicit SegmentTree(const vector<T>& v) : n(v.size()) {\n    d.assign(2\
    \ * n, e());\n    for (int i = 0; i < v.size(); i++) d[n + i] = v[i];\n    for\
    \ (int i = n - 1; i > 0; i--) update(i);\n  }\n  void clear() { fill(d.begin(),\
    \ d.end(), e()); }\n\n  void set_without_update(int p, T v) { d[n + p] = v; }\n\
    \  void all_update() {\n    for (int i = n - 1; i > 0; i--) update(i);\n  }\n\
    \  T get(int p) {\n    assert(0 <= p && p <= n);\n    return d[p + n];\n  }\n\
    \  void set(int p, T v) {\n    assert(0 <= p && p <= n);\n    d[p += n] = v;\n\
    \    for (p >>= 1; p > 0; p >>= 1) update(p);\n  }\n  void apply(int p, T v) {\n\
    \    assert(0 <= p && p <= n);\n    p += n;\n    d[p] = op(d[p], v);\n    for\
    \ (p >>= 1; p > 0; p >>= 1) update(p);\n  }\n  T prod(int l, int r) {\n    if\
    \ (l >= r) return e();\n    assert(0 <= l && l <= r && r <= n);\n    T sl = e(),\
    \ sr = e();\n    l += n, r += n;\n    while (l < r) {\n      if ((l & 1) != 0)\
    \ sl = op(sl, d[l++]);\n      if ((r & 1) != 0) sr = op(d[--r], sr);\n      l\
    \ >>= 1, r >>= 1;\n    }\n    return op(sl, sr);\n  }\n  T all_prod() { return\
    \ prod(0, n); }\n\n  template <bool (*f)(T)>\n  int max_right(int l) const {\n\
    \    return max_right(l, [](T x) { return f(x); });\n  }\n  template <class F>\n\
    \  int max_right(int l, F f) const {\n    assert(0 <= l && l <= n);\n    assert(f(e()));\n\
    \    if (l == n) return n;\n    int x = n + l, w = 1;\n    T s = e();\n    for\
    \ (; l + w <= n; x >>= 1, w <<= 1)\n      if (x & 1) {\n        if (!f(op(s, d[x])))\
    \ break;\n        s = op(s, d[x++]);\n        l += w;\n      }\n    while (x <<=\
    \ 1, w >>= 1) {\n      if (l + w <= n && f(op(s, d[x]))) {\n        s = op(s,\
    \ d[l++]);\n        l += w;\n      }\n    }\n    return l;\n  }\n\n  template\
    \ <bool (*f)(T)>\n  int min_left(int r) const {\n    return min_left(r, [](T x)\
    \ { return f(x); });\n  }\n  template <class F>\n  int min_left(int r, F f) const\
    \ {\n    assert(0 <= r && r <= n);\n    assert(f(e()));\n    if (r == 0) return\
    \ 0;\n    int x = n + r, w = 1;\n    T s = e();\n    for (; r - w >= 0; x >>=\
    \ 1, w <<= 1)\n      if (x & 1) {\n        if (!f(op(d[x - 1], s))) break;\n \
    \       s = op(d[--x], s);\n        r -= w;\n      }\n    while (x <<= 1, w >>=\
    \ 1) {\n      if (r - w >= 0 && f(op(d[x - 1], s))) {\n        s = op(d[--x],\
    \ s);\n        r -= w;\n      }\n    }\n    return r;\n  }\n};\n\n/**\n * @brief\
    \ Segment Tree\n * @docs docs/segment-tree/segment-tree.md\n */\n"
  code: "#pragma once\n\ntemplate <class T, T (*op)(T, T), T (*e)()>\nstruct SegmentTree\
    \ {\n private:\n  int n;\n  vector<T> d;\n  void update(int p) { d[p] = op(d[2\
    \ * p], d[2 * p + 1]); }\n\n public:\n  SegmentTree() : SegmentTree(0) {}\n  explicit\
    \ SegmentTree(int sz) : SegmentTree(vector<T>(sz, e())) {}\n  explicit SegmentTree(const\
    \ vector<T>& v) : n(v.size()) {\n    d.assign(2 * n, e());\n    for (int i = 0;\
    \ i < v.size(); i++) d[n + i] = v[i];\n    for (int i = n - 1; i > 0; i--) update(i);\n\
    \  }\n  void clear() { fill(d.begin(), d.end(), e()); }\n\n  void set_without_update(int\
    \ p, T v) { d[n + p] = v; }\n  void all_update() {\n    for (int i = n - 1; i\
    \ > 0; i--) update(i);\n  }\n  T get(int p) {\n    assert(0 <= p && p <= n);\n\
    \    return d[p + n];\n  }\n  void set(int p, T v) {\n    assert(0 <= p && p <=\
    \ n);\n    d[p += n] = v;\n    for (p >>= 1; p > 0; p >>= 1) update(p);\n  }\n\
    \  void apply(int p, T v) {\n    assert(0 <= p && p <= n);\n    p += n;\n    d[p]\
    \ = op(d[p], v);\n    for (p >>= 1; p > 0; p >>= 1) update(p);\n  }\n  T prod(int\
    \ l, int r) {\n    if (l >= r) return e();\n    assert(0 <= l && l <= r && r <=\
    \ n);\n    T sl = e(), sr = e();\n    l += n, r += n;\n    while (l < r) {\n \
    \     if ((l & 1) != 0) sl = op(sl, d[l++]);\n      if ((r & 1) != 0) sr = op(d[--r],\
    \ sr);\n      l >>= 1, r >>= 1;\n    }\n    return op(sl, sr);\n  }\n  T all_prod()\
    \ { return prod(0, n); }\n\n  template <bool (*f)(T)>\n  int max_right(int l)\
    \ const {\n    return max_right(l, [](T x) { return f(x); });\n  }\n  template\
    \ <class F>\n  int max_right(int l, F f) const {\n    assert(0 <= l && l <= n);\n\
    \    assert(f(e()));\n    if (l == n) return n;\n    int x = n + l, w = 1;\n \
    \   T s = e();\n    for (; l + w <= n; x >>= 1, w <<= 1)\n      if (x & 1) {\n\
    \        if (!f(op(s, d[x]))) break;\n        s = op(s, d[x++]);\n        l +=\
    \ w;\n      }\n    while (x <<= 1, w >>= 1) {\n      if (l + w <= n && f(op(s,\
    \ d[x]))) {\n        s = op(s, d[l++]);\n        l += w;\n      }\n    }\n   \
    \ return l;\n  }\n\n  template <bool (*f)(T)>\n  int min_left(int r) const {\n\
    \    return min_left(r, [](T x) { return f(x); });\n  }\n  template <class F>\n\
    \  int min_left(int r, F f) const {\n    assert(0 <= r && r <= n);\n    assert(f(e()));\n\
    \    if (r == 0) return 0;\n    int x = n + r, w = 1;\n    T s = e();\n    for\
    \ (; r - w >= 0; x >>= 1, w <<= 1)\n      if (x & 1) {\n        if (!f(op(d[x\
    \ - 1], s))) break;\n        s = op(d[--x], s);\n        r -= w;\n      }\n  \
    \  while (x <<= 1, w >>= 1) {\n      if (r - w >= 0 && f(op(d[x - 1], s))) {\n\
    \        s = op(d[--x], s);\n        r -= w;\n      }\n    }\n    return r;\n\
    \  }\n};\n\n/**\n * @brief Segment Tree\n * @docs docs/segment-tree/segment-tree.md\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: segment-tree/segment-tree.hpp
  requiredBy: []
  timestamp: '2025-10-17 21:43:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/segment-tree/LC_point_add_range_sum.test.cpp
  - verify/segment-tree/LC_point_set_range_composite.test.cpp
documentation_of: segment-tree/segment-tree.hpp
layout: document
redirect_from:
- /library/segment-tree/segment-tree.hpp
- /library/segment-tree/segment-tree.hpp.html
title: Segment Tree
---
モノイド $(T,\cdot,e)$ に対するデータ構造．

- 実際は $\cdot$ が $T\times T$ 上全体で定義されていなくても，計算で出てくる範囲で定義されていれば構わない．

長さ $N$ の $T$ の列 $A=(A_0,A_1,\dots,A_{N-1})$ に対し，空間計算量 $\Theta(N)$ のもとで以下の操作を行う．

- 一点更新：$O(\log N)$ 時間
- 区間総積：$O(\log N)$ 時間
- 区間の二分探索：$O(\log N)$ 時間

## 二分探索のしかた

$f$ は単調であること，また $f(e)$ が真であることを仮定する．

- `max_right`：$f(A_l \cdot A_{l+1} \cdot \cdots \cdot A_{r-1})$ が真となる最大の $r$ を返す．
- `min_left`：$f(A_l \cdot A_{l+1} \cdot \cdots \cdot A_{r-1})$ が真となる最小の $l$ を返す．

## 仕組み

必要ならば $A$ を伸ばして $N$ が二冪 $2^n$ であるとする．

$0\leq i\leq n,0\leq j\lt 2^{n-i}$ について区間 $[2^ij,2^i(j+1))$ を $1$ 以上 $2N$ 未満の整数 $2^{n-i}+j(=k)$ に対応させ，その区間を $I_k$ と表す．

完全二分木に対応している．

$N=8$ のときの様子
```
0     1     2     3     4     5     6     7     8    k
|                     [0,8)                     |    1
|         [0,4)         |         [4,8)         |  2 ~ 3
|   [0,2)   |   [2,4)   |   [4,6)   |   [6,8)   |  4 ~ 7
|[0,1)|[1,2)|[2,3)|[3,4)|[4,5)|[5,6)|[6,7)|[7,8)|  8 ~ 15
```

また $X_k=\prod_{i\in I_k}A_i$ として，$(X_1,X_2,\dots,X_{2N-1})$ を管理する．

$1\leq k\lt N$ に対して $I_k=I_{2k}\cup I_{2k+1},I_{2k}\cap I_{2k+1}=\emptyset$ が成り立つため，$X$ の満たすべき条件は次のように表現できる．

- $0\leq i\lt N$ に対して $X_{i+N}=A_i$．
- $1\leq i\lt N$ に対して $X_{i}=X_{2i}\cdot X_{2i+1}$

### 一点更新

$A_i$ を更新する場合，まず $X_{i+N}$ を更新した上で二分木を根へ辿りながら $X$ を更新していけばよい．

### 区間総積

$[l,r)$ の総積を取得する場合，二分木を降りていく方法と上がっていく方法がある．

実装は上がっていく方法に対応している．

深さ $i+1$ にある連続する区間の和は，左右の端の区間を高々一つずつ取り除くことで深さ $i$ にある区間の和で表せることを用いている．

例えば $n=4(N=16),[l,r)=[1,13)$ のとき，以下のような式変形に対応する計算をしている．

$$\begin{align*}
[1,13)
&=[1,2)\cup[2,12)\cup[12,13)\\
&=[1,2)\cup[2,4)\cup[4,12)\cup[12,13)\\
&=[1,2)\cup[2,4)\cup[4,8)\cup[8,12)\cup[12,13)
\end{align*}$$

### 二分探索

$l,f$ が与えられたときに $f(A_l \cdot A_{l+1} \cdot \cdots \cdot A_{r-1})$ が真となる最大の $r$ を求める．

$l=0$ のときは長い区間から順に加えられるなら加えていけばよい．

一般の $l$ でも $l=0$ と同様のケースに帰着できる．

- すでに確認済みの区間の積を $P$ とする．はじめ $P=e$．
- 左端が $l$ の区間で最も大きいものを $I=[l,m)$ とする．
- $f(P\cdot A_I)$ が真なら $P\leftarrow P\cdot A_I,l\leftarrow m$ として繰り返す．
- $f(P\cdot A_I)$ が偽なら求める $r$ が $I$ の中に存在する．
  - $l=0$ のケースと同様に考えられる．


## 長さを二冪にしない場合

長さを二冪にせずとも，基本的に同じコードで動く．

更新によって $X$ のうち意味をもたない値が入る箇所が生まれる．

例：$N=11$ のとき

```
     |         3         |         4         |
     |    6    |    7    |    8    |    9    |   10    |
| 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 |
```

二分探索で invalid な区間に入らないように注意．