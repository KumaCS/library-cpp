#pragma once
#include "segment-tree/lazy-segment-tree.hpp"

namespace LazySegmentTreeUtil {
template <class T>
T Zero() { return T{}; }
template <class T>
T One() { return T{1}; }
template <class T, T e>
T Const() { return e; }
template <class T>
T Add(T x, T y) { return x + y; }
template <class T>
T Mul(T x, T y) { return x * y; }
template <class T>
T Max(T x, T y) { return x > y ? x : y; }
template <class T>
T Min(T x, T y) { return x < y ? x : y; }
template <class T>
using P = pair<T, T>;
template <class T>
P<T> PAdd(P<T> x, P<T> y) { return P<T>{x.first + y.first, x.second + y.second}; }
template <class T>
P<T> FPAdd(T f, P<T> x) { return P<T>{x.first, x.second + x.first * f}; }
template <class T>
P<T> PZero() { return P<T>{T{}, T{}}; }
template <class T>
vector<P<T>> InitPair(const vector<T>& a) {
  vector<P<T>> v(a.size());
  for (int i = 0; i < (int)v.size(); i++) v[i] = P<T>{1, a[i]};
  return v;
}
template <class T>
struct LazySegmentTreeAddSum : LazySegmentTree<P<T>, PAdd<T>, PZero<T>, T, FPAdd<T>, Add<T>, Zero<T>> {
  using base = LazySegmentTree<P<T>, PAdd<T>, PZero<T>, T, FPAdd<T>, Add<T>, Zero<T>>;
  LazySegmentTreeAddSum(int n) : base(vector<P<T>>(n, PZero<T>())) {}
  LazySegmentTreeAddSum(const vector<T>& a) : base(InitPair(a)) {}
};
template <class T>
struct LazySegmentTreeMulSum : LazySegmentTree<T, Add<T>, Zero<T>, T, Mul<T>, Mul<T>, One<T>> {
  using base = LazySegmentTree<T, Add<T>, Zero<T>, T, Mul<T>, Mul<T>, One<T>>;
  LazySegmentTreeMulSum(int n) : base(vector<T>(n, Zero<T>())) {}
  LazySegmentTreeMulSum(const vector<T>& a) : base(a) {}
};
};  // namespace LazySegmentTreeUtil
using LazySegmentTreeUtil::LazySegmentTreeAddSum;
using LazySegmentTreeUtil::LazySegmentTreeMulSum;
/**
 * @brief よく使う Lazy Segment Tree
 * @docs docs/segment-tree/lazy-segment-tree-util.md
 */