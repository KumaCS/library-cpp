#define PROBLEM "https://judge.yosupo.jp/problem/find_linear_recurrence"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "fps/fps-ntt-friendly.hpp"
using fps = FormalPowerSeries<mint>;
#include "fps/berlekamp-massey.hpp"

int main() {
  int n;
  in(n);
  fps a(n);
  in(a);
  auto b = BerlekampMassey(a);
  b.erase(b.begin());
  for (auto& v : b) v = -v;
  out(b.size());
  out(b);
}