#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation_on_geometric_sequence"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "fps/fps-ntt-friendly.hpp"
using fps = FormalPowerSeries<mint>;
#include "fps/polynomial-interpolation.hpp"

int main() {
  int n;
  mint a, r;
  in(n, a, r);
  vector<mint> y(n);
  in(y);
  out(PolynomialInterpolationGeometric(a, r, y));
}