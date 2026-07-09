#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_add_point_get"

#include "template/template.hpp"
#include "segment-tree/dynamic-dual-segment-tree-2d.hpp"

int main() {
  constexpr int C = 1000000001;

  int n, q;
  in(n, q);

  DynamicDualSegmentTree2D<AddMonoid<long long>, int> seg(0, C, 0, C);
  rep(i, 0, n) {
    int l, d, r, u, w;
    in(l, d, r, u, w);
    seg.apply(l, r, d, u, w);
  }

  rep(_, 0, q) {
    int t;
    in(t);
    if (t == 0) {
      int l, d, r, u, w;
      in(l, d, r, u, w);
      seg.apply(l, r, d, u, w);
    } else {
      int x, y;
      in(x, y);
      out(seg.get(x, y));
    }
  }
}
