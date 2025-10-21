#define PROBLEM "https://judge.yosupo.jp/problem/compositional_inverse_of_formal_power_series_large"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "fps/fps-ntt-friendly.hpp"
using fps = FormalPowerSeries<mint>;
#include "fps/compositional-inv.hpp"

int main() {
  int n;
  in(n);
  fps f(n);
  in(f);
  fps g = CompositionalInv(f);
  out(g);
}