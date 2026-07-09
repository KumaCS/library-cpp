#pragma once

#include "segment-tree/dynamic-dual-segment-tree.hpp"

// M: commutative monoid
template <class M, class I = long long>
REQUIRES(Monoid<M>)
struct DynamicDualSegmentTree2D {
  using F = typename M::value_type;

  DynamicDualSegmentTree2D() : DynamicDualSegmentTree2D(0, 1, 0, 1) {}
  DynamicDualSegmentTree2D(I xl, I xr, I yl, I yr) : x_low(xl), x_high(xr), y_low(yl), y_high(yr), root(0) {
    assert(x_low < x_high);
    assert(y_low < y_high);
    xs.push_back({});
    ys.emplace_back(y_low, y_high);
  }

  void apply(I xl, I xr, I yl, I yr, F f) {
    assert(x_low <= xl && xl <= xr && xr <= x_high);
    assert(y_low <= yl && yl <= yr && yr <= y_high);
    if (xl == xr || yl == yr) return;
    root = apply_x(root, x_low, x_high, xl, xr, yl, yr, f);
  }

  F get(I x, I y) const {
    assert(x_low <= x && x < x_high);
    assert(y_low <= y && y < y_high);
    return get_x(root, x_low, x_high, x, y);
  }

  int x_nodes() const { return (int)xs.size() - 1; }
  int y_nodes() const {
    int ret = 0;
    for (const auto& seg : ys) ret += seg.node_count();
    return ret;
  }

 private:
  struct XNode {
    int l = 0, r = 0;
  };

  I x_low, x_high, y_low, y_high;
  int root;
  vector<XNode> xs;
  vector<DynamicDualSegmentTree<M, I>> ys;

  int new_x_node() {
    xs.push_back({});
    ys.emplace_back(y_low, y_high);
    return (int)xs.size() - 1;
  }

  static I mid(I l, I r) { return l + (r - l) / 2; }

  int apply_x(int t, I l, I r, I qxl, I qxr, I qyl, I qyr, F f) {
    if (qxr <= l || r <= qxl) return t;
    if (t == 0) t = new_x_node();
    if (qxl <= l && r <= qxr) {
      ys[t].apply(qyl, qyr, f);
      return t;
    }
    I m = mid(l, r);
    xs[t].l = apply_x(xs[t].l, l, m, qxl, qxr, qyl, qyr, f);
    xs[t].r = apply_x(xs[t].r, m, r, qxl, qxr, qyl, qyr, f);
    return t;
  }

  F get_x(int t, I l, I r, I x, I y) const {
    if (t == 0) return M::e();
    F cur = ys[t].get(y);
    if (r - l == 1) return cur;
    I m = mid(l, r);
    F child = x < m ? get_x(xs[t].l, l, m, x, y) : get_x(xs[t].r, m, r, x, y);
    return M::op(cur, child);
  }
};

/**
 * @brief Dynamic 2D Dual Segment Tree
 * @docs docs/segment-tree/dynamic-dual-segment-tree-2d.md
 */
