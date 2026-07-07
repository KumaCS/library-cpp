#pragma once

#include "algebraic-structure/monoid.hpp"

// M: commutative monoid
template <class M>
REQUIRES(Monoid<M>)
struct SegmentTree2D {
  using T = typename M::value_type;
  SegmentTree2D() : n(0), size(1) {}
  explicit SegmentTree2D(const vector<pair<int, int>>& points) { build(points); }
  void build(vector<pair<int, int>> points) {
    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());
    ps = points;
    xs.clear();
    xs.reserve(ps.size());
    for (auto [x, _] : ps) xs.push_back(x);
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    n = xs.size();
    size = 1;
    while (size < n) size <<= 1;
    ys.assign(2 * size, {});
    seg.assign(2 * size, {});
    for (auto [x, y] : ps) {
      int k = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
      for (k += size; k > 0; k >>= 1) ys[k].push_back(y);
    }
    for (int k = 1; k < 2 * size; k++) {
      sort(ys[k].begin(), ys[k].end());
      ys[k].erase(unique(ys[k].begin(), ys[k].end()), ys[k].end());
      seg[k].assign(2 * ys[k].size(), M::e());
    }
  }
  bool contains(int x, int y) const {
    auto it = lower_bound(ps.begin(), ps.end(), make_pair(x, y));
    return it != ps.end() && *it == make_pair(x, y);
  }
  void set(int x, int y, T v) {
    int k = leaf(x, y);
    set_node(k, y, v);
    while (k >>= 1) {
      T vl = get_node(2 * k, y);
      T vr = get_node(2 * k + 1, y);
      set_node(k, y, M::op(vl, vr));
    }
  }
  void apply(int x, int y, T v) {
    int k = leaf(x, y);
    while (k > 0) {
      apply_node(k, y, v);
      k >>= 1;
    }
  }
  T get(int x, int y) const {
    int k = leaf(x, y);
    return get_node(k, y);
  }
  T prod(int xl, int xr, int yl, int yr) const {
    if (xl >= xr || yl >= yr) return M::e();
    int l = lower_bound(xs.begin(), xs.end(), xl) - xs.begin();
    int r = lower_bound(xs.begin(), xs.end(), xr) - xs.begin();
    T sl = M::e(), sr = M::e();
    for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
      if (l & 1) sl = M::op(sl, prod_node(l++, yl, yr));
      if (r & 1) sr = M::op(prod_node(--r, yl, yr), sr);
    }
    return M::op(sl, sr);
  }
  int size_x() const { return n; }
  int size_points() const { return ps.size(); }

 private:
  int n, size;
  vector<pair<int, int>> ps;
  vector<int> xs;
  vector<vector<int>> ys;
  vector<vector<T>> seg;
  int leaf(int x, int y) const {
    auto it = lower_bound(ps.begin(), ps.end(), make_pair(x, y));
    assert(it != ps.end() && *it == make_pair(x, y));
    int k = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    return k + size;
  }
  int y_index(int k, int y) const {
    int i = lower_bound(ys[k].begin(), ys[k].end(), y) - ys[k].begin();
    assert(i < (int)ys[k].size() && ys[k][i] == y);
    return i;
  }
  void set_node(int k, int y, T v) {
    int m = ys[k].size();
    int i = y_index(k, y) + m;
    seg[k][i] = v;
    while (i >>= 1) seg[k][i] = M::op(seg[k][2 * i], seg[k][2 * i + 1]);
  }
  void apply_node(int k, int y, T v) {
    int m = ys[k].size();
    int i = y_index(k, y) + m;
    seg[k][i] = M::op(seg[k][i], v);
    while (i >>= 1) seg[k][i] = M::op(seg[k][2 * i], seg[k][2 * i + 1]);
  }
  T get_node(int k, int y) const {
    int m = ys[k].size();
    int i = lower_bound(ys[k].begin(), ys[k].end(), y) - ys[k].begin();
    if (i == m || ys[k][i] != y) return M::e();
    return seg[k][i + m];
  }
  T prod_node(int k, int yl, int yr) const {
    int m = ys[k].size();
    int l = lower_bound(ys[k].begin(), ys[k].end(), yl) - ys[k].begin();
    int r = lower_bound(ys[k].begin(), ys[k].end(), yr) - ys[k].begin();
    T sl = M::e(), sr = M::e();
    for (l += m, r += m; l < r; l >>= 1, r >>= 1) {
      if (l & 1) sl = M::op(sl, seg[k][l++]);
      if (r & 1) sr = M::op(seg[k][--r], sr);
    }
    return M::op(sl, sr);
  }
};

/**
 * @brief 2D Segment Tree
 * @docs docs/segment-tree/segment-tree-2d.md
 */
