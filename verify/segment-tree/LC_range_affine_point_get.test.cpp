#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"

#include "template/template.hpp"
#include "segment-tree/dual-segment-tree.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
struct F {
  mint a, b;
  mint eval(mint x) { return a * x + b; }
};
F op(F f, F g) { return {f.a * g.a, f.a * g.b + f.b}; }
F e() { return {1, 0}; }

int main() {
  int n, q;
  in(n, q);
  vector<mint> a(n);
  in(a);
  DualSegmentTree<F, op, e> seg(n);
  while (q--) {
    int t;
    in(t);
    if (t == 0) {
      int l, r;
      mint b, c;
      in(l, r, b, c);
      seg.apply(l, r, {b, c});
    } else {
      int i;
      in(i);
      out(seg.get(i).eval(a[i]));
    }
  }
}