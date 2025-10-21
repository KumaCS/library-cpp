#define PROBLEM "https://judge.yosupo.jp/problem/log_of_formal_power_series"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "fps/fps-ntt-friendly.hpp"
using fps = FormalPowerSeries<mint>;

int main() {
  int n;
  in(n);
  fps a(n);
  in(a);
  out(a.log());
}