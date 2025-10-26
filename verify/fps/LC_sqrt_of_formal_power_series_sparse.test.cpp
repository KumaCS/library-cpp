#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series_sparse"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "fps/fps-ntt-friendly.hpp"
using fps = FormalPowerSeries<mint>;
#include "fps/sparse.hpp"

#include "fps/fps-sqrt.hpp"

int main() {
  int n, k;
  in(n, k);
  map<int, mint> f;
  rep(i, 0, k) {
    int j;
    mint a;
    in(j, a);
    f[j] = a;
  }
  auto g = FPSSparse::sqrt(f, n);
  if (g.empty())
    out(-1);
  else
    out(g);
}