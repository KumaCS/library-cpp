#pragma once
#include "segment-tree/segment-tree.hpp"

namespace SegmentTreeUtil {
template <class T>
struct SegmentTreeSum : SegmentTree<AddMonoid<T>> {
  using base = SegmentTree<AddMonoid<T>>;
  SegmentTreeSum(const vector<T>& a) : base(a) {}
  SegmentTreeSum(int n) : base(n) {}
};
template <class T>
struct SegmentTreeProd : SegmentTree<MulMonoid<T>> {
  using base = SegmentTree<MulMonoid<T>>;
  SegmentTreeProd(const vector<T>& a) : base(a) {}
  SegmentTreeProd(int n) : base(n) {}
};
template <class T, T e>
struct SegmentTreeMax : SegmentTree<MaxMonoid<T, e>> {
  using base = SegmentTree<MaxMonoid<T, e>>;
  SegmentTreeMax(const vector<T>& a) : base(a) {}
  SegmentTreeMax(int n) : base(n) {}
};
template <class T, T e>
struct SegmentTreeMin : SegmentTree<MinMonoid<T, e>> {
  using base = SegmentTree<MinMonoid<T, e>>;
  SegmentTreeMin(const vector<T>& a) : base(a) {}
  SegmentTreeMin(int n) : base(n) {}
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
