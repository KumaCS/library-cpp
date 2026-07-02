---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data-structure/UNIT_range_add_range_positive_sum.test.cpp
    title: verify/data-structure/UNIT_range_add_range_positive_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/range-add-range-positive-sum.md
    document_title: Range Add Range Positive Sum
    links: []
  bundledCode: "#line 2 \"data-structure/range-add-range-positive-sum.hpp\"\n\ntemplate\
    \ <class T>\nstruct RangeAddRangePositiveSum {\n  RangeAddRangePositiveSum() {}\n\
    \  RangeAddRangePositiveSum(int n) : RangeAddRangePositiveSum(vector<T>(n)) {}\n\
    \  RangeAddRangePositiveSum(const vector<T>& a) : N(a.size()), B(max(1, (int)sqrt(N))),\
    \ M((N + B - 1) / B), data(a), sorted(a), sorted_sum(N + M), lazy(M) {\n    for\
    \ (int k = 0; k < M; k++) update_block(k);\n  }\n  void add(int l, int r, T v)\
    \ {\n    if (l >= r) return;\n    int bl = l / B, br = (r - 1) / B;\n    if (bl\
    \ == br) {\n      for (int i = l; i < r; i++) data[i] += v;\n      update_block(bl);\n\
    \    } else {\n      if (bl * B != l) {\n        bl++;\n        int l1 = bl *\
    \ B;\n        while (l < l1) data[l++] += v;\n        update_block(bl - 1);\n\
    \      }\n      if (r < min(N, (br + 1) * B)) {\n        int r1 = br * B;\n  \
    \      while (r1 < r) data[--r] += v;\n        update_block(br--);\n      }\n\
    \      for (int k = bl; k <= br; k++) lazy[k] += v;\n    }\n  }\n  T sum(int l,\
    \ int r) const {\n    if (l >= r) return 0;\n    T ret = 0;\n    int bl = l /\
    \ B, br = (r - 1) / B;\n    if (bl == br) {\n      for (int i = l; i < r; i++)\
    \ ret += sum_point(i);\n    } else {\n      if (bl * B != l) {\n        bl++;\n\
    \        int l1 = bl * B;\n        while (l < l1) ret += sum_point(l++);\n   \
    \   }\n      if (r < min(N, (br + 1) * B)) {\n        int r1 = br * B;\n     \
    \   while (r1 < r) ret += sum_point(--r);\n        br--;\n      }\n      for (int\
    \ k = bl; k <= br; k++) ret += sum_block(k);\n    }\n    return ret;\n  }\n\n\
    \ private:\n  int N, B, M;\n  vector<T> data, sorted, sorted_sum, lazy;\n  void\
    \ update_block(int k) {\n    int l = B * k, r = min(N, l + B);\n    int sz = r\
    \ - l;\n    copy(data.begin() + l, data.begin() + r, sorted.begin() + l);\n  \
    \  sort(sorted.begin() + l, sorted.begin() + r);\n    auto it = sorted_sum.begin()\
    \ + l + k;\n    *it = 0;\n    for (int i = 0; i < sz; i++)\n      *(it + i + 1)\
    \ = *(it + i) + sorted[l + i];\n  }\n  T sum_point(int x) const { return max<T>(0,\
    \ data[x] + lazy[x / B]); }\n  T sum_block(int k) const {\n    int l = B * k,\
    \ r = min(N, l + B);\n    int sz = r - l;\n    auto itl = sorted.begin() + l;\n\
    \    int i = lower_bound(itl, itl + sz, -lazy[k]) - itl;\n    int l1 = l + k,\
    \ r1 = l1 + sz;\n    return sorted_sum[r1] - sorted_sum[l1 + i] + lazy[k] * (sz\
    \ - i);\n  }\n};\n\n/**\n * @brief Range Add Range Positive Sum\n * @docs docs/data-structure/range-add-range-positive-sum.md\n\
    \ */\n"
  code: "#pragma once\n\ntemplate <class T>\nstruct RangeAddRangePositiveSum {\n \
    \ RangeAddRangePositiveSum() {}\n  RangeAddRangePositiveSum(int n) : RangeAddRangePositiveSum(vector<T>(n))\
    \ {}\n  RangeAddRangePositiveSum(const vector<T>& a) : N(a.size()), B(max(1, (int)sqrt(N))),\
    \ M((N + B - 1) / B), data(a), sorted(a), sorted_sum(N + M), lazy(M) {\n    for\
    \ (int k = 0; k < M; k++) update_block(k);\n  }\n  void add(int l, int r, T v)\
    \ {\n    if (l >= r) return;\n    int bl = l / B, br = (r - 1) / B;\n    if (bl\
    \ == br) {\n      for (int i = l; i < r; i++) data[i] += v;\n      update_block(bl);\n\
    \    } else {\n      if (bl * B != l) {\n        bl++;\n        int l1 = bl *\
    \ B;\n        while (l < l1) data[l++] += v;\n        update_block(bl - 1);\n\
    \      }\n      if (r < min(N, (br + 1) * B)) {\n        int r1 = br * B;\n  \
    \      while (r1 < r) data[--r] += v;\n        update_block(br--);\n      }\n\
    \      for (int k = bl; k <= br; k++) lazy[k] += v;\n    }\n  }\n  T sum(int l,\
    \ int r) const {\n    if (l >= r) return 0;\n    T ret = 0;\n    int bl = l /\
    \ B, br = (r - 1) / B;\n    if (bl == br) {\n      for (int i = l; i < r; i++)\
    \ ret += sum_point(i);\n    } else {\n      if (bl * B != l) {\n        bl++;\n\
    \        int l1 = bl * B;\n        while (l < l1) ret += sum_point(l++);\n   \
    \   }\n      if (r < min(N, (br + 1) * B)) {\n        int r1 = br * B;\n     \
    \   while (r1 < r) ret += sum_point(--r);\n        br--;\n      }\n      for (int\
    \ k = bl; k <= br; k++) ret += sum_block(k);\n    }\n    return ret;\n  }\n\n\
    \ private:\n  int N, B, M;\n  vector<T> data, sorted, sorted_sum, lazy;\n  void\
    \ update_block(int k) {\n    int l = B * k, r = min(N, l + B);\n    int sz = r\
    \ - l;\n    copy(data.begin() + l, data.begin() + r, sorted.begin() + l);\n  \
    \  sort(sorted.begin() + l, sorted.begin() + r);\n    auto it = sorted_sum.begin()\
    \ + l + k;\n    *it = 0;\n    for (int i = 0; i < sz; i++)\n      *(it + i + 1)\
    \ = *(it + i) + sorted[l + i];\n  }\n  T sum_point(int x) const { return max<T>(0,\
    \ data[x] + lazy[x / B]); }\n  T sum_block(int k) const {\n    int l = B * k,\
    \ r = min(N, l + B);\n    int sz = r - l;\n    auto itl = sorted.begin() + l;\n\
    \    int i = lower_bound(itl, itl + sz, -lazy[k]) - itl;\n    int l1 = l + k,\
    \ r1 = l1 + sz;\n    return sorted_sum[r1] - sorted_sum[l1 + i] + lazy[k] * (sz\
    \ - i);\n  }\n};\n\n/**\n * @brief Range Add Range Positive Sum\n * @docs docs/data-structure/range-add-range-positive-sum.md\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/range-add-range-positive-sum.hpp
  requiredBy: []
  timestamp: '2026-07-02 22:11:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data-structure/UNIT_range_add_range_positive_sum.test.cpp
