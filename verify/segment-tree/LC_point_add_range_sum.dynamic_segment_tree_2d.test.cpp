#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "template/template.hpp"
#include "segment-tree/dynamic-segment-tree-2d.hpp"

int main() {
  int n, q;
  in(n, q);

  DynamicSegmentTree2D<AddMonoid<long long>, int> seg(0, 1, 0, n);
  rep(i, 0, n) {
    long long a;
    in(a);
    seg.apply(0, i, a);
  }

  rep(_, 0, q) {
    int t;
    in(t);
    if (t == 0) {
      int p;
      long long x;
      in(p, x);
      seg.apply(0, p, x);
    } else {
      int l, r;
      in(l, r);
      out(seg.prod(0, 1, l, r));
    }
  }
}
