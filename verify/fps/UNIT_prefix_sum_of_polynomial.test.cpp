#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "fps/fps-ntt-friendly.hpp"
using fps = FormalPowerSeries<mint>;
#include "fps/multipoint-evaluation.hpp"
#include "fps/polynomial-interpolation.hpp"
#include "fps/prefix-sum-of-polynomial.hpp"

fps prefix_sum_with_multieval_and_interpolation(fps f) {
  vector<mint> x(f.size() + 1);
  iota(ALL(x), 0);
  auto y = MultipointEvaluation(f, x);
  rep(i, 1, y.size()) y[i] += y[i - 1];
  return PolynomialInterpolation(x, y);
}

void test(fps f) {
  auto g = prefix_sum_with_multieval_and_interpolation(f);
  auto h = PrefixSumOfPolynomial(f);
  assert(g == h);
}

int main() {
  {
    fps f(10);
    fill(ALL(f), 1);
    test(f);
  }
  {
    fps f(10);
    iota(ALL(f), 1);
    test(f);
  }
  {
    fps f(100000);
    f[0] = 998;
    rep(i, 1, f.size()) f[i] = f[i - 1] * 244 + 353;
    test(f);
  }

  int a, b;
  in(a, b);
  out(a + b);
}