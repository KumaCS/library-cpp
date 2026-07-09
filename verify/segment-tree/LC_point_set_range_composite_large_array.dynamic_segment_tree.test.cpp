#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite_large_array"

#include "template/template.hpp"
#include "segment-tree/dynamic-segment-tree.hpp"
#include "modint/modint.hpp"

using mint = ModInt<998244353>;

struct F {
  mint a, b;
  mint eval(mint x) { return a * x + b; }
};

struct CompositeMonoid {
  using value_type = F;
  static F op(F f, F g) { return {f.a * g.a, f.b * g.a + g.b}; }
  static F e() { return {1, 0}; }
};

int main() {
  int n, q;
  in(n, q);

  DynamicSegmentTree<CompositeMonoid, int> seg(0, n);
  rep(_, 0, q) {
    int t;
    in(t);
    if (t == 0) {
      int p;
      mint c, d;
      in(p, c, d);
      seg.set(p, {c, d});
    } else {
      int l, r;
      mint x;
      in(l, r, x);
      out(seg.prod(l, r).eval(x));
    }
  }
}
