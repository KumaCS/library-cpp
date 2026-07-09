#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_add_point_get"

#include "template/template.hpp"
#include "segment-tree/dual-segment-tree-2d.hpp"

int main() {
  int n, q;
  in(n, q);
  vector<array<int, 5>> rects(n);
  rep(i, 0, n) {
    int l, d, r, u, w;
    in(l, d, r, u, w);
    rects[i] = {l, d, r, u, w};
  }

  vector<array<int, 6>> qs(q);
  vector<pair<int, int>> points;
  rep(i, 0, q) {
    int t;
    in(t);
    if (t == 0) {
      int l, d, r, u, w;
      in(l, d, r, u, w);
      qs[i] = {0, l, d, r, u, w};
    } else {
      int x, y;
      in(x, y);
      qs[i] = {1, x, y, 0, 0, 0};
      points.push_back({x, y});
    }
  }

  DualSegmentTree2D<AddMonoid<long long>> seg(points);
  for (auto [l, d, r, u, w] : rects) seg.apply(l, r, d, u, w);

  for (auto query : qs) {
    if (query[0] == 0) {
      auto [_, l, d, r, u, w] = query;
      seg.apply(l, r, d, u, w);
    } else {
      auto [_, x, y, __, ___, ____] = query;
      out(seg.get(x, y));
    }
  }
}
