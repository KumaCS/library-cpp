#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_composite_set_power_series"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "set/composite-set-power-series.hpp"

int main() {
  int m, n;
  in(m, n);
  vector<mint> a(m), b(1 << n);
  in(a, b);
  auto c = SetPowerSeries::composite_polynomial(a, b);
  out(c);
}