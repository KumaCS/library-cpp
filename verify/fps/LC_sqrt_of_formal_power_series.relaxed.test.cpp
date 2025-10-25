#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_of_formal_power_series"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "fps/fps-ntt-friendly.hpp"
using fps = FormalPowerSeries<mint>;
#include "fps/fps-sqrt.hpp"
#include "fps/relaxed.hpp"

int main() {
  int n;
  in(n);
  fps a(n);
  in(a);
  if (a[0] == 0) {
    a = FpsSqrt(a);
    if (a.empty())
      out(-1);
    else
      out(a);
  } else if (ModSqrt(a[0].val(), mint::get_mod()) == -1) {
    out(-1);
  } else {
    fps b(n);
    RelaxedSqrt<mint> sqrt;
    rep(i, 0, n) b[i] = sqrt.append(a[i]);
    out(b);
  }
}