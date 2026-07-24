#pragma once

#include "segment-tree/segment-tree.hpp"
#include "string/rolling-hash-monoid.hpp"

template <class Value = char>
struct RollingHashSegmentTree : SegmentTree<RollingHashMonoid> {
  using M = RollingHashMonoid;
  using SegTree = SegmentTree<M>;
  RollingHashSegmentTree() : SegTree() {}
  explicit RollingHashSegmentTree(const vector<Value>& a) : SegTree(M::init(a)) {}
  explicit RollingHashSegmentTree(const string& s) : SegTree(M::init(s)) {}
  void set(int p, Value v) { SegTree::set(p, M::single(v)); }
  Value get(int p) { return RollingHashBase::restore<Value>(SegTree::get(p).hash); }
  RollingHashValue prod(int l, int r) { return SegTree::prod(l, r); }
};

template <class Value = char>
struct RollingHashSegmentTreeReversible : SegmentTree<RollingHashMonoidReversible> {
  using M = RollingHashMonoidReversible;
  using SegTree = SegmentTree<M>;
  RollingHashSegmentTreeReversible() : SegTree() {}
  explicit RollingHashSegmentTreeReversible(const vector<Value>& a) : SegTree(M::init(a)) {}
  explicit RollingHashSegmentTreeReversible(const string& s) : SegTree(M::init(s)) {}
  void set(int p, Value v) { SegTree::set(p, M::single(v)); }
  Value get(int p) { return RollingHashBase::restore<Value>(SegTree::get(p).hash); }
  RollingHashValueReversible prod(int l, int r) { return SegTree::prod(l, r); }
};
