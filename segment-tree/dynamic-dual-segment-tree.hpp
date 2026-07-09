#pragma once

#include "algebraic-structure/monoid.hpp"

template <class M, class I = long long>
REQUIRES(Monoid<M>)
struct DynamicDualSegmentTree {
  using F = typename M::value_type;

  DynamicDualSegmentTree() : DynamicDualSegmentTree(0, 1) {}
  DynamicDualSegmentTree(I l, I r) : low(l), high(r), root(0) {
    assert(low < high);
    nodes.push_back({});
  }

  void set(I p, F f) {
    assert(low <= p && p < high);
    root = set(root, low, high, p, f);
  }

  void apply(I p, F f) { apply(p, p + 1, f); }

  void apply(I l, I r, F f) {
    assert(low <= l && l <= r && r <= high);
    if (l == r) return;
    root = apply(root, low, high, l, r, f);
  }

  F get(I p) const {
    assert(low <= p && p < high);
    return get(root, low, high, p);
  }

  int node_count() const { return (int)nodes.size() - 1; }

 private:
  struct Node {
    F lz = M::e();
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
  void inner_apply(int t, F f) { nodes[t].lz = M::op(f, nodes[t].lz); }

  void push(int t) {
    if (nodes[t].l == 0) nodes[t].l = new_node();
    if (nodes[t].r == 0) nodes[t].r = new_node();
    inner_apply(nodes[t].l, nodes[t].lz);
    inner_apply(nodes[t].r, nodes[t].lz);
    nodes[t].lz = M::e();
  }

  int set(int t, I l, I r, I p, F f) {
    if (t == 0) t = new_node();
    if (r - l == 1) {
      nodes[t].lz = f;
      return t;
    }
    push(t);
    I m = mid(l, r);
    if (p < m)
      nodes[t].l = set(nodes[t].l, l, m, p, f);
    else
      nodes[t].r = set(nodes[t].r, m, r, p, f);
    return t;
  }

  int apply(int t, I l, I r, I ql, I qr, F f) {
    if (qr <= l || r <= ql) return t;
    if (t == 0) t = new_node();
    if (ql <= l && r <= qr) {
      inner_apply(t, f);
      return t;
    }
    push(t);
    I m = mid(l, r);
    nodes[t].l = apply(nodes[t].l, l, m, ql, qr, f);
    nodes[t].r = apply(nodes[t].r, m, r, ql, qr, f);
    return t;
  }

  F get(int t, I l, I r, I p) const {
    if (t == 0) return M::e();
    if (r - l == 1) return nodes[t].lz;
    I m = mid(l, r);
    F child = p < m ? get(nodes[t].l, l, m, p) : get(nodes[t].r, m, r, p);
    return M::op(nodes[t].lz, child);
  }
};

/**
 * @brief Dynamic Dual Segment Tree
 * @docs docs/segment-tree/dynamic-dual-segment-tree.md
 */
