#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "fps/fps-ntt-friendly.hpp"
using fps = FormalPowerSeries<mint>;
#include "fps/polynomial-interpolation.hpp"

int main() {
  int n;
  in(n);
  vector<mint> x(n), y(n);
  in(x, y);
  out(PolynomialInterpolation(x, y));
}