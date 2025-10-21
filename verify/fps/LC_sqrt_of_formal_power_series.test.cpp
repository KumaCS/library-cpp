#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_of_formal_power_series"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "fps/fps-ntt-friendly.hpp"
using fps = FormalPowerSeries<mint>;
#include "fps/fps-sqrt.hpp"

int main() {
  int n;
  in(n);
  fps a(n);
  in(a);
  a = FpsSqrt(a);
  if (a.empty())
    out(-1);
  else
    out(a);
}