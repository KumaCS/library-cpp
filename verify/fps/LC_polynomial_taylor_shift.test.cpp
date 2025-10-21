#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "fps/fps-ntt-friendly.hpp"
using fps = FormalPowerSeries<mint>;
#include "fps/taylor-shift.hpp"

int main() {
  int n;
  mint c;
  in(n, c);
  fps a(n);
  in(a);
  out(TaylorShift(a, c));
}