#pragma once
#include "binary-search-tree/rbst-base.hpp"
#include "algebraic-structure/monoid.hpp"

template <class M>
REQUIRES(Monoid<M>)
struct RBSTSegmentTreeNode {
  using T = M::value_type;
  typename RBSTBase<RBSTSegmentTreeNode>::Ptr l, r;
  int cnt;
  T key, sum, rev_sum;
  bool rev;
  RBSTSegmentTreeNode(const T& t = M::e()) : l(), r(), cnt(1), key(t), sum(t), rev_sum(t), rev(false) {}
};

template <class M>
REQUIRES(Monoid<M>)
struct RBSTSegmentTree : RBSTBase<RBSTSegmentTreeNode<M>> {
  using T = M::value_type;
  using Node = RBSTSegmentTreeNode<M>;
  using base = RBSTBase<Node>;
  using base::merge;
  using base::split;
  using typename base::Ptr;

  RBSTSegmentTree() = default;
  T get(Ptr& t, int k) {
    auto x = split(t, k);
    auto y = split(x.second, 1);
    T v = y.first->key;
    t = merge(x.first, merge(y.first, y.second));
    return v;
  }
  void set(Ptr& t, int k, T v) {
    auto x = split(t, k);
    auto y = split(x.second, 1);
    y.first->key = v;
    update(y.first);
    t = merge(x.first, merge(y.first, y.second));
  }
  T prod(Ptr& t, int l, int r) {
    if (l >= r) return M::e();
    auto x = split(t, l);
    auto y = split(x.second, r - l);
    auto ret = y.first->sum;
    t = merge(x.first, merge(y.first, y.second));
    return ret;
  }
  void reverse(Ptr& t, int l, int r) {
    if (l >= r) return;
    auto x = split(t, l);
    auto y = split(x.second, r - l);
    toggle(y.first);
    t = merge(x.first, merge(y.first, y.second));
  }

 protected:
  Ptr update(Ptr t) override {
    t->cnt = 1;
    t->sum = t->rev_sum = t->key;
    if (t->l) {
      t->cnt += t->l->cnt;
      t->sum = M::op(t->l->sum, t->sum);
      t->rev_sum = M::op(t->rev_sum, t->l->rev_sum);
    }
    if (t->r) {
      t->cnt += t->r->cnt;
      t->sum = M::op(t->sum, t->r->sum);
      t->rev_sum = M::op(t->r->rev_sum, t->rev_sum);
    }
    return t;
  }
  void push(Ptr t) override {
    if (!t->rev) return;
    if (t->l) toggle(t->l);
    if (t->r) toggle(t->r);
    t->rev = false;
  }

 private:
  void toggle(Ptr t) {
    swap(t->l, t->r);
    swap(t->sum, t->rev_sum);
    t->rev ^= true;
  }
};

/**
 * @brief 挿入/削除の可能なセグメント木 (乱択二分探索木)
 * @docs docs/binary-search-tree/rbst-segment-tree.md
 */
