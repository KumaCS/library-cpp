#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum_large_array"

#include "template/template.hpp"
#include "segment-tree/dynamic-lazy-segment-tree.hpp"
#include "modint/modint.hpp"

using mint = ModInt<998244353>;

struct T {
  mint c, s;
};

struct F {
  mint a, b;
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
  DynamicLazySegmentTree<AffineSumAction, int> seg(0, n, [](int l, int r) { return T{r - l, 0}; });
  while (q--) {
    int t, l, r;
    in(t, l, r);
    if (t == 0) {
      mint b, c;
      in(b, c);
      seg.apply(l, r, {b, c});
    } else {
      out(seg.prod(l, r).s);
    }
  }
}
