#pragma once

#include "algebraic-structure/monoid-action.hpp"

template <class A, class I = long long>
REQUIRES(MonoidAction<A>)
struct DynamicLazySegmentTree {
  using VM = typename A::value_monoid;
  using OM = typename A::operator_monoid;
  using T = typename VM::value_type;
  using F = typename OM::value_type;

  DynamicLazySegmentTree() : DynamicLazySegmentTree(0, 1) {}
  DynamicLazySegmentTree(I l, I r) : DynamicLazySegmentTree(l, r, [](I, I) { return VM::e(); }) {}
  DynamicLazySegmentTree(I l, I r, function<T(I, I)> init) : low(l), high(r), root(0), initial(move(init)) {
    assert(low < high);
    nodes.push_back({});
  }

  void set(I p, T x) {
    assert(low <= p && p < high);
    root = set(root, low, high, p, x);
  }
  T get(I p) {
    assert(low <= p && p < high);
    return prod(p, p + 1);
  }
  T prod(I l, I r) {
    assert(low <= l && l <= r && r <= high);
    if (l == r) return VM::e();
    return prod(root, low, high, l, r);
  }
  T all_prod() const { return value(root, low, high); }
  void apply(I p, F f) {
    assert(low <= p && p < high);
    root = apply(root, low, high, p, p + 1, f);
  }
  void apply(I l, I r, F f) {
    assert(low <= l && l <= r && r <= high);
    if (l == r) return;
    root = apply(root, low, high, l, r, f);
  }
  int node_count() const { return (int)nodes.size() - 1; }

 private:
  struct Node {
    T val = VM::e();
    F lz = OM::e();
    int l = 0, r = 0;
  };

  I low, high;
  int root;
  function<T(I, I)> initial;
  vector<Node> nodes;

  int new_node(I l, I r) {
    nodes.push_back({initial(l, r), OM::e(), 0, 0});
    return (int)nodes.size() - 1;
  }
  static I mid(I l, I r) { return l + (r - l) / 2; }
  T value(int t, I l, I r) const { return t == 0 ? initial(l, r) : nodes[t].val; }
  void update(int t, I l, I m, I r) {
    nodes[t].val = VM::op(value(nodes[t].l, l, m), value(nodes[t].r, m, r));
  }
  void all_apply(int t, F f) {
    nodes[t].val = A::mapping(f, nodes[t].val);
    nodes[t].lz = OM::op(f, nodes[t].lz);
  }
  void push(int t, I l, I m, I r) {
    if (nodes[t].l == 0) nodes[t].l = new_node(l, m);
    if (nodes[t].r == 0) nodes[t].r = new_node(m, r);
    all_apply(nodes[t].l, nodes[t].lz);
    all_apply(nodes[t].r, nodes[t].lz);
    nodes[t].lz = OM::e();
  }
  int set(int t, I l, I r, I p, T x) {
    if (t == 0) t = new_node(l, r);
    if (r - l == 1) {
      nodes[t].val = x;
      nodes[t].lz = OM::e();
      return t;
    }
    I m = mid(l, r);
    push(t, l, m, r);
    if (p < m)
      nodes[t].l = set(nodes[t].l, l, m, p, x);
    else
      nodes[t].r = set(nodes[t].r, m, r, p, x);
    update(t, l, m, r);
    return t;
  }
  int apply(int t, I l, I r, I ql, I qr, F f) {
    if (qr <= l || r <= ql) return t;
    if (t == 0) t = new_node(l, r);
    if (ql <= l && r <= qr) {
      all_apply(t, f);
      return t;
    }
    I m = mid(l, r);
    push(t, l, m, r);
    nodes[t].l = apply(nodes[t].l, l, m, ql, qr, f);
    nodes[t].r = apply(nodes[t].r, m, r, ql, qr, f);
    update(t, l, m, r);
    return t;
  }
  T prod(int t, I l, I r, I ql, I qr) {
    if (qr <= l || r <= ql) return VM::e();
    if (t == 0) return initial(max(l, ql), min(r, qr));
    if (ql <= l && r <= qr) return nodes[t].val;
    I m = mid(l, r);
    push(t, l, m, r);
    return VM::op(prod(nodes[t].l, l, m, ql, qr), prod(nodes[t].r, m, r, ql, qr));
  }
};

/**
 * @brief Dynamic Lazy Segment Tree
 * @docs docs/segment-tree/dynamic-lazy-segment-tree.md
 */
