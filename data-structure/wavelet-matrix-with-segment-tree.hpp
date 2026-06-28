#pragma once

#include "data-structure/wavelet-matrix.hpp"
#include "segment-tree/segment-tree.hpp"

// M: commutative monoid
template <class T, class M, int B = 30>
struct WaveletMatrixWithSegmentTree : public WaveletMatrix<T, B> {
  using Base = WaveletMatrix<T, B>;
  using S = typename M::value_type;
  using u32 = uint32_t;
  using i64 = int64_t;
  using u64 = uint64_t;

  using Base::a;
  using Base::bv;
  using Base::n;
  vector<S> w;
  vector<SegmentTree<M>> seg;

  WaveletMatrixWithSegmentTree(u32 _n) : Base(_n), w(_n) {}
  WaveletMatrixWithSegmentTree(const vector<T>& _a, const vector<S>& _w) : Base(_a), w(_w) { build(); }

  void set(u32 i, const T& x, const S& v) {
    assert(x >= 0);
    a[i] = x;
    w[i] = v;
  }

  void build() {
    bv.assign(B, n);
    seg.resize(B + 1);
    seg[B] = SegmentTree<M>(w);
    vector<T> cur = a, nxt(n);
    vector<S> wcur = w, wnxt(n);
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
      seg[h] = SegmentTree<M>(wnxt);
      swap(cur, nxt);
      swap(wcur, wnxt);
    }
  }

  void update(u32 k, const S& v) {
    seg[B].set(k, v);
    for (int h = B - 1; h >= 0; --h) {
      u32 f = bv[h].get(k);
      k = f ? bv[h].rank1(k) + bv[h].zeros : bv[h].rank0(k);
      seg[h].set(k, v);
    }
  }
  void apply(u32 k, const S& v) {
    seg[B].apply(k, v);
    for (int h = B - 1; h >= 0; --h) {
      u32 f = bv[h].get(k);
      k = f ? bv[h].rank1(k) + bv[h].zeros : bv[h].rank0(k);
      seg[h].apply(k, v);
    }
  }

  // count i s.t. (l <= i < r) && (lower <= v[i] ^ value_xor < upper)
  S range_sum(int l, int r, T lower, T upper, T value_xor = 0) {
    if (lower >= upper) return M::e();
    return range_sum_(B - 1, l, r, T(0), T(1) << B, lower, upper, value_xor);
  }

 private:
  S range_sum_(int h, int l, int r, T vl, T vr, T lower, T upper, T value_xor) {
    if (r <= l) return M::e();
    if (vr <= lower || upper <= vl) return M::e();
    if (lower <= vl && vr <= upper) return seg[h + 1].prod(l, r);

    u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);
    u32 zeros = bv[h].zeros;
    u32 l1 = l + zeros - l0, r1 = r + zeros - r0;
    if ((value_xor >> h) & 1) {
      swap(l0, l1);
      swap(r0, r1);
    }

    T vm = (vl + vr) >> 1;
    return M::op(range_sum_(h - 1, l0, r0, vl, vm, lower, upper, value_xor),
                 range_sum_(h - 1, l1, r1, vm, vr, lower, upper, value_xor));
  }
};
