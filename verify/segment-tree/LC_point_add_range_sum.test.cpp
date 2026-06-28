#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "template/template.hpp"
#include "segment-tree/segment-tree.hpp"

int main() {
  int n, q;
  in(n, q);
  vector<ll> a(n);
  in(a);
  SegmentTree<AddMonoid<ll>> seg(a);
  while (q--) {
    int t;
    in(t);
    if (t == 0) {
      int p, x;
      in(p, x);
      seg.apply(p, x);
    } else {
      int l, r;
      in(l, r);
      out(seg.prod(l, r));
    }
  }
}
