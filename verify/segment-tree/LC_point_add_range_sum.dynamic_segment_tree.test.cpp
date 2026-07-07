#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "template/template.hpp"
#include "segment-tree/dynamic-segment-tree.hpp"

int main() {
  int n, q;
  in(n, q);

  DynamicSegmentTree<AddMonoid<long long>, int> seg(0, n);
  rep(i, 0, n) {
    long long a;
    in(a);
    seg.apply(i, a);
  }

  rep(_, 0, q) {
    int t;
    in(t);
    if (t == 0) {
      int p;
      long long x;
      in(p, x);
      seg.apply(p, x);
    } else {
      int l, r;
      in(l, r);
      out(seg.prod(l, r));
    }
  }
}
