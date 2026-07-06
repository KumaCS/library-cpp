#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_multiplicative_function"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<469762049>;

#include "number-theory/lucy-dp.hpp"
#include "number-theory/sum-of-multiplicative-function.hpp"

int main() {
  int T;
  in(T);
  const mint inv2 = mint(2).inv();
  while (T--) {
    ll N;
    mint a, b;
    in(N, a, b);
    auto sum0 = LucyDP<mint>(N, [&](ll p) { return 1; }, [&](ll p) { return p; }).second;
    auto sum1 = LucyDP<mint>(N, [&](ll p) { return p; }, [&](ll p) { return mint(p) * (p + 1) * inv2; }).second;
    vector<mint> sum(sum0.size());
    rep(i, 0, sum.size()) sum[i] = sum0[i] * a + sum1[i] * b;
    mint ans = SumOfMultiplicativeFunction<mint>(N, 1, sum, [&](ll p, int e, ll q) { return a * e + b * p; });
    out(ans);
  }
}
