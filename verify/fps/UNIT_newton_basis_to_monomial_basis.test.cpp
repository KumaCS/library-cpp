#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "fps/fps-ntt-friendly.hpp"
using fps = FormalPowerSeries<mint>;
#include "fps/newton-basis-to-monomial-basis.hpp"

fps naive(const fps& a, const vector<mint>& p) {
  fps f(a.size()), basis{1};
  for (int i = 0; i < (int)a.size(); i++) {
    f += basis * a[i];
    basis *= fps{-p[i], 1};
  }
  return f;
}

int main() {
  assert(FallingFactorialToMonomialBasis(fps{}).empty());
  assert(FallingFactorialToMonomialBasis(fps{7}) == fps{7});
  assert(NewtonToMonomialBasis(fps{}, vector<mint>{}).empty());

  mt19937 rng(0);
  for (int n = 1; n <= 100; n++) {
    fps a(n);
    vector<mint> p(n);
    for (auto& x : a) x = rng();
    for (auto& x : p) x = rng() % 10;
    assert(NewtonToMonomialBasis(a, p) == naive(a, p));
  }
  for (int n = 1; n <= 100; n++) {
    fps a(n);
    vector<mint> p(n);
    for (auto& x : a) x = rng();
    iota(ALL(p), 0);
    assert(FallingFactorialToMonomialBasis(a) == naive(a, p));
    assert(NewtonToMonomialBasis(a, p) == naive(a, p));
  }
  {
    int n = 100000;
    fps a(n);
    vector<mint> p(n);
    for (auto& x : a) x = rng();
    assert(NewtonToMonomialBasis(a, p) == a);
  }

  int a, b;
  in(a, b);
  out(a + b);
}
