#define PROBLEM "https://judge.yosupo.jp/problem/division_of_polynomials"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "fps/fps-ntt-friendly.hpp"
using fps = FormalPowerSeries<mint>;

int main() {
  int n, m;
  in(n, m);
  fps f(n), g(m);
  in(f, g);
  fps q = f / g;
  q.shrink();
  fps r = f - g * q;
  r.shrink();
  out(q.size(), r.size());
  out(q);
  out(r);
}