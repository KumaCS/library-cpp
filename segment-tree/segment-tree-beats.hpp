#pragma once
#include "segment-tree/lazy-segment-tree.hpp"

template <class A>
REQUIRES(MonoidAction<A>)
struct SegmentTreeBeats : LazySegmentTree<A> {
  using base = LazySegmentTree<A>;
  using T = typename base::T;
  using F = typename base::F;

  SegmentTreeBeats() : base() {}
  explicit SegmentTreeBeats(int n) : base(n) {}
  explicit SegmentTreeBeats(const vector<T>& v) : base(v) {}

 protected:
  void all_apply(int k, F f) override {
    this->d[k] = A::mapping(f, this->d[k]);
    if (k < this->size) {
      this->lz[k] = base::OM::op(f, this->lz[k]);
      if (this->d[k].fail) this->push(k), this->update(k);
    }
  }
};

/**
 * @brief Segment Tree Beats
 * @docs docs/segment-tree/segment-tree-beats.md
 */
