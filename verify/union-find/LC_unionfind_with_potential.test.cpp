#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "union-find/potentialized-union-find.hpp"

int main() {
  int n, q;
  in(n, q);
  PotentializedUnionFind<mint> uf(n);
  while (q--) {
    int type, u, v;
    in(type, u, v);
    if (type == 0) {
      mint w;
      in(w);
      out(uf.unite(u, v, w));
    } else {
      if (uf.same(u, v))
        out(uf.diff(u, v));
      else
        out(-1);
    }
  }
}