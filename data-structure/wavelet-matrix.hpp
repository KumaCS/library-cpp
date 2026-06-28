#pragma once

#include "data-structure/bit-vector.hpp"

template <class T, int B = 30>
struct WaveletMatrix {
  using u32 = uint32_t;
  using i64 = int64_t;
  using u64 = uint64_t;

  int n;
  vector<T> a;
  vector<BitVector> bv;

  WaveletMatrix(u32 _n) : n(max<u32>(_n, 1)), a(n) {}
  WaveletMatrix(const vector<T>& _a) : n(_a.size()), a(_a) { build(); }

  void set(u32 i, const T& x) {
    assert(x >= 0);
    a[i] = x;
  }

  void build() {
    bv.assign(B, n);
    vector<T> cur = a, nxt(n);
    for (int h = B - 1; h >= 0; --h) {
      for (int i = 0; i < n; ++i)
        if ((cur[i] >> h) & 1) bv[h].set(i);
      bv[h].build();
      array<decltype(begin(nxt)), 2> it{begin(nxt), begin(nxt) + bv[h].zeros};
      for (int i = 0; i < n; ++i) *it[bv[h].get(i)]++ = cur[i];
      swap(cur, nxt);
    }
  }

  inline pair<u32, u32> succ0(int l, int r, int h) const {
    return make_pair(bv[h].rank0(l), bv[h].rank0(r));
  }
  inline pair<u32, u32> succ1(int l, int r, int h) const {
    u32 l0 = bv[h].rank0(l);
    u32 r0 = bv[h].rank0(r);
    u32 zeros = bv[h].zeros;
    return make_pair(l + zeros - l0, r + zeros - r0);
  }

  // return a[k]
  T access(u32 k) const {
    T ret = 0;
    for (int h = B - 1; h >= 0; --h) {
      u32 f = bv[h].get(k);
      ret |= f ? T(1) << h : 0;
      k = f ? bv[h].rank1(k) + bv[h].zeros : bv[h].rank0(k);
    }
    return ret;
  }

  // k-th (0-indexed) smallest number in { a[i] ^ value_xor : i in [l, r) }
  T kth_smallest(u32 l, u32 r, u32 k, T value_xor = 0) const {
    T res = value_xor;
    for (int h = B - 1; h >= 0; --h) {
      u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);
      u32 c0 = r0 - l0;
      if ((k < c0) ^ ((value_xor >> h) & 1))
        l = l0, r = r0;
      else {
        k -= c0;
        res ^= (T)1 << h;
        l += bv[h].zeros - l0;
        r += bv[h].zeros - r0;
      }
    }
    return res;
  }
  // k-th (0-indexed) largest number in { a[i] ^ value_xor : i in [l, r) }
  T kth_largest(u32 l, u32 r, u32 k, T value_xor = 0) {
    return kth_smallest(l, r, r - l - k - 1);
  }

  // count i s.t. (l <= i < r) && (v[i] ^ value_xor < upper)
  int range_freq(int l, int r, T upper, T value_xor = 0) {
    if (upper >= (T(1) << B)) return r - l;
    int ret = 0;
    for (int h = B - 1; h >= 0; --h) {
      bool f = (upper >> h) & 1;
      u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);
      u32 zeros = bv[h].zeros;
      u32 l1 = l + zeros - l0, r1 = r + zeros - r0;
      if ((value_xor >> h) & 1) {
        swap(l0, l1);
        swap(r0, r1);
      }
      if (f) {
        ret += r0 - l0;
        l += zeros - l0;
        r += zeros - r0;
      } else {
        l = l0;
        r = r0;
      }
    }
    return ret;
  }
  int range_freq(int l, int r, T lower, T upper, T value_xor = 0) {
    return range_freq(l, r, upper, value_xor) - range_freq(l, r, lower, value_xor);
  }

  // max v[i] s.t. (l <= i < r) && (v[i] ^ value_xor < upper)
  T prev_value(int l, int r, T upper, T value_xor = 0) {
    int cnt = range_freq(l, r, upper, value_xor);
    return cnt == 0 ? T(-1) : kth_smallest(l, r, cnt - 1, value_xor);
  }

  // min v[i] s.t. (l <= i < r) && (lower ^ value_xor <= v[i])
  T next_value(int l, int r, T lower, T value_xor = 0) {
    int cnt = range_freq(l, r, lower, value_xor);
    return cnt == r - l ? T(-1) : kth_smallest(l, r, cnt, value_xor);
  }
};

/**
 * @brief Wavelet Matrix
 * @docs docs/data-structure/wavelet-matrix.md
 */