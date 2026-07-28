#define PROBLEM "https://judge.yosupo.jp/problem/range_set_range_composite"

#include "template/template.hpp"
#include "segment-tree/range-set-range-prod.hpp"
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
  vector<F> f(n);
  rep(i, 0, n) in(f[i].a, f[i].b);
  RangeSetRangeProd<CompositeMonoid> seg(f);
  while (q--) {
    int t, l, r;
    in(t, l, r);
    if (t == 0) {
      mint c, d;
      in(c, d);
      seg.apply(l, r, {c, d});
    } else {
      mint x;
      in(x);
      out(seg.prod(l, r).eval(x));
    }
  }
}
