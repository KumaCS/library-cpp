---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: data-structure/bit-vector.hpp
    title: data-structure/bit-vector.hpp
  - icon: ':warning:'
    path: data-structure/wavelet-matrix.hpp
    title: Wavelet Matrix
  - icon: ':heavy_check_mark:'
    path: segment-tree/segment-tree.hpp
    title: Segment Tree
  _extendedRequiredBy:
  - icon: ':warning:'
    path: verify/data-structure/LC_point_add_rectangle_sum.wavelet_matrix.cpp
    title: verify/data-structure/LC_point_add_rectangle_sum.wavelet_matrix.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/wavelet-matrix-with-segment-tree.hpp\"\n\n\
    #line 2 \"data-structure/wavelet-matrix.hpp\"\n\n#line 2 \"data-structure/bit-vector.hpp\"\
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
    \ */\n#line 2 \"segment-tree/segment-tree.hpp\"\n\ntemplate <class T, T (*op)(T,\
    \ T), T (*e)()>\nstruct SegmentTree {\n private:\n  int _n, size, log;\n  vector<T>\
    \ d;\n  void update(int p) { d[p] = op(d[2 * p], d[2 * p + 1]); }\n\n public:\n\
    \  SegmentTree() : SegmentTree(0) {}\n  explicit SegmentTree(int sz) : SegmentTree(vector<T>(sz,\
    \ e())) {}\n  explicit SegmentTree(const vector<T>& v) : _n(v.size()) {\n    size\
    \ = 1, log = 0;\n    while (size < _n) size <<= 1, log++;\n    d.assign(2 * size,\
    \ e());\n    for (int i = 0; i < v.size(); i++) d[size + i] = v[i];\n    for (int\
    \ i = size - 1; i > 0; i--) update(i);\n  }\n  void clear() { fill(d.begin(),\
    \ d.end(), e()); }\n\n  void set_without_update(int p, T v) { d[p + size] = v;\
    \ }\n  void all_update() {\n    for (int i = size - 1; i > 0; i--) update(i);\n\
    \  }\n  T get(int p) {\n    assert(0 <= p && p <= _n);\n    return d[p + size];\n\
    \  }\n  void set(int p, T v) {\n    assert(0 <= p && p <= _n);\n    p += size;\n\
    \    d[p] = v;\n    for (int i = 1; i <= log; i++) update(p >> i);\n  }\n  void\
    \ apply(int p, T v) {\n    assert(0 <= p && p <= _n);\n    p += size;\n    d[p]\
    \ = op(d[p], v);\n    for (int i = 1; i <= log; i++) update(p >> i);\n  }\n  T\
    \ all_prod() { return d[1]; }\n  T prod(int l, int r) {\n    if (l >= r) return\
    \ e();\n    assert(0 <= l && l <= r && r <= _n);\n    T sl = e(), sr = e();\n\
    \    l += size, r += size;\n    while (l < r) {\n      if ((l & 1) != 0) sl =\
    \ op(sl, d[l++]);\n      if ((r & 1) != 0) sr = op(d[--r], sr);\n      l >>= 1,\
    \ r >>= 1;\n    }\n    return op(sl, sr);\n  }\n\n  template <bool (*f)(T)>\n\
    \  int max_right(int l) const {\n    return max_right(l, [](T x) { return f(x);\
    \ });\n  }\n  template <class F>\n  int max_right(int l, F f) const {\n    assert(0\
    \ <= l && l <= size);\n    assert(f(e()));\n    if (l == _n) return _n;\n    l\
    \ += size;\n    T s = e();\n    do {\n      while (l % 2 == 0) l >>= 1;\n    \
    \  if (!f(op(s, d[l]))) {\n        while (l < size) {\n          l <<= 1;\n  \
    \        if (f(op(s, d[l]))) s = op(s, d[l++]);\n        }\n        return l -\
    \ size;\n      }\n      s = op(s, d[l++]);\n    } while ((l & -l) != l);\n   \
    \ return _n;\n  }\n\n  template <bool (*f)(T)>\n  int min_left(int r) const {\n\
    \    return min_left(r, [](T x) { return f(x); });\n  }\n  template <class F>\n\
    \  int min_left(int r, F f) const {\n    assert(0 <= r && r <= _n);\n    assert(f(e()));\n\
    \    if (r == 0) return 0;\n    r += size;\n    T s = e();\n    do {\n      r--;\n\
    \      while (r > 1 && (r % 2)) r >>= 1;\n      if (!f(op(d[r], s))) {\n     \
    \   while (r < size) {\n          r <<= 1, r++;\n          if (f(op(d[r], s)))\
    \ s = op(d[r--], s);\n        }\n        return r + 1 - size;\n      }\n     \
    \ s = op(d[r], s);\n    } while ((r & -r) != r);\n    return 0;\n  }\n};\n\n/**\n\
    \ * @brief Segment Tree\n * @docs docs/segment-tree/segment-tree.md\n */\n#line\
    \ 5 \"data-structure/wavelet-matrix-with-segment-tree.hpp\"\n\n// S: commutative\n\
    template <class T, class S, S (*op)(S, S), S (*e)(), int B = 30>\nstruct WaveletMatrixWithSegmentTree\
    \ : public WaveletMatrix<T, B> {\n  using Base = WaveletMatrix<T, B>;\n  using\
    \ u32 = uint32_t;\n  using i64 = int64_t;\n  using u64 = uint64_t;\n\n  using\
    \ Base::a;\n  using Base::bv;\n  using Base::n;\n  vector<S> w;\n  vector<SegmentTree<S,\
    \ op, e>> seg;\n\n  WaveletMatrixWithSegmentTree(u32 _n) : Base(_n), w(_n) {}\n\
    \  WaveletMatrixWithSegmentTree(const vector<T>& _a, const vector<S>& _w) : Base(_a),\
    \ w(_w) { build(); }\n\n  void set(u32 i, const T& x, const S& v) {\n    assert(x\
    \ >= 0);\n    a[i] = x;\n    w[i] = v;\n  }\n\n  void build() {\n    bv.assign(B,\
    \ n);\n    seg.resize(B + 1);\n    seg[B] = SegmentTree<S, op, e>(w);\n    vector<T>\
    \ cur = a, nxt(n);\n    vector<S> wcur = w, wnxt(n);\n    for (int h = B - 1;\
    \ h >= 0; --h) {\n      for (int i = 0; i < n; ++i)\n        if ((cur[i] >> h)\
    \ & 1) bv[h].set(i);\n      bv[h].build();\n      array<decltype(begin(nxt)),\
    \ 2> it{begin(nxt), begin(nxt) + bv[h].zeros};\n      array<decltype(begin(wnxt)),\
    \ 2> wit{begin(wnxt), begin(wnxt) + bv[h].zeros};\n      for (int i = 0; i < n;\
    \ ++i) {\n        int x = bv[h].get(i);\n        *it[x]++ = cur[i];\n        *wit[x]++\
    \ = wcur[i];\n      }\n      seg[h] = SegmentTree<S, op, e>(wnxt);\n      swap(cur,\
    \ nxt);\n      swap(wcur, wnxt);\n    }\n  }\n\n  void update(u32 k, const S&\
    \ v) {\n    seg[B].set(k, v);\n    for (int h = B - 1; h >= 0; --h) {\n      u32\
    \ f = bv[h].get(k);\n      k = f ? bv[h].rank1(k) + bv[h].zeros : bv[h].rank0(k);\n\
    \      seg[h].set(k, v);\n    }\n  }\n  void apply(u32 k, const S& v) {\n    seg[B].apply(k,\
    \ v);\n    for (int h = B - 1; h >= 0; --h) {\n      u32 f = bv[h].get(k);\n \
    \     k = f ? bv[h].rank1(k) + bv[h].zeros : bv[h].rank0(k);\n      seg[h].apply(k,\
    \ v);\n    }\n  }\n\n  // count i s.t. (l <= i < r) && (lower <= v[i] ^ value_xor\
    \ < upper)\n  S range_sum(int l, int r, T lower, T upper, T value_xor = 0) {\n\
    \    if (lower >= upper) return e();\n    return range_sum_(B - 1, l, r, T(0),\
    \ T(1) << B, lower, upper, value_xor);\n  }\n\n private:\n  S range_sum_(int h,\
    \ int l, int r, T vl, T vr, T lower, T upper, T value_xor) {\n    if (r <= l)\
    \ return e();\n    if (vr <= lower || upper <= vl) return e();\n    if (lower\
    \ <= vl && vr <= upper) return seg[h + 1].prod(l, r);\n\n    u32 l0 = bv[h].rank0(l),\
    \ r0 = bv[h].rank0(r);\n    u32 zeros = bv[h].zeros;\n    u32 l1 = l + zeros -\
    \ l0, r1 = r + zeros - r0;\n    if ((value_xor >> h) & 1) {\n      swap(l0, l1);\n\
    \      swap(r0, r1);\n    }\n\n    T vm = (vl + vr) >> 1;\n    return op(range_sum_(h\
    \ - 1, l0, r0, vl, vm, lower, upper, value_xor),\n              range_sum_(h -\
    \ 1, l1, r1, vm, vr, lower, upper, value_xor));\n  }\n};\n"
  code: "#pragma once\n\n#include \"data-structure/wavelet-matrix.hpp\"\n#include\
    \ \"segment-tree/segment-tree.hpp\"\n\n// S: commutative\ntemplate <class T, class\
    \ S, S (*op)(S, S), S (*e)(), int B = 30>\nstruct WaveletMatrixWithSegmentTree\
    \ : public WaveletMatrix<T, B> {\n  using Base = WaveletMatrix<T, B>;\n  using\
    \ u32 = uint32_t;\n  using i64 = int64_t;\n  using u64 = uint64_t;\n\n  using\
    \ Base::a;\n  using Base::bv;\n  using Base::n;\n  vector<S> w;\n  vector<SegmentTree<S,\
    \ op, e>> seg;\n\n  WaveletMatrixWithSegmentTree(u32 _n) : Base(_n), w(_n) {}\n\
    \  WaveletMatrixWithSegmentTree(const vector<T>& _a, const vector<S>& _w) : Base(_a),\
    \ w(_w) { build(); }\n\n  void set(u32 i, const T& x, const S& v) {\n    assert(x\
    \ >= 0);\n    a[i] = x;\n    w[i] = v;\n  }\n\n  void build() {\n    bv.assign(B,\
    \ n);\n    seg.resize(B + 1);\n    seg[B] = SegmentTree<S, op, e>(w);\n    vector<T>\
    \ cur = a, nxt(n);\n    vector<S> wcur = w, wnxt(n);\n    for (int h = B - 1;\
    \ h >= 0; --h) {\n      for (int i = 0; i < n; ++i)\n        if ((cur[i] >> h)\
    \ & 1) bv[h].set(i);\n      bv[h].build();\n      array<decltype(begin(nxt)),\
    \ 2> it{begin(nxt), begin(nxt) + bv[h].zeros};\n      array<decltype(begin(wnxt)),\
    \ 2> wit{begin(wnxt), begin(wnxt) + bv[h].zeros};\n      for (int i = 0; i < n;\
    \ ++i) {\n        int x = bv[h].get(i);\n        *it[x]++ = cur[i];\n        *wit[x]++\
    \ = wcur[i];\n      }\n      seg[h] = SegmentTree<S, op, e>(wnxt);\n      swap(cur,\
    \ nxt);\n      swap(wcur, wnxt);\n    }\n  }\n\n  void update(u32 k, const S&\
    \ v) {\n    seg[B].set(k, v);\n    for (int h = B - 1; h >= 0; --h) {\n      u32\
    \ f = bv[h].get(k);\n      k = f ? bv[h].rank1(k) + bv[h].zeros : bv[h].rank0(k);\n\
    \      seg[h].set(k, v);\n    }\n  }\n  void apply(u32 k, const S& v) {\n    seg[B].apply(k,\
    \ v);\n    for (int h = B - 1; h >= 0; --h) {\n      u32 f = bv[h].get(k);\n \
    \     k = f ? bv[h].rank1(k) + bv[h].zeros : bv[h].rank0(k);\n      seg[h].apply(k,\
    \ v);\n    }\n  }\n\n  // count i s.t. (l <= i < r) && (lower <= v[i] ^ value_xor\
    \ < upper)\n  S range_sum(int l, int r, T lower, T upper, T value_xor = 0) {\n\
    \    if (lower >= upper) return e();\n    return range_sum_(B - 1, l, r, T(0),\
    \ T(1) << B, lower, upper, value_xor);\n  }\n\n private:\n  S range_sum_(int h,\
    \ int l, int r, T vl, T vr, T lower, T upper, T value_xor) {\n    if (r <= l)\
    \ return e();\n    if (vr <= lower || upper <= vl) return e();\n    if (lower\
    \ <= vl && vr <= upper) return seg[h + 1].prod(l, r);\n\n    u32 l0 = bv[h].rank0(l),\
    \ r0 = bv[h].rank0(r);\n    u32 zeros = bv[h].zeros;\n    u32 l1 = l + zeros -\
    \ l0, r1 = r + zeros - r0;\n    if ((value_xor >> h) & 1) {\n      swap(l0, l1);\n\
    \      swap(r0, r1);\n    }\n\n    T vm = (vl + vr) >> 1;\n    return op(range_sum_(h\
    \ - 1, l0, r0, vl, vm, lower, upper, value_xor),\n              range_sum_(h -\
    \ 1, l1, r1, vm, vr, lower, upper, value_xor));\n  }\n};"
  dependsOn:
  - data-structure/wavelet-matrix.hpp
  - data-structure/bit-vector.hpp
  - segment-tree/segment-tree.hpp
  isVerificationFile: false
  path: data-structure/wavelet-matrix-with-segment-tree.hpp
  requiredBy:
  - verify/data-structure/LC_point_add_rectangle_sum.wavelet_matrix.cpp
  timestamp: '2026-06-28 14:52:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/wavelet-matrix-with-segment-tree.hpp
layout: document
redirect_from:
- /library/data-structure/wavelet-matrix-with-segment-tree.hpp
- /library/data-structure/wavelet-matrix-with-segment-tree.hpp.html
title: data-structure/wavelet-matrix-with-segment-tree.hpp
---
