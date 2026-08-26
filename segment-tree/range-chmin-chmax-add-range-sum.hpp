#pragma once

#include "segment-tree/segment-tree-beats.hpp"

namespace RangeChminChmaxAddRangeSumImpl {
template <class T>
struct S {
  static_assert(numeric_limits<T>::is_integer && numeric_limits<T>::is_signed);
  static constexpr T INF = numeric_limits<T>::max() / 4;
  T lo, hi, lo2, hi2, sum;
  int sz, nlo, nhi;
  bool fail;
  S() : lo(INF), hi(-INF), lo2(INF), hi2(-INF), sum(0), sz(0), nlo(0), nhi(0), fail(false) {}
  S(T x, int sz_) : lo(x), hi(x), lo2(INF), hi2(-INF), sum(x * sz_), sz(sz_), nlo(sz_), nhi(sz_), fail(false) {}
};
template <class T>
T second_lowest(T a, T a2, T b, T b2) {
  return a == b ? min(a2, b2) : a2 <= b ? a2 : b2 <= a ? b2 : max(a, b);
}
template <class T>
T second_highest(T a, T a2, T b, T b2) {
  return a == b ? max(a2, b2) : a2 >= b ? a2 : b2 >= a ? b2 : min(a, b);
}
template <class T>
struct ValueMonoid {
  using value_type = S<T>;
  static S<T> op(S<T> l, S<T> r) {
    S<T> x;
    x.lo = min(l.lo, r.lo), x.hi = max(l.hi, r.hi);
    x.lo2 = second_lowest(l.lo, l.lo2, r.lo, r.lo2);
    x.hi2 = second_highest(l.hi, l.hi2, r.hi, r.hi2);
    x.sum = l.sum + r.sum, x.sz = l.sz + r.sz;
    x.nlo = l.nlo * (l.lo <= r.lo) + r.nlo * (r.lo <= l.lo);
    x.nhi = l.nhi * (l.hi >= r.hi) + r.nhi * (r.hi >= l.hi);
    return x;
  }
  static S<T> e() { return S<T>(); }
};
template <class T>
struct F {
  T lb, ub, bias;
  F(T lb_ = -S<T>::INF, T ub_ = S<T>::INF, T bias_ = 0) : lb(lb_), ub(ub_), bias(bias_) {}
  static F chmin(T x) { return F(-S<T>::INF, x, 0); }
  static F chmax(T x) { return F(x, S<T>::INF, 0); }
  static F add(T x) { return F(-S<T>::INF, S<T>::INF, x); }
};
template <class T>
struct OperatorMonoid {
  using value_type = F<T>;
  static F<T> op(F<T> f, F<T> g) {
    F<T> h;
    h.lb = max(min(g.lb + g.bias, f.ub), f.lb) - g.bias;
    h.ub = min(max(g.ub + g.bias, f.lb), f.ub) - g.bias;
    h.bias = g.bias + f.bias;
    return h;
  }
  static F<T> e() { return F<T>(); }
};
template <class T>
struct Action {
  using value_monoid = ValueMonoid<T>;
  using operator_monoid = OperatorMonoid<T>;
  static S<T> mapping(F<T> f, S<T> x) {
    if (x.sz == 0) return S<T>();
    if (x.lo == x.hi || f.lb == f.ub || f.lb >= x.hi || f.ub <= x.lo) {
      return S<T>(min(max(x.lo, f.lb), f.ub) + f.bias, x.sz);
    }
    if (x.lo2 == x.hi) {
      x.lo = x.hi2 = max(x.lo, f.lb) + f.bias;
      x.hi = x.lo2 = min(x.hi, f.ub) + f.bias;
      x.sum = x.lo * x.nlo + x.hi * x.nhi;
      return x;
    }
    if (f.lb < x.lo2 && f.ub > x.hi2) {
      T next_lo = max(x.lo, f.lb), next_hi = min(x.hi, f.ub);
      x.sum += (next_lo - x.lo) * x.nlo - (x.hi - next_hi) * x.nhi + f.bias * x.sz;
      x.lo = next_lo + f.bias, x.hi = next_hi + f.bias;
      x.lo2 += f.bias, x.hi2 += f.bias;
      return x;
    }
    x.fail = true;
    return x;
  }
};
template <class T>
vector<S<T>> init(const vector<T>& a) {
  vector<S<T>> v;
  v.reserve(a.size());
  for (T x : a) v.emplace_back(x, 1);
  return v;
}
}  // namespace RangeChminChmaxAddRangeSumImpl

template <class T>
struct RangeChminChmaxAddRangeSum : SegmentTreeBeats<RangeChminChmaxAddRangeSumImpl::Action<T>> {
  using Impl = RangeChminChmaxAddRangeSumImpl::Action<T>;
  using S = RangeChminChmaxAddRangeSumImpl::S<T>;
  using F = RangeChminChmaxAddRangeSumImpl::F<T>;
  using base = SegmentTreeBeats<Impl>;
  RangeChminChmaxAddRangeSum() : base() {}
  explicit RangeChminChmaxAddRangeSum(int n) : base(vector<S>(n, S(T(0), 1))) {}
  explicit RangeChminChmaxAddRangeSum(const vector<T>& a) : base(RangeChminChmaxAddRangeSumImpl::init(a)) {}
  void set(int p, T x) { base::set(p, S(x, 1)); }
  T get(int p) { return base::get(p).sum; }
  void chmin(int l, int r, T x) { base::apply(l, r, F::chmin(x)); }
  void chmax(int l, int r, T x) { base::apply(l, r, F::chmax(x)); }
  void add(int l, int r, T x) { base::apply(l, r, F::add(x)); }
  T sum(int l, int r) { return base::prod(l, r).sum; }
  T prod(int l, int r) { return sum(l, r); }
  T all_sum() { return base::all_prod().sum; }
  T all_prod() { return all_sum(); }
};

/**
 * @brief Range Chmin Chmax Add Range Sum
 * @docs docs/segment-tree/range-chmin-chmax-add-range-sum.md
 */
