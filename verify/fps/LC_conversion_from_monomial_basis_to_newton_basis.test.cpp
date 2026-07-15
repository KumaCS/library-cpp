#define PROBLEM "https://judge.yosupo.jp/problem/conversion_from_monomial_basis_to_newton_basis"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "fps/fps-ntt-friendly.hpp"
using fps = FormalPowerSeries<mint>;
#include "fps/monomial-basis-to-newton-basis.hpp"

int main() {
  int n;
  in(n);
  fps a(n);
  vector<mint> p(n);
  in(a, p);
  out(MonomialToNewtonBasis(a, p));
}
