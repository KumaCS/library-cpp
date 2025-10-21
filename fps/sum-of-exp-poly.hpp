#pragma once
#include "fps/interpolate.hpp"
#include "modint/factorial.hpp"

// sum_{i=0}^{infty}r^i*poly(i)
// f[i]=poly(i)
template <class mint>
mint SumOfExpPolyLimit(mint r, vector<mint>& f) {
  if (r == 0) return f[0];
  assert(r != 1);
  int k = f.size();
  vector<mint> g(k + 1, 0);
  mint prod = 1;
  for (int i = 0; i < k; i++) {
    g[i + 1] = g[i] + f[i] * prod;
    prod *= r;
  }
  using fact = Factorial<mint>;
  mint c = 0;
  prod = 1;
  for (int i = 0; i <= k; i++) {
    c += fact::binom(k, i) * prod * g[k - i];
    prod *= -r;
  }
  c /= (1 - r).pow(k);
  return c;
}
// sum_{i=0}^{n-1}r^i*poly(i)
// f[i]=poly(i)
template <class mint>
mint SumOfExpPoly(long long n, mint r, vector<mint>& f) {
  if (n <= 0) return 0;
  if (r == 0) return f[0];
  int k = f.size();
  vector<mint> g(k + 1, 0);
  mint prod = 1;
  for (int i = 0; i < k; i++) {
    g[i + 1] = g[i] + f[i] * prod;
    prod *= r;
  }
  if (r == 1) return Interpolate(g, mint(n));
  mint c = 0;
  prod = 1;
  using fact = Factorial<mint>;
  for (int i = 0; i <= k; i++) {
    c += fact::binom(k, i) * prod * g[k - i];
    prod *= -r;
  }
  c /= (1 - r).pow(k);
  for (int i = 0; i <= k; i++) g[i] -= c;
  mint ir = r.inv();
  prod = 1;
  for (int i = 1; i <= k; i++) g[i] *= (prod *= ir);
  return Interpolate(g, mint(n)) * r.pow(n) + c;
}
/**
 * @brief $\sum_{i}r^i poly(i)$
 * @docs docs/fps/sum-of-exp-poly.md
 */