#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include "template/template.hpp"
#include "data-structure/wavelet-matrix-with-weight.hpp"

int main() {
  int n, q;
  in(n, q);
  vector<array<int, 3>> xyws(n);
  rep(i, 0, n) {
    int x, y, w;
    in(x, y, w);
    xyws[i] = {x, y, w};
  }

  sort(ALL(xyws));
  vector<int> xs(n);
  WaveletMatrixWithWeight<int, ll> wm(n);
  rep(i, 0, n) {
    auto [x, y, w] = xyws[i];
    xs[i] = x;
    wm.set(i, y, w);
  }
  wm.build();

  while (q--) {
    int l, d, r, u;
    in(l, d, r, u);
    ll ans = wm.range_sum(LB(xs, l), LB(xs, r), d, u);
    out(ans);
  }
}