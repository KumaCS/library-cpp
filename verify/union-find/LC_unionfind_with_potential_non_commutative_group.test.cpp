#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "union-find/potentialized-union-find.hpp"

struct Mat {
  mint a, b, c, d;
  friend bool operator==(const Mat& x, const Mat& y) {
    return x.a == y.a && x.b == y.b && x.c == y.c && x.d == y.d;
  }
};

struct MatGroup {
  using value_type = Mat;
  static Mat op(const Mat& x, const Mat& y) {
    // The problem composes transformations in the opposite order of diff(u, v).
    return {
        y.a * x.a + y.b * x.c,
        y.a * x.b + y.b * x.d,
        y.c * x.a + y.d * x.c,
        y.c * x.b + y.d * x.d,
    };
  }
  static Mat e() { return {1, 0, 0, 1}; }
  static Mat inv(const Mat& x) {
    mint det_inv = (x.a * x.d - x.b * x.c).inv();
    return {x.d * det_inv, -x.b * det_inv, -x.c * det_inv, x.a * det_inv};
  }
};

int main() {
  int n, q;
  in(n, q);
  PotentializedUnionFind<MatGroup> uf(n);
  while (q--) {
    int type, u, v;
    in(type, u, v);
    if (type == 0) {
      Mat w;
      in(w.a, w.b, w.c, w.d);
      out(uf.unite(u, v, w));
    } else {
      if (uf.same(u, v)) {
        Mat w = uf.diff(u, v);
        out(w.a, w.b, w.c, w.d);
      } else {
        out(-1);
      }
    }
  }
}
