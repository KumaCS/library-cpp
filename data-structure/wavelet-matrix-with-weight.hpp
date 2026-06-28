#pragma once

#include "data-structure/wavelet-matrix.hpp"

// W: commutative, inverse
template <class T, class W, int B = 30>
struct WaveletMatrixWithWeight : public WaveletMatrix<T, B> {
  using Base = WaveletMatrix<T, B>;
  using u32 = uint32_t;
  using i64 = int64_t;
  using u64 = uint64_t;

  using Base::a;
  using Base::bv;
  using Base::n;
  vector<W> w;
  vector<vector<W>> sum;

  WaveletMatrixWithWeight(u32 _n) : Base(_n), w(_n) {}
  WaveletMatrixWithWeight(const vector<T>& _a, const vector<W>& _w) : Base(_a), w(_w) { build(); }

  void set(u32 i, const T& x, const W& v) {
    assert(x >= 0);
    a[i] = x;
    w[i] = v;
  }

  void build() {
    bv.assign(B, n);
    sum.assign(B + 1, vector<W>(n + 1));
    for (int i = 0; i < n; i++) sum[B][i + 1] = sum[B][i] + w[i];
    vector<T> cur = a, nxt(n);
    vector<W> wcur = w, wnxt(n);
    for (int h = B - 1; h >= 0; --h) {
      for (int i = 0; i < n; ++i)
        if ((cur[i] >> h) & 1) bv[h].set(i);
      bv[h].build();
      array<decltype(begin(nxt)), 2> it{begin(nxt), begin(nxt) + bv[h].zeros};
      array<decltype(begin(wnxt)), 2> wit{begin(wnxt), begin(wnxt) + bv[h].zeros};
      for (int i = 0; i < n; ++i) {
        int x = bv[h].get(i);
        *it[x]++ = cur[i];
        *wit[x]++ = wcur[i];
      }
      for (int i = 0; i < n; i++) sum[h][i + 1] = sum[h][i] + wnxt[i];
      swap(cur, nxt);
      swap(wcur, wnxt);
    }
  }

  // count i s.t. (l <= i < r) && (lower <= v[i] ^ value_xor < upper)
  W range_sum(int l, int r, T lower, T upper, T value_xor = 0) {
    return range_sum_(l, r, upper, value_xor) - range_sum_(l, r, lower, value_xor);
  }

 private:
  // count i s.t. (l <= i < r) && (v[i] ^ value_xor < upper)
  W range_sum_(int l, int r, T upper, T value_xor = 0) {
    if (upper >= (T(1) << B)) return sum[B][r] - sum[B][l];
    W ret = 0;
    for (int h = B - 1; h >= 0; --h) {
      u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);
      u32 zeros = bv[h].zeros;
      u32 l1 = l + zeros - l0, r1 = r + zeros - r0;
      if ((value_xor >> h) & 1) {
        swap(l0, l1);
        swap(r0, r1);
      }
      if ((upper >> h) & 1) {
        ret += sum[h][r0] - sum[h][l0];
        l = l1, r = r1;
      } else {
        l = l0, r = r0;
      }
    }
    return ret;
  }
};