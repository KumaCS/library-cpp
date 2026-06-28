---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/wavelet-matrix-with-segment-tree.hpp
    title: data-structure/wavelet-matrix-with-segment-tree.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/wavelet-matrix-with-weight.hpp
    title: data-structure/wavelet-matrix-with-weight.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/wavelet-matrix.hpp
    title: Wavelet Matrix
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data-structure/LC_point_add_rectangle_sum.wavelet_matrix.test.cpp
    title: verify/data-structure/LC_point_add_rectangle_sum.wavelet_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/data-structure/LC_range_kth_smallest.test.cpp
    title: verify/data-structure/LC_range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/data-structure/LC_rectangle_sum.wavelet_matrix.test.cpp
    title: verify/data-structure/LC_rectangle_sum.wavelet_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/data-structure/LC_static_range_frequency.test.cpp
    title: verify/data-structure/LC_static_range_frequency.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/data-structure/LC_static_range_sum_with_upper_bound.test.cpp
    title: verify/data-structure/LC_static_range_sum_with_upper_bound.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/bit-vector.hpp\"\n\nstruct BitVector {\n\
    \  using i32 = int32_t;\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n\
    \  static constexpr u32 W = 64;\n  inline u32 get(u32 i) const { return u32(block[i\
    \ / W] >> (i % W)) & 1u; }\n  inline void set(u32 i) { block[i / W] |= 1ull <<\
    \ (i % W); }\n\n  vector<u64> block;\n  vector<i32> count;\n  u32 n, zeros;\n\
    \  BitVector() {}\n  BitVector(int _n) : n(_n) {\n    block.resize(n / W + 1,\
    \ 0);\n    count.resize(block.size(), 0);\n  }\n  void build() {\n    for (u32\
    \ i = 1; i < block.size(); i++)\n      count[i] = count[i - 1] + __builtin_popcountll(block[i\
    \ - 1]);\n    zeros = rank0(n);\n  }\n  inline u32 rank0(u32 i) const { return\
    \ i - rank1(i); }\n  inline u32 rank1(u32 i) const { return count[i / W] + __builtin_popcountll(block[i\
    \ / W] & ((1ull << i % W) - 1)); }\n};\n"
  code: "#pragma once\n\nstruct BitVector {\n  using i32 = int32_t;\n  using u32 =\
    \ uint32_t;\n  using u64 = uint64_t;\n\n  static constexpr u32 W = 64;\n  inline\
    \ u32 get(u32 i) const { return u32(block[i / W] >> (i % W)) & 1u; }\n  inline\
    \ void set(u32 i) { block[i / W] |= 1ull << (i % W); }\n\n  vector<u64> block;\n\
    \  vector<i32> count;\n  u32 n, zeros;\n  BitVector() {}\n  BitVector(int _n)\
    \ : n(_n) {\n    block.resize(n / W + 1, 0);\n    count.resize(block.size(), 0);\n\
    \  }\n  void build() {\n    for (u32 i = 1; i < block.size(); i++)\n      count[i]\
    \ = count[i - 1] + __builtin_popcountll(block[i - 1]);\n    zeros = rank0(n);\n\
    \  }\n  inline u32 rank0(u32 i) const { return i - rank1(i); }\n  inline u32 rank1(u32\
    \ i) const { return count[i / W] + __builtin_popcountll(block[i / W] & ((1ull\
    \ << i % W) - 1)); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/bit-vector.hpp
  requiredBy:
  - data-structure/wavelet-matrix-with-weight.hpp
  - data-structure/wavelet-matrix.hpp
  - data-structure/wavelet-matrix-with-segment-tree.hpp
  timestamp: '2026-06-28 14:52:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data-structure/LC_rectangle_sum.wavelet_matrix.test.cpp
  - verify/data-structure/LC_range_kth_smallest.test.cpp
  - verify/data-structure/LC_static_range_sum_with_upper_bound.test.cpp
  - verify/data-structure/LC_static_range_frequency.test.cpp
  - verify/data-structure/LC_point_add_rectangle_sum.wavelet_matrix.test.cpp
documentation_of: data-structure/bit-vector.hpp
layout: document
redirect_from:
- /library/data-structure/bit-vector.hpp
- /library/data-structure/bit-vector.hpp.html
title: data-structure/bit-vector.hpp
---
