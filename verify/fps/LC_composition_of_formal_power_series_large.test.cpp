#define PROBLEM "https://judge.yosupo.jp/problem/composition_of_formal_power_series_large"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "fps/fps-ntt-friendly.hpp"
using fps = FormalPowerSeries<mint>;
#include "fps/composition.hpp"

int main() {
  int n;
  in(n);
  fps f(n), g(n);
  in(f, g);
  fps h = Composition(f, g);
  out(h);
}