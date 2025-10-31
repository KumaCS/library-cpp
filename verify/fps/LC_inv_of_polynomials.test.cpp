#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_polynomials"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "fps/fps-ntt-friendly.hpp"
using fps = FormalPowerSeries<mint>;
#include "fps/polynomial-gcd.hpp"

int main() {
  int n, m;
  in(n, m);
  fps a(n), b(m);
  in(a, b);
  auto g = PolynomialInv(a, b);
  if (!g)
    out(-1);
  else {
    out(g.value().size());
    out(g.value());
  }
}