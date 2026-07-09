#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include "template/template.hpp"
#include "segment-tree/dynamic-segment-tree-2d.hpp"

int main() {
  constexpr int C = 1000000001;

  int n, q;
  in(n, q);

  DynamicSegmentTree2D<AddMonoid<long long>, int> seg(0, C, 0, C);
  rep(i, 0, n) {
    int x, y, w;
    in(x, y, w);
    seg.apply(x, y, w);
  }

  rep(_, 0, q) {
    int t;
    in(t);
    if (t == 0) {
      int x, y, w;
      in(x, y, w);
      seg.apply(x, y, w);
    } else {
      int l, d, r, u;
      in(l, d, r, u);
      out(seg.prod(l, r, d, u));
    }
  }
}
