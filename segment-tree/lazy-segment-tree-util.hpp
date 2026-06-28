#pragma once
#include "segment-tree/lazy-segment-tree.hpp"

namespace LazySegmentTreeUtil {
template <class T>
using P = pair<T, T>;

template <class T>
struct PairAddMonoid {
  using value_type = P<T>;
  static value_type op(value_type x, value_type y) { return {x.first + y.first, x.second + y.second}; }
  static value_type e() { return {T{}, T{}}; }
};

template <class T>
struct AddSumAction {
  using value_monoid = PairAddMonoid<T>;
  using operator_monoid = AddMonoid<T>;
  static P<T> mapping(T f, P<T> x) { return {x.first, x.second + x.first * f}; }
};

template <class T>
struct MulSumAction {
  using value_monoid = AddMonoid<T>;
  using operator_monoid = MulMonoid<T>;
  static T mapping(T f, T x) { return f * x; }
};

template <class T>
vector<P<T>> InitPair(const vector<T>& a) {
  vector<P<T>> v(a.size());
  for (int i = 0; i < (int)v.size(); i++) v[i] = P<T>{1, a[i]};
  return v;
}
template <class T>
struct LazySegmentTreeAddSum : LazySegmentTree<AddSumAction<T>> {
  using base = LazySegmentTree<AddSumAction<T>>;
  LazySegmentTreeAddSum(int n) : base(vector<P<T>>(n, PairAddMonoid<T>::e())) {}
  LazySegmentTreeAddSum(const vector<T>& a) : base(InitPair(a)) {}
  void set(int p, T v) { base::set(p, P<T>{1, v}); }
  T get(int p) { return base::get(p).second; }
  T prod(int l, int r) { return base::prod(l, r).second; }
  void apply(int l, int r, T v) { base::apply(l, r, v); }
};
template <class T>
struct LazySegmentTreeMulSum : LazySegmentTree<MulSumAction<T>> {
  using base = LazySegmentTree<MulSumAction<T>>;
  LazySegmentTreeMulSum(int n) : base(n) {}
  LazySegmentTreeMulSum(const vector<T>& a) : base(a) {}
};
};  // namespace LazySegmentTreeUtil
using LazySegmentTreeUtil::LazySegmentTreeAddSum;
using LazySegmentTreeUtil::LazySegmentTreeMulSum;
/**
 * @brief よく使う Lazy Segment Tree
 * @docs docs/segment-tree/lazy-segment-tree-util.md
 */
