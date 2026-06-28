#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include "template/template.hpp"
#include "data-structure/wavelet-matrix-with-segment-tree.hpp"

ll op(ll x, ll y) { return x + y; }
ll e() { return 0; }

int main() {
  int n, q;
  in(n, q);
  vector<pair<int, int>> ps;
  vector<array<int, 3>> xyws(n);
  rep(i, 0, n) {
    int x, y, w;
    in(x, y, w);
    xyws[i] = {x, y, w};
    ps.push_back({x, y});
  }
  vector<array<int, 5>> qs(q);
  rep(i, 0, q) {
    int type;
    in(type);
    if (type == 0) {
      int x, y, w;
      in(x, y, w);
      qs[i] = {0, x, y, w, -1};
      ps.push_back({x, y});
    } else {
      int l, d, r, u;
      in(l, d, r, u);
      qs[i] = {1, l, d, r, u};
    }
  }
  UNIQUE(ps);
  int m = ps.size();

  vector<int> xs(m);
  WaveletMatrixWithSegmentTree<int, ll, op, e> wm(m);
  rep(i, 0, m) {
    auto [x, y] = ps[i];
    xs[i] = x;
    wm.set(i, y, 0);
  }
  wm.build();
  for (auto [x, y, w] : xyws) wm.apply(LB(ps, make_pair(x, y)), w);

  for (auto query : qs) {
    if (query[0] == 0) {
      auto [_, x, y, w, __] = query;
      wm.apply(LB(ps, make_pair(x, y)), w);
    } else {
      auto [_, l, d, r, u] = query;
      ll ans = wm.range_sum(LB(xs, l), LB(xs, r), d, u);
      out(ans);
    }
  }
}