---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/data-structure/binary-indexed-tree.md
    document_title: Binary Indexed Tree
    links: []
  bundledCode: "#line 2 \"data-structure/binary-indexed-tree.hpp\"\n\ntemplate <class\
    \ T>\nstruct BinaryIndexedTree {\n  int size;\n  vector<T> data;\n  BinaryIndexedTree(int\
    \ n) : size(n), data(n) {}\n  T add(int p, T x) {\n    for (p++; p <= size; p\
    \ += p & -p) data[p - 1] += x;\n  }\n  T sum(int p) {\n    T s = 0;\n    for (;\
    \ p; p -= p & -p) s += data[p - 1];\n    return s;\n  }\n  T sum(int l, int r)\
    \ { return sum(r) - sum(l); }\n\n  template <bool (*f)(S)>\n  int lower_bound()\
    \ const {\n    return lower_bound([](S x) { return f(x); });\n  }\n  template\
    \ <class F>\n  int lower_bound(F f) const {\n    if (f(T(0))) return 0;\n    int\
    \ x = 0, r = 1;\n    while (r < size) r = r << 1;\n    T s = 0;\n    for (int\
    \ len = r; len > 0; len >>= 1) {\n      if (x + len < size && !f(s + data[x +\
    \ len])) {\n        s += data[x + len];\n        x += len;\n      }\n    }\n \
    \   return x + 1;\n  }\n};\n\n/**\n * @brief Binary Indexed Tree\n * @docs docs/data-structure/binary-indexed-tree.md\n\
    \ */\n"
  code: "#pragma once\n\ntemplate <class T>\nstruct BinaryIndexedTree {\n  int size;\n\
    \  vector<T> data;\n  BinaryIndexedTree(int n) : size(n), data(n) {}\n  T add(int\
    \ p, T x) {\n    for (p++; p <= size; p += p & -p) data[p - 1] += x;\n  }\n  T\
    \ sum(int p) {\n    T s = 0;\n    for (; p; p -= p & -p) s += data[p - 1];\n \
    \   return s;\n  }\n  T sum(int l, int r) { return sum(r) - sum(l); }\n\n  template\
    \ <bool (*f)(S)>\n  int lower_bound() const {\n    return lower_bound([](S x)\
    \ { return f(x); });\n  }\n  template <class F>\n  int lower_bound(F f) const\
    \ {\n    if (f(T(0))) return 0;\n    int x = 0, r = 1;\n    while (r < size) r\
    \ = r << 1;\n    T s = 0;\n    for (int len = r; len > 0; len >>= 1) {\n     \
    \ if (x + len < size && !f(s + data[x + len])) {\n        s += data[x + len];\n\
    \        x += len;\n      }\n    }\n    return x + 1;\n  }\n};\n\n/**\n * @brief\
    \ Binary Indexed Tree\n * @docs docs/data-structure/binary-indexed-tree.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/binary-indexed-tree.hpp
  requiredBy: []
  timestamp: '2025-10-10 17:35:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/binary-indexed-tree.hpp
layout: document
redirect_from:
- /library/data-structure/binary-indexed-tree.hpp
- /library/data-structure/binary-indexed-tree.hpp.html
title: Binary Indexed Tree
---
Fenwick Tree (フェニック木) とも．

列 $A=(A_0,A_1,\dots,A_{N-1})$ があり，はじめ全て $0$．

以下のクエリを，空間計算量 $\Theta(N)$ のもとクエリあたり時間計算量 $O(\log N)$ で処理する．

- `add(p, x)`：$A_p$ に $x$ を加える．
- `sum(p)`：和 $A_0+A_1+\cdots+A_{p-1}$ を求める．
- `sum(l, r)`：和 $A_l+A_1+\cdots+A_{r-1}$ を求める．**減算を行う．**
- `lower_bound(f)`：$f(A_0+A_1+\cdots+A_{p-1})$ が真となる最小の $p$ を求める．

一般の区間和で逆元を要求する代わりに segment tree よりも空間・時間計算量の定数倍が軽い．

## 仕組み

以下 1-indexed で考える．

$0\leq l\leq r\leq N$ に対し以下のように定める．

- $(l,r]\coloneqq\{l+1,\cdots,r-1,r\}.$
- $A(l,r]\coloneqq A_{l+1}+\cdots+A_{r-1}+A_r.$

また正整数 $i$ を二進表記したときに $2^j$ の位が $1$ であるような最小の $j$ を **least-significant set bit** と呼び，$\operatorname{lsb}(i)$ で表すことにする．

列 $B=(B_1,B_2,\dots,B_N)$ を $B_i=A(i-2^{\operatorname{lsb}(i)},i]$ を満たすように管理する．

$I_i\coloneqq(i-2^{\operatorname{lsb}(i)},i]$ とする．

$N=8$ のときのイメージ
```
0     1     2     3     4     5     6     7     8
|                     (0,8]                     |
|         (0,4]         |           -           |
|   (0,2]   |     -     |   (4,6]   |     -     |
|(0,1]|  -  |(2,3]|  -  |(4,5]|  -  |(6,7]|  -  |
```

### add

$p\in I_i$ となるとき $\operatorname{lsb}(p) \leq \operatorname{lsb}(i)$ が必要．

- $\forall j\in I_i$ に対し $\operatorname{lsb}(j) \leq \operatorname{lsb}(i)$ より．

$\operatorname{lsb}(p)=\operatorname{lsb}(i)$ のとき $p\in I_i$ となるのは明らかに $i=p$ のみ．

また $\operatorname{lsb}(p) \lt \operatorname{lsb}(i)$ のとき，$p\in I_i$ となることは $p$ の $2^j$ の位が $0$ であるような $j$ に対して $p$ の $2^j$ の位を $1$，$2^0,\dots,2^{j-1}$ の位を $0$ にして得られる数が $i$ と一致することと同値．

以上をまとめることで，次の要領で計算できることがわかる．

- $p\leq N$ の間以下を繰り返す：
  - $B_p$ に $x$ を加える．
  - $p$ に $2^{\operatorname{lsb}(p)}$ を加える．

### sum

$A(0,p]=A(0,p-2^{\operatorname{lsb}(p)}]+B_p$ を用いれば再帰的に計算できる．

### lower_bound

長い区間から順に条件を満たすなら付け加えていけばよい．

## 実装

$2^{\operatorname{lsb}(p)}$ は bit 演算を用いれば `p & -p` で計算できる．