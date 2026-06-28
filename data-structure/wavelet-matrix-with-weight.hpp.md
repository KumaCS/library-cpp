---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: data-structure/bit-vector.hpp
    title: data-structure/bit-vector.hpp
  - icon: ':warning:'
    path: data-structure/wavelet-matrix.hpp
    title: Wavelet Matrix
  _extendedRequiredBy:
  - icon: ':warning:'
    path: verify/data-structure/LC_rectangle_sum.wavelet_matrix.cpp
    title: verify/data-structure/LC_rectangle_sum.wavelet_matrix.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/wavelet-matrix-with-weight.hpp\"\n\n#line\
    \ 2 \"data-structure/wavelet-matrix.hpp\"\n\n#line 2 \"data-structure/bit-vector.hpp\"\
    \n\nstruct BitVector {\n  using i32 = int32_t;\n  using u32 = uint32_t;\n  using\
    \ u64 = uint64_t;\n\n  static constexpr u32 W = 64;\n  inline u32 get(u32 i) const\
    \ { return u32(block[i / W] >> (i % W)) & 1u; }\n  inline void set(u32 i) { block[i\
    \ / W] |= 1ull << (i % W); }\n\n  vector<u64> block;\n  vector<i32> count;\n \
    \ u32 n, zeros;\n  BitVector() {}\n  BitVector(int _n) : n(_n) {\n    block.resize(n\
    \ / W + 1, 0);\n    count.resize(block.size(), 0);\n  }\n  void build() {\n  \
    \  for (u32 i = 1; i < block.size(); i++)\n      count[i] = count[i - 1] + __builtin_popcountll(block[i\
    \ - 1]);\n    zeros = rank0(n);\n  }\n  inline u32 rank0(u32 i) const { return\
    \ i - rank1(i); }\n  inline u32 rank1(u32 i) const { return count[i / W] + __builtin_popcountll(block[i\
    \ / W] & ((1ull << i % W) - 1)); }\n};\n#line 4 \"data-structure/wavelet-matrix.hpp\"\
    \n\ntemplate <class T, int B = 30>\nstruct WaveletMatrix {\n  using u32 = uint32_t;\n\
    \  using i64 = int64_t;\n  using u64 = uint64_t;\n\n  int n;\n  vector<T> a;\n\
    \  vector<BitVector> bv;\n\n  WaveletMatrix(u32 _n) : n(max<u32>(_n, 1)), a(n)\
    \ {}\n  WaveletMatrix(const vector<T>& _a) : n(_a.size()), a(_a) { build(); }\n\
    \n  void set(u32 i, const T& x) {\n    assert(x >= 0);\n    a[i] = x;\n  }\n\n\
    \  void build() {\n    bv.assign(B, n);\n    vector<T> cur = a, nxt(n);\n    for\
    \ (int h = B - 1; h >= 0; --h) {\n      for (int i = 0; i < n; ++i)\n        if\
    \ ((cur[i] >> h) & 1) bv[h].set(i);\n      bv[h].build();\n      array<decltype(begin(nxt)),\
    \ 2> it{begin(nxt), begin(nxt) + bv[h].zeros};\n      for (int i = 0; i < n; ++i)\
    \ *it[bv[h].get(i)]++ = cur[i];\n      swap(cur, nxt);\n    }\n  }\n\n  inline\
    \ pair<u32, u32> succ0(int l, int r, int h) const {\n    return make_pair(bv[h].rank0(l),\
    \ bv[h].rank0(r));\n  }\n  inline pair<u32, u32> succ1(int l, int r, int h) const\
    \ {\n    u32 l0 = bv[h].rank0(l);\n    u32 r0 = bv[h].rank0(r);\n    u32 zeros\
    \ = bv[h].zeros;\n    return make_pair(l + zeros - l0, r + zeros - r0);\n  }\n\
    \n  // return a[k]\n  T access(u32 k) const {\n    T ret = 0;\n    for (int h\
    \ = B - 1; h >= 0; --h) {\n      u32 f = bv[h].get(k);\n      ret |= f ? T(1)\
    \ << h : 0;\n      k = f ? bv[h].rank1(k) + bv[h].zeros : bv[h].rank0(k);\n  \
    \  }\n    return ret;\n  }\n\n  // k-th (0-indexed) smallest number in { a[i]\
    \ ^ value_xor : i in [l, r) }\n  T kth_smallest(u32 l, u32 r, u32 k, T value_xor\
    \ = 0) const {\n    T res = value_xor;\n    for (int h = B - 1; h >= 0; --h) {\n\
    \      u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n      u32 c0 = r0 - l0;\n\
    \      if ((k < c0) ^ ((value_xor >> h) & 1))\n        l = l0, r = r0;\n     \
    \ else {\n        k -= c0;\n        res ^= (T)1 << h;\n        l += bv[h].zeros\
    \ - l0;\n        r += bv[h].zeros - r0;\n      }\n    }\n    return res;\n  }\n\
    \  // k-th (0-indexed) largest number in { a[i] ^ value_xor : i in [l, r) }\n\
    \  T kth_largest(u32 l, u32 r, u32 k, T value_xor = 0) {\n    return kth_smallest(l,\
    \ r, r - l - k - 1);\n  }\n\n  // count i s.t. (l <= i < r) && (v[i] ^ value_xor\
    \ < upper)\n  int range_freq(int l, int r, T upper, T value_xor = 0) {\n    if\
    \ (upper >= (T(1) << B)) return r - l;\n    int ret = 0;\n    for (int h = B -\
    \ 1; h >= 0; --h) {\n      bool f = (upper >> h) & 1;\n      u32 l0 = bv[h].rank0(l),\
    \ r0 = bv[h].rank0(r);\n      u32 zeros = bv[h].zeros;\n      u32 l1 = l + zeros\
    \ - l0, r1 = r + zeros - r0;\n      if ((value_xor >> h) & 1) {\n        swap(l0,\
    \ l1);\n        swap(r0, r1);\n      }\n      if (f) {\n        ret += r0 - l0;\n\
    \        l += zeros - l0;\n        r += zeros - r0;\n      } else {\n        l\
    \ = l0;\n        r = r0;\n      }\n    }\n    return ret;\n  }\n  int range_freq(int\
    \ l, int r, T lower, T upper, T value_xor = 0) {\n    return range_freq(l, r,\
    \ upper, value_xor) - range_freq(l, r, lower, value_xor);\n  }\n\n  // max v[i]\
    \ s.t. (l <= i < r) && (v[i] ^ value_xor < upper)\n  T prev_value(int l, int r,\
    \ T upper, T value_xor = 0) {\n    int cnt = range_freq(l, r, upper, value_xor);\n\
    \    return cnt == 0 ? T(-1) : kth_smallest(l, r, cnt - 1, value_xor);\n  }\n\n\
    \  // min v[i] s.t. (l <= i < r) && (lower ^ value_xor <= v[i])\n  T next_value(int\
    \ l, int r, T lower, T value_xor = 0) {\n    int cnt = range_freq(l, r, lower,\
    \ value_xor);\n    return cnt == r - l ? T(-1) : kth_smallest(l, r, cnt, value_xor);\n\
    \  }\n};\n\n/**\n * @brief Wavelet Matrix\n * @docs docs/data-structure/wavelet-matrix.md\n\
    \ */\n#line 4 \"data-structure/wavelet-matrix-with-weight.hpp\"\n\n// W: commutative,\
    \ inverse\ntemplate <class T, class W, int B = 30>\nstruct WaveletMatrixWithWeight\
    \ : public WaveletMatrix<T, B> {\n  using Base = WaveletMatrix<T, B>;\n  using\
    \ u32 = uint32_t;\n  using i64 = int64_t;\n  using u64 = uint64_t;\n\n  using\
    \ Base::a;\n  using Base::bv;\n  using Base::n;\n  vector<W> w;\n  vector<vector<W>>\
    \ sum;\n\n  WaveletMatrixWithWeight(u32 _n) : Base(_n), w(_n) {}\n  WaveletMatrixWithWeight(const\
    \ vector<T>& _a, const vector<W>& _w) : Base(_a), w(_w) { build(); }\n\n  void\
    \ set(u32 i, const T& x, const W& v) {\n    assert(x >= 0);\n    a[i] = x;\n \
    \   w[i] = v;\n  }\n\n  void build() {\n    bv.assign(B, n);\n    sum.assign(B\
    \ + 1, vector<W>(n + 1));\n    for (int i = 0; i < n; i++) sum[B][i + 1] = sum[B][i]\
    \ + w[i];\n    vector<T> cur = a, nxt(n);\n    vector<W> wcur = w, wnxt(n);\n\
    \    for (int h = B - 1; h >= 0; --h) {\n      for (int i = 0; i < n; ++i)\n \
    \       if ((cur[i] >> h) & 1) bv[h].set(i);\n      bv[h].build();\n      array<decltype(begin(nxt)),\
    \ 2> it{begin(nxt), begin(nxt) + bv[h].zeros};\n      array<decltype(begin(wnxt)),\
    \ 2> wit{begin(wnxt), begin(wnxt) + bv[h].zeros};\n      for (int i = 0; i < n;\
    \ ++i) {\n        int x = bv[h].get(i);\n        *it[x]++ = cur[i];\n        *wit[x]++\
    \ = wcur[i];\n      }\n      for (int i = 0; i < n; i++) sum[h][i + 1] = sum[h][i]\
    \ + wnxt[i];\n      swap(cur, nxt);\n      swap(wcur, wnxt);\n    }\n  }\n\n \
    \ // count i s.t. (l <= i < r) && (lower <= v[i] ^ value_xor < upper)\n  W range_sum(int\
    \ l, int r, T lower, T upper, T value_xor = 0) {\n    return range_sum_(l, r,\
    \ upper, value_xor) - range_sum_(l, r, lower, value_xor);\n  }\n\n private:\n\
    \  // count i s.t. (l <= i < r) && (v[i] ^ value_xor < upper)\n  W range_sum_(int\
    \ l, int r, T upper, T value_xor = 0) {\n    if (upper >= (T(1) << B)) return\
    \ sum[B][r] - sum[B][l];\n    W ret = 0;\n    for (int h = B - 1; h >= 0; --h)\
    \ {\n      u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n      u32 zeros = bv[h].zeros;\n\
    \      u32 l1 = l + zeros - l0, r1 = r + zeros - r0;\n      if ((value_xor >>\
    \ h) & 1) {\n        swap(l0, l1);\n        swap(r0, r1);\n      }\n      if ((upper\
    \ >> h) & 1) {\n        ret += sum[h][r0] - sum[h][l0];\n        l = l1, r = r1;\n\
    \      } else {\n        l = l0, r = r0;\n      }\n    }\n    return ret;\n  }\n\
    };\n"
  code: "#pragma once\n\n#include \"data-structure/wavelet-matrix.hpp\"\n\n// W: commutative,\
    \ inverse\ntemplate <class T, class W, int B = 30>\nstruct WaveletMatrixWithWeight\
    \ : public WaveletMatrix<T, B> {\n  using Base = WaveletMatrix<T, B>;\n  using\
    \ u32 = uint32_t;\n  using i64 = int64_t;\n  using u64 = uint64_t;\n\n  using\
    \ Base::a;\n  using Base::bv;\n  using Base::n;\n  vector<W> w;\n  vector<vector<W>>\
    \ sum;\n\n  WaveletMatrixWithWeight(u32 _n) : Base(_n), w(_n) {}\n  WaveletMatrixWithWeight(const\
    \ vector<T>& _a, const vector<W>& _w) : Base(_a), w(_w) { build(); }\n\n  void\
    \ set(u32 i, const T& x, const W& v) {\n    assert(x >= 0);\n    a[i] = x;\n \
    \   w[i] = v;\n  }\n\n  void build() {\n    bv.assign(B, n);\n    sum.assign(B\
    \ + 1, vector<W>(n + 1));\n    for (int i = 0; i < n; i++) sum[B][i + 1] = sum[B][i]\
    \ + w[i];\n    vector<T> cur = a, nxt(n);\n    vector<W> wcur = w, wnxt(n);\n\
    \    for (int h = B - 1; h >= 0; --h) {\n      for (int i = 0; i < n; ++i)\n \
    \       if ((cur[i] >> h) & 1) bv[h].set(i);\n      bv[h].build();\n      array<decltype(begin(nxt)),\
    \ 2> it{begin(nxt), begin(nxt) + bv[h].zeros};\n      array<decltype(begin(wnxt)),\
    \ 2> wit{begin(wnxt), begin(wnxt) + bv[h].zeros};\n      for (int i = 0; i < n;\
    \ ++i) {\n        int x = bv[h].get(i);\n        *it[x]++ = cur[i];\n        *wit[x]++\
    \ = wcur[i];\n      }\n      for (int i = 0; i < n; i++) sum[h][i + 1] = sum[h][i]\
    \ + wnxt[i];\n      swap(cur, nxt);\n      swap(wcur, wnxt);\n    }\n  }\n\n \
    \ // count i s.t. (l <= i < r) && (lower <= v[i] ^ value_xor < upper)\n  W range_sum(int\
    \ l, int r, T lower, T upper, T value_xor = 0) {\n    return range_sum_(l, r,\
    \ upper, value_xor) - range_sum_(l, r, lower, value_xor);\n  }\n\n private:\n\
    \  // count i s.t. (l <= i < r) && (v[i] ^ value_xor < upper)\n  W range_sum_(int\
    \ l, int r, T upper, T value_xor = 0) {\n    if (upper >= (T(1) << B)) return\
    \ sum[B][r] - sum[B][l];\n    W ret = 0;\n    for (int h = B - 1; h >= 0; --h)\
    \ {\n      u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n      u32 zeros = bv[h].zeros;\n\
    \      u32 l1 = l + zeros - l0, r1 = r + zeros - r0;\n      if ((value_xor >>\
    \ h) & 1) {\n        swap(l0, l1);\n        swap(r0, r1);\n      }\n      if ((upper\
    \ >> h) & 1) {\n        ret += sum[h][r0] - sum[h][l0];\n        l = l1, r = r1;\n\
    \      } else {\n        l = l0, r = r0;\n      }\n    }\n    return ret;\n  }\n\
    };"
  dependsOn:
  - data-structure/wavelet-matrix.hpp
  - data-structure/bit-vector.hpp
  isVerificationFile: false
  path: data-structure/wavelet-matrix-with-weight.hpp
  requiredBy:
  - verify/data-structure/LC_rectangle_sum.wavelet_matrix.cpp
  timestamp: '2026-06-28 14:52:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/wavelet-matrix-with-weight.hpp
layout: document
redirect_from:
- /library/data-structure/wavelet-matrix-with-weight.hpp
- /library/data-structure/wavelet-matrix-with-weight.hpp.html
title: data-structure/wavelet-matrix-with-weight.hpp
---
