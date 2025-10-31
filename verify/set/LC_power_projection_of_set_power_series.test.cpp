#define PROBLEM "https://judge.yosupo.jp/problem/power_projection_of_set_power_series"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "set/power-projection-of-set-power-series.hpp"

int main() {
  int n, m;
  in(n, m);
  vector<mint> a(1 << n), w(1 << n);
  in(a, w);
  auto c = SetPowerSeries::power_projection(a, w, m);
  out(c);
}