#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "template/template.hpp"
#include "segment-tree/lazy-segment-tree.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
struct T {
  mint c, s;
};
struct F {
  mint a, b;
  mint eval(mint x) { return a * x + b; }
};
struct SumMonoid {
  using value_type = T;
  static T op(T x, T y) { return {x.c + y.c, x.s + y.s}; }
  static T e() { return {0, 0}; }
};
struct AffineMonoid {
  using value_type = F;
  static F op(F f, F g) { return {f.a * g.a, f.a * g.b + f.b}; }
  static F e() { return {1, 0}; }
};
struct AffineSumAction {
  using value_monoid = SumMonoid;
  using operator_monoid = AffineMonoid;
  static T mapping(F f, T x) { return {x.c, f.a * x.s + f.b * x.c}; }
};

int main() {
  int n, q;
  in(n, q);
  vector<T> a(n, {1, 0});
  rep(i, 0, n) cin >> a[i].s;
  LazySegmentTree<AffineSumAction> seg(a);
  while (q--) {
    int t;
    in(t);
    if (t == 0) {
      int l, r;
      mint b, c;
      in(l, r, b, c);
      seg.apply(l, r, {b, c});
    } else {
      int l, r;
      in(l, r);
      out(seg.prod(l, r).s);
    }
  }
}
