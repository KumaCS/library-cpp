#define PROBLEM "https://judge.yosupo.jp/problem/log_of_formal_power_series"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "fps/fps-ntt-friendly.hpp"
using fps = FormalPowerSeries<mint>;
#include "fps/relaxed.hpp"

int main() {
  int n;
  in(n);
  fps a(n);
  in(a);
  RelaxedLog<mint> log;
  fps b(n);
  rep(i, 0, n) b[i] = log.append(a[i]);
  out(b);
}