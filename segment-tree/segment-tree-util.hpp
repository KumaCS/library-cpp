#pragma once
#include "segment-tree/segment-tree.hpp"

namespace SegmentTreeUtil {
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
struct SegmentTreeSum : SegmentTree<T, Add<T>, Zero<T>> {
  using base = SegmentTree<T, Add<T>, Zero<T>>;
  SegmentTreeSum(const vector<T>& a) : base(a) {}
};
template <class T>
struct SegmentTreeProd : SegmentTree<T, Mul<T>, One<T>> {
  using base = SegmentTree<T, Mul<T>, One<T>>;
  SegmentTreeProd(const vector<T>& a) : base(a) {}
};
template <class T, T e>
struct SegmentTreeMax : SegmentTree<T, Max<T>, Const<T, e>> {
  using base = SegmentTree<T, Max<T>, Const<T, e>>;
  SegmentTreeMax(const vector<T>& a) : base(a) {}
};
template <class T, T e>
struct SegmentTreeMin : SegmentTree<T, Min<T>, Const<T, e>> {
  using base = SegmentTree<T, Min<T>, Const<T, e>>;
  SegmentTreeMin(const vector<T>& a) : base(a) {}
};
};  // namespace SegmentTreeUtil
using SegmentTreeUtil::SegmentTreeMax;
using SegmentTreeUtil::SegmentTreeMin;
using SegmentTreeUtil::SegmentTreeProd;
using SegmentTreeUtil::SegmentTreeSum;
/**
 * @brief よく使う Segment Tree
 * @docs docs/segment-tree/segment-tree-util.md
 */