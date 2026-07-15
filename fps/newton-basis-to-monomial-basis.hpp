#pragma once
#include "fps/formal-power-series.hpp"
#include "fps/power-projection.hpp"
#include "modint/factorial.hpp"

namespace newton_to_monomial_basis_internal {

template <class mint>
FormalPowerSeries<mint> BuildProductTree(vector<FormalPowerSeries<mint>>& prod, int k, int l, int r,
                                         const vector<mint>& p) {
  using fps = FormalPowerSeries<mint>;
  if (r - l == 1) return prod[k] = fps{-p[l], 1};
  int m = (l + r) / 2;
  return prod[k] = BuildProductTree(prod, k * 2, l, m, p) * BuildProductTree(prod, k * 2 + 1, m, r, p);
}

template <class mint>
FormalPowerSeries<mint> Convert(const FormalPowerSeries<mint>& a,
                                const vector<FormalPowerSeries<mint>>& prod, int k, int l, int r) {
  using fps = FormalPowerSeries<mint>;
  if (r - l == 1) return fps{a[l]};
  int m = (l + r) / 2;
  fps left = Convert(a, prod, k * 2, l, m);
  fps right = Convert(a, prod, k * 2 + 1, m, r);
  return left + prod[k * 2] * right;
}

template <class mint>
FormalPowerSeries<mint> ConvertWithProductTree(const FormalPowerSeries<mint>& a, const vector<mint>& p) {
  using fps = FormalPowerSeries<mint>;
  int n = a.size();
  if (n == 0) return {};
  vector<fps> prod(4 * n);
  BuildProductTree(prod, 1, 0, n, p);
  return Convert(a, prod, 1, 0, n);
}

}  // namespace newton_to_monomial_basis_internal

template <class mint>
FormalPowerSeries<mint> FallingFactorialToMonomialBasis(FormalPowerSeries<mint> a) {
  using fps = FormalPowerSeries<mint>;
  using fact = Factorial<mint>;
  int n = a.size();
  if (n <= 1) return a;
  fps::set_ntt();
  if (fps::ntt_ptr == nullptr) {
    vector<mint> p(n);
    for (int i = 0; i < n; i++) p[i] = i;
    return newton_to_monomial_basis_internal::ConvertWithProductTree(a, p);
  }
  fps g(n);
  for (int i = 1; i < n; i++) g[i] = fact::inv(i) * (i & 1 ? 1 : -1);
  for (int i = 0; i < n; i++) a[i] *= fact::fact(i);
  a = TransposedComposition(a, g, n);
  for (int i = 0; i < n; i++) a[i] *= fact::fact_inv(i);
  return a;
}

template <class mint>
FormalPowerSeries<mint> NewtonToMonomialBasis(const FormalPowerSeries<mint>& a, const vector<mint>& p) {
  using fps = FormalPowerSeries<mint>;
  assert(a.size() == p.size());
  int n = a.size();
  if (n == 0) return {};
  bool consecutive = true;
  for (int i = 0; i + 1 < n; i++) consecutive &= p[i] == mint(i);
  if (consecutive) return FallingFactorialToMonomialBasis(FormalPowerSeries<mint>(a));
  return newton_to_monomial_basis_internal::ConvertWithProductTree(a, p);
}

/**
 * @brief Newton 基底から単項式基底への変換
 * @docs docs/fps/newton-basis-to-monomial-basis.md
 */
