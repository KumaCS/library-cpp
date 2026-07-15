#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series_2d"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "fps/fps-2d-ntt-friendly.hpp"
using fps2d = FormalPowerSeries2D<mint>;

int main() {
  int n, m;
  in(n, m);
  fps2d a(n, m);
  in(a);
  out(a.inv());
}
