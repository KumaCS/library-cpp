#pragma once

#include "algebraic-structure/monoid.hpp"

template <class M, class I = long long>
REQUIRES(Monoid<M>)
struct DynamicSegmentTree {
  using T = typename M::value_type;
  DynamicSegmentTree() : DynamicSegmentTree(0, 1) {}
  // [l, r)
  DynamicSegmentTree(I l, I r) : low(l), high(r), root(0) {
    assert(low < high);
    nodes.push_back({});
  }
  void set(I p, T v) {
    assert(low <= p && p < high);
    root = set(root, low, high, p, v);
  }
  void apply(I p, T v) {
    assert(low <= p && p < high);
    root = apply(root, low, high, p, v);
  }
  T get(I p) const {
    assert(low <= p && p < high);
    return prod(p, p + 1);
  }
  T prod(I l, I r) const {
    assert(low <= l && l <= r && r <= high);
    if (l == r) return M::e();
    return prod(root, low, high, l, r);
  }
  T all_prod() const { return value(root); }
  int node_count() const { return (int)nodes.size() - 1; }

 private:
  struct Node {
    T val = M::e();
    int l = 0, r = 0;
  };
  I low, high;
  int root;
  vector<Node> nodes;
  int new_node() {
    nodes.push_back({});
    return (int)nodes.size() - 1;
  }
  static I mid(I l, I r) { return l + (r - l) / 2; }
  T value(int t) const { return t == 0 ? M::e() : nodes[t].val; }
  int set(int t, I l, I r, I p, T v) {
    if (t == 0) t = new_node();
    if (r - l == 1) {
      nodes[t].val = v;
      return t;
    }
    I m = mid(l, r);
    if (p < m)
      nodes[t].l = set(nodes[t].l, l, m, p, v);
    else
      nodes[t].r = set(nodes[t].r, m, r, p, v);
    nodes[t].val = M::op(value(nodes[t].l), value(nodes[t].r));
    return t;
  }
  int apply(int t, I l, I r, I p, T v) {
    if (t == 0) t = new_node();
    if (r - l == 1) {
      nodes[t].val = M::op(nodes[t].val, v);
      return t;
    }
    I m = mid(l, r);
    if (p < m)
      nodes[t].l = apply(nodes[t].l, l, m, p, v);
    else
      nodes[t].r = apply(nodes[t].r, m, r, p, v);
    nodes[t].val = M::op(value(nodes[t].l), value(nodes[t].r));
    return t;
  }
  T prod(int t, I l, I r, I ql, I qr) const {
    if (t == 0 || qr <= l || r <= ql) return M::e();
    if (ql <= l && r <= qr) return nodes[t].val;
    I m = mid(l, r);
    return M::op(prod(nodes[t].l, l, m, ql, qr), prod(nodes[t].r, m, r, ql, qr));
  }
};

/**
 * @brief Dynamic Segment Tree
 * @docs docs/segment-tree/dynamic-segment-tree.md
 */
