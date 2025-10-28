#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_set_power_series"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "set/exp-of-set-power-series.hpp"

int main() {
  int n;
  in(n);
  vector<mint> b(1 << n);
  in(b);
  auto c = SetPowerSeries::exp(b);
  out(c);
}