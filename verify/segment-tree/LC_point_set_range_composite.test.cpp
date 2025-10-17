#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "template/template.hpp"
#include "segment-tree/segment-tree.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
struct F {
  mint a, b;
  mint eval(mint x) { return a * x + b; }
};
F op(F f, F g) { return {f.a * g.a, f.b * g.a + g.b}; }
F e() { return {1, 0}; }

int main() {
  int n, q;
  in(n, q);
  vector<F> f(n);
  rep(i, 0, n) {
    mint a, b;
    in(a, b);
    f[i] = {a, b};
  }
  SegmentTree<F, op, e> seg(f);
  while (q--) {
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