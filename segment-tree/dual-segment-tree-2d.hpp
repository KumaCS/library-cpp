#pragma once

#include "segment-tree/dual-segment-tree.hpp"

// M: commutative monoid
template <class M>
REQUIRES(Monoid<M>)
struct DualSegmentTree2D {
  using F = typename M::value_type;

  DualSegmentTree2D() : n(0), size(1) {}
  explicit DualSegmentTree2D(const vector<pair<int, int>>& points) { build(points); }

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
      seg[k] = DualSegmentTree<M>((int)ys[k].size());
    }
  }

  bool contains(int x, int y) const {
    auto it = lower_bound(ps.begin(), ps.end(), make_pair(x, y));
    return it != ps.end() && *it == make_pair(x, y);
  }

  void apply(int xl, int xr, int yl, int yr, F f) {
    if (xl >= xr || yl >= yr) return;
    int l = lower_bound(xs.begin(), xs.end(), xl) - xs.begin();
    int r = lower_bound(xs.begin(), xs.end(), xr) - xs.begin();
    for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
      if (l & 1) apply_node(l++, yl, yr, f);
      if (r & 1) apply_node(--r, yl, yr, f);
    }
  }

  F get(int x, int y) {
    int k = leaf(x, y);
    F ret = M::e();
    while (k > 0) {
      ret = M::op(get_node(k, y), ret);
      k >>= 1;
    }
    return ret;
  }

  int size_x() const { return n; }
  int size_points() const { return ps.size(); }

 private:
  int n, size;
  vector<pair<int, int>> ps;
  vector<int> xs;
  vector<vector<int>> ys;
  vector<DualSegmentTree<M>> seg;

  int leaf(int x, int y) const {
    auto it = lower_bound(ps.begin(), ps.end(), make_pair(x, y));
    assert(it != ps.end() && *it == make_pair(x, y));
    int k = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    return k + size;
  }

  void apply_node(int k, int yl, int yr, F f) {
    int l = lower_bound(ys[k].begin(), ys[k].end(), yl) - ys[k].begin();
    int r = lower_bound(ys[k].begin(), ys[k].end(), yr) - ys[k].begin();
    seg[k].apply(l, r, f);
  }

  F get_node(int k, int y) {
    int i = lower_bound(ys[k].begin(), ys[k].end(), y) - ys[k].begin();
    assert(i < (int)ys[k].size() && ys[k][i] == y);
    return seg[k].get(i);
  }
};

/**
 * @brief 2D Dual Segment Tree
 * @docs docs/segment-tree/dual-segment-tree-2d.md
 */
