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
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/wavelet-matrix-with-segment-tree.hpp
    title: data-structure/wavelet-matrix-with-segment-tree.hpp
  - icon: ':warning:'
    path: segment-tree/segment-tree-util.hpp
    title: "\u3088\u304F\u4F7F\u3046 Segment Tree"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data-structure/LC_point_add_rectangle_sum.wavelet_matrix.test.cpp
    title: verify/data-structure/LC_point_add_rectangle_sum.wavelet_matrix.test.cpp
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
    \ }\n};\n#line 3 \"segment-tree/segment-tree.hpp\"\n\ntemplate <class M>\nREQUIRES(Monoid<M>)\n\
    struct SegmentTree {\n  using T = typename M::value_type;\n\n private:\n  int\
    \ _n, size, log;\n  vector<T> d;\n  void update(int p) { d[p] = M::op(d[2 * p],\
    \ d[2 * p + 1]); }\n\n public:\n  SegmentTree() : SegmentTree(0) {}\n  explicit\
    \ SegmentTree(int sz) : SegmentTree(vector<T>(sz, M::e())) {}\n  explicit SegmentTree(const\
    \ vector<T>& v) : _n(v.size()) {\n    size = 1, log = 0;\n    while (size < _n)\
    \ size <<= 1, log++;\n    d.assign(2 * size, M::e());\n    for (int i = 0; i <\
    \ _n; i++) d[size + i] = v[i];\n    for (int i = size - 1; i > 0; i--) update(i);\n\
    \  }\n  void clear() { fill(d.begin(), d.end(), M::e()); }\n\n  void set_without_update(int\
    \ p, T v) { d[p + size] = v; }\n  void all_update() {\n    for (int i = size -\
    \ 1; i > 0; i--) update(i);\n  }\n  T get(int p) {\n    assert(0 <= p && p <=\
    \ _n);\n    return d[p + size];\n  }\n  void set(int p, T v) {\n    assert(0 <=\
    \ p && p <= _n);\n    p += size;\n    d[p] = v;\n    for (int i = 1; i <= log;\
    \ i++) update(p >> i);\n  }\n  void apply(int p, T v) {\n    assert(0 <= p &&\
    \ p <= _n);\n    p += size;\n    d[p] = M::op(d[p], v);\n    for (int i = 1; i\
    \ <= log; i++) update(p >> i);\n  }\n  T all_prod() { return d[1]; }\n  T prod(int\
    \ l, int r) {\n    if (l >= r) return M::e();\n    assert(0 <= l && l <= r &&\
    \ r <= _n);\n    T sl = M::e(), sr = M::e();\n    l += size, r += size;\n    while\
    \ (l < r) {\n      if ((l & 1) != 0) sl = M::op(sl, d[l++]);\n      if ((r & 1)\
    \ != 0) sr = M::op(d[--r], sr);\n      l >>= 1, r >>= 1;\n    }\n    return M::op(sl,\
    \ sr);\n  }\n\n  template <bool (*f)(T)>\n  int max_right(int l) const {\n   \
    \ return max_right(l, [](T x) { return f(x); });\n  }\n  template <class F>\n\
    \  int max_right(int l, F f) const {\n    assert(0 <= l && l <= size);\n    assert(f(M::e()));\n\
    \    if (l == _n) return _n;\n    l += size;\n    T s = M::e();\n    do {\n  \
    \    while (l % 2 == 0) l >>= 1;\n      if (!f(M::op(s, d[l]))) {\n        while\
    \ (l < size) {\n          l <<= 1;\n          if (f(M::op(s, d[l]))) s = M::op(s,\
    \ d[l++]);\n        }\n        return l - size;\n      }\n      s = M::op(s, d[l++]);\n\
    \    } while ((l & -l) != l);\n    return _n;\n  }\n\n  template <bool (*f)(T)>\n\
    \  int min_left(int r) const {\n    return min_left(r, [](T x) { return f(x);\
    \ });\n  }\n  template <class F>\n  int min_left(int r, F f) const {\n    assert(0\
    \ <= r && r <= _n);\n    assert(f(M::e()));\n    if (r == 0) return 0;\n    r\
    \ += size;\n    T s = M::e();\n    do {\n      r--;\n      while (r > 1 && (r\
    \ % 2)) r >>= 1;\n      if (!f(M::op(d[r], s))) {\n        while (r < size) {\n\
    \          r <<= 1, r++;\n          if (f(M::op(d[r], s))) s = M::op(d[r--], s);\n\
    \        }\n        return r + 1 - size;\n      }\n      s = M::op(d[r], s);\n\
    \    } while ((r & -r) != r);\n    return 0;\n  }\n};\n\n/**\n * @brief Segment\
    \ Tree\n * @docs docs/segment-tree/segment-tree.md\n */\n"
  code: "#pragma once\n#include \"algebraic-structure/monoid.hpp\"\n\ntemplate <class\
    \ M>\nREQUIRES(Monoid<M>)\nstruct SegmentTree {\n  using T = typename M::value_type;\n\
    \n private:\n  int _n, size, log;\n  vector<T> d;\n  void update(int p) { d[p]\
    \ = M::op(d[2 * p], d[2 * p + 1]); }\n\n public:\n  SegmentTree() : SegmentTree(0)\
    \ {}\n  explicit SegmentTree(int sz) : SegmentTree(vector<T>(sz, M::e())) {}\n\
    \  explicit SegmentTree(const vector<T>& v) : _n(v.size()) {\n    size = 1, log\
    \ = 0;\n    while (size < _n) size <<= 1, log++;\n    d.assign(2 * size, M::e());\n\
    \    for (int i = 0; i < _n; i++) d[size + i] = v[i];\n    for (int i = size -\
    \ 1; i > 0; i--) update(i);\n  }\n  void clear() { fill(d.begin(), d.end(), M::e());\
    \ }\n\n  void set_without_update(int p, T v) { d[p + size] = v; }\n  void all_update()\
    \ {\n    for (int i = size - 1; i > 0; i--) update(i);\n  }\n  T get(int p) {\n\
    \    assert(0 <= p && p <= _n);\n    return d[p + size];\n  }\n  void set(int\
    \ p, T v) {\n    assert(0 <= p && p <= _n);\n    p += size;\n    d[p] = v;\n \
    \   for (int i = 1; i <= log; i++) update(p >> i);\n  }\n  void apply(int p, T\
    \ v) {\n    assert(0 <= p && p <= _n);\n    p += size;\n    d[p] = M::op(d[p],\
    \ v);\n    for (int i = 1; i <= log; i++) update(p >> i);\n  }\n  T all_prod()\
    \ { return d[1]; }\n  T prod(int l, int r) {\n    if (l >= r) return M::e();\n\
    \    assert(0 <= l && l <= r && r <= _n);\n    T sl = M::e(), sr = M::e();\n \
    \   l += size, r += size;\n    while (l < r) {\n      if ((l & 1) != 0) sl = M::op(sl,\
    \ d[l++]);\n      if ((r & 1) != 0) sr = M::op(d[--r], sr);\n      l >>= 1, r\
    \ >>= 1;\n    }\n    return M::op(sl, sr);\n  }\n\n  template <bool (*f)(T)>\n\
    \  int max_right(int l) const {\n    return max_right(l, [](T x) { return f(x);\
    \ });\n  }\n  template <class F>\n  int max_right(int l, F f) const {\n    assert(0\
    \ <= l && l <= size);\n    assert(f(M::e()));\n    if (l == _n) return _n;\n \
    \   l += size;\n    T s = M::e();\n    do {\n      while (l % 2 == 0) l >>= 1;\n\
    \      if (!f(M::op(s, d[l]))) {\n        while (l < size) {\n          l <<=\
    \ 1;\n          if (f(M::op(s, d[l]))) s = M::op(s, d[l++]);\n        }\n    \
    \    return l - size;\n      }\n      s = M::op(s, d[l++]);\n    } while ((l &\
    \ -l) != l);\n    return _n;\n  }\n\n  template <bool (*f)(T)>\n  int min_left(int\
    \ r) const {\n    return min_left(r, [](T x) { return f(x); });\n  }\n  template\
    \ <class F>\n  int min_left(int r, F f) const {\n    assert(0 <= r && r <= _n);\n\
    \    assert(f(M::e()));\n    if (r == 0) return 0;\n    r += size;\n    T s =\
    \ M::e();\n    do {\n      r--;\n      while (r > 1 && (r % 2)) r >>= 1;\n   \
    \   if (!f(M::op(d[r], s))) {\n        while (r < size) {\n          r <<= 1,\
    \ r++;\n          if (f(M::op(d[r], s))) s = M::op(d[r--], s);\n        }\n  \
    \      return r + 1 - size;\n      }\n      s = M::op(d[r], s);\n    } while ((r\
    \ & -r) != r);\n    return 0;\n  }\n};\n\n/**\n * @brief Segment Tree\n * @docs\
    \ docs/segment-tree/segment-tree.md\n */\n"
  dependsOn:
  - algebraic-structure/monoid.hpp
  - algebraic-structure/magma.hpp
  - algebraic-structure/util.hpp
  isVerificationFile: false
  path: segment-tree/segment-tree.hpp
  requiredBy:
  - segment-tree/segment-tree-util.hpp
  - data-structure/wavelet-matrix-with-segment-tree.hpp
  timestamp: '2026-06-28 15:32:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/segment-tree/LC_point_set_range_composite.test.cpp
  - verify/segment-tree/LC_point_add_range_sum.test.cpp
  - verify/data-structure/LC_point_add_rectangle_sum.wavelet_matrix.test.cpp
documentation_of: segment-tree/segment-tree.hpp
layout: document
redirect_from:
- /library/segment-tree/segment-tree.hpp
- /library/segment-tree/segment-tree.hpp.html
title: Segment Tree
---
モノイド $(T,\cdot,e)$ に対するデータ構造．

- 実際は $\cdot$ が $T\times T$ 上全体で定義されていなくても，計算で出てくる範囲で定義されていれば構わない．

`SegmentTree<M>` として使う．
`M` は `value_type`, `op(x,y)`, `e()` を持つモノイドを表す型．
よく使うものは `AddMonoid<T>`, `MulMonoid<T>`, `MaxMonoid<T,e>`, `MinMonoid<T,e>` を使える．

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
