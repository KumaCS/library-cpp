#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "fps/fps-ntt-friendly.hpp"
using fps = FormalPowerSeries<mint>;
#include "fps/relaxed.hpp"

int main() {
  int n, m;
  in(n, m);
  fps a(n), b(m);
  in(a, b);
  fps c(n + m - 1);
  SemiRelaxedMultiply<mint> conv(b);
  rep(i, 0, n + m - 1) c[i] = conv.append(i < n ? a[i] : 0);
  out(c);
}