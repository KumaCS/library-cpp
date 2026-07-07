#pragma once

#include "segment-tree/dynamic-segment-tree.hpp"

// M: commutative monoid
template <class M, class I = long long>
REQUIRES(Monoid<M>)
struct DynamicSegmentTree2D {
  using T = typename M::value_type;
  DynamicSegmentTree2D() : DynamicSegmentTree2D(0, 1, 0, 1) {}
  // [xl, xr) * [yl, yr)
  DynamicSegmentTree2D(I xl, I xr, I yl, I yr) : x_low(xl), x_high(xr), y_low(yl), y_high(yr), root(0) {
    assert(x_low < x_high);
    assert(y_low < y_high);
    xs.push_back({});
    ys.emplace_back(y_low, y_high);
  }
  void apply(I x, I y, T v) {
    assert(x_low <= x && x < x_high);
    assert(y_low <= y && y < y_high);
    root = apply_x(root, x_low, x_high, x, y, v);
  }
  T get(I x, I y) const {
    assert(x_low <= x && x < x_high);
    assert(y_low <= y && y < y_high);
    return prod(x, x + 1, y, y + 1);
  }
  T prod(I qxl, I qxr, I qyl, I qyr) const {
    assert(x_low <= qxl && qxl <= qxr && qxr <= x_high);
    assert(y_low <= qyl && qyl <= qyr && qyr <= y_high);
    if (qxl == qxr || qyl == qyr) return M::e();
    return prod_x(root, x_low, x_high, qxl, qxr, qyl, qyr);
  }
  int x_nodes() const { return xs.size() - 1; }
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
  vector<DynamicSegmentTree<M, I>> ys;
  int new_x_node() {
    xs.push_back({});
    ys.emplace_back(y_low, y_high);
    return (int)xs.size() - 1;
  }
  static I mid(I l, I r) { return l + (r - l) / 2; }
  int apply_x(int t, I l, I r, I x, I y, T v) {
    if (t == 0) t = new_x_node();
    ys[t].apply(y, v);
    if (r - l == 1) return t;
    I m = mid(l, r);
    if (x < m)
      xs[t].l = apply_x(xs[t].l, l, m, x, y, v);
    else
      xs[t].r = apply_x(xs[t].r, m, r, x, y, v);
    return t;
  }
  T prod_x(int t, I l, I r, I qxl, I qxr, I qyl, I qyr) const {
    if (t == 0 || qxr <= l || r <= qxl) return M::e();
    if (qxl <= l && r <= qxr) return ys[t].prod(qyl, qyr);
    I m = mid(l, r);
    return M::op(prod_x(xs[t].l, l, m, qxl, qxr, qyl, qyr), prod_x(xs[t].r, m, r, qxl, qxr, qyl, qyr));
  }
};

/**
 * @brief Dynamic 2D Segment Tree
 * @docs docs/segment-tree/dynamic-segment-tree-2d.md
 */
