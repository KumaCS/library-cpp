#define PROBLEM "https://judge.yosupo.jp/problem/dirichlet_convolution_and_prefix_sums"

#include "template/template.hpp"
#include "modint/modint.hpp"
#include "number-theory/dirichlet-series-prefix-sum.hpp"
#include "number-theory/enumerate-quotients.hpp"

using mint = ModInt998244353;
using DP = DirichletSeriesPrefixSum<mint>;

DP read_series(long long n, const vector<long long>& xs) {
  vector<mint> values(xs.size());
  in(values);
  DP f(n);
  // The input fixes prefix sums only at xs. Put each difference at its right endpoint.
  mint prev = 0;
  for (int i = 0; i < (int)xs.size() && xs[i] <= (long long)f.K; i++) {
    f.a[xs[i]] = values[i] - prev;
    prev = values[i];
  }
  f.calc_small_sum();
  for (size_t i = 1; i <= f.L; i++)
    f.S[i] = values[lower_bound(xs.begin(), xs.end(), n / i) - xs.begin()];
  return f;
}

int main() {
  int t;
  in(t);
  while (t--) {
    long long n;
    in(n);
    auto xs = EnumerateQuotients::table(n);
    auto f = read_series(n, xs);
    auto g = read_series(n, xs);
    auto h = f * g;
    vector<mint> ans;
    for (auto x : xs) ans.push_back(x <= (long long)h.K ? h.s[x] : h.S[n / x]);
    out(ans);
  }
}
