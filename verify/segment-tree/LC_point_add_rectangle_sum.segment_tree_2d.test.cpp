#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include "template/template.hpp"
#include "segment-tree/segment-tree-2d.hpp"

int main() {
  int n, q;
  in(n, q);
  vector<array<int, 3>> ps(n);
  vector<pair<int, int>> points;
  rep(i, 0, n) {
    int x, y, w;
    in(x, y, w);
    ps[i] = {x, y, w};
    points.push_back({x, y});
  }

  vector<array<int, 5>> qs(q);
  rep(i, 0, q) {
    int t;
    in(t);
    if (t == 0) {
      int x, y, w;
      in(x, y, w);
      qs[i] = {0, x, y, w, 0};
      points.push_back({x, y});
    } else {
      int l, d, r, u;
      in(l, d, r, u);
      qs[i] = {1, l, d, r, u};
    }
  }

  SegmentTree2D<AddMonoid<long long>> seg(points);
  for (auto [x, y, w] : ps) seg.apply(x, y, w);

  for (auto query : qs) {
    if (query[0] == 0) {
      auto [_, x, y, w, __] = query;
      seg.apply(x, y, w);
    } else {
      auto [_, l, d, r, u] = query;
      out(seg.prod(l, r, d, u));
    }
  }
}