documentation_of: data-structure/range-add-range-positive-sum.hpp
layout: document
redirect_from:
- /library/data-structure/range-add-range-positive-sum.hpp
- /library/data-structure/range-add-range-positive-sum.hpp.html
title: Range Add Range Positive Sum
---
列 $A=(A_0,A_1,\dots,A_{N-1})$ を管理し，区間加算と正の部分だけの区間和を求めるデータ構造．

- `RangeAddRangePositiveSum<T>(n)`：長さ $n$，全要素 $0$ で初期化する．
- `RangeAddRangePositiveSum<T>(a)`：列 `a` で初期化する．
- `add(l, r, v)`：各 $i\in[l,r)$ について $A_i\leftarrow A_i+v$ とする．
- `sum(l, r)`：$\sum_{i=l}^{r-1}\max(A_i,0)$ を返す．

空区間に対する `add` は何もせず，`sum` は $0$ を返す．

## 計算量

平方分割を用いる．ブロックサイズを $B$，ブロック数を $M$ とすると，

- `add(l, r, v)`：$O(B\log B+M)$
- `sum(l, r)`：$O(B+M\log B)$

空間計算量は $O(N)$．

## 仕組み

各ブロックについて，遅延加算値，ソート済み列，ソート済み列の prefix sum を持つ．

ブロック全体に加算するときは遅延加算値だけを更新する．
ブロックの一部だけを更新するときは，元の値を直接更新して，そのブロックのソート済み列と prefix sum を作り直す．

`sum` でブロック全体を見るときは，ソート済み列から `lower_bound(-lazy)` で正になる要素を探し，prefix sum と遅延加算値からまとめて寄与を計算する．
