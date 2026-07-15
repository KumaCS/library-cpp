#pragma once
#include "fps/formal-power-series.hpp"
#include "fps/power-projection.hpp"
#include "modint/factorial.hpp"

namespace monomial_to_newton_basis_internal {

template <class mint>
FormalPowerSeries<mint> BuildProductTree(vector<FormalPowerSeries<mint>>& prod, int k, int l, int r,
                                         const vector<mint>& p) {
  using fps = FormalPowerSeries<mint>;
  if (r - l == 1) return prod[k] = fps{-p[l], 1};
  int m = (l + r) / 2;
  return prod[k] = BuildProductTree(prod, k * 2, l, m, p) * BuildProductTree(prod, k * 2 + 1, m, r, p);
}

template <class mint>
void Convert(FormalPowerSeries<mint> f, const vector<FormalPowerSeries<mint>>& prod, int k, int l,
             int r, FormalPowerSeries<mint>& res) {
  if (r - l == 1) {
    res[l] = f.empty() ? mint(0) : f[0];
    return;
  }
  int m = (l + r) / 2;
  auto q = f / prod[k * 2];
  f -= q * prod[k * 2];
  f.shrink();
  Convert(std::move(f), prod, k * 2, l, m, res);
  Convert(std::move(q), prod, k * 2 + 1, m, r, res);
}

template <class mint>
FormalPowerSeries<mint> ConvertWithProductTree(FormalPowerSeries<mint> f, const vector<mint>& p) {
  using fps = FormalPowerSeries<mint>;
  int n = f.size();
  if (n == 0) return {};
  vector<fps> prod(4 * n);
  BuildProductTree(prod, 1, 0, n, p);
  fps res(n);
  Convert(std::move(f), prod, 1, 0, n, res);
  return res;
}

}  // namespace monomial_to_newton_basis_internal

template <class mint>
FormalPowerSeries<mint> MonomialToFallingFactorialBasis(FormalPowerSeries<mint> f) {
  using fps = FormalPowerSeries<mint>;
  using fact = Factorial<mint>;
  int n = f.size();
  if (n <= 1) return f;
  fps::set_ntt();
  if (fps::ntt_ptr == nullptr) {
    vector<mint> p(n);
    for (int i = 0; i < n; i++) p[i] = i;
    return monomial_to_newton_basis_internal::ConvertWithProductTree(std::move(f), p);
  }
  fps g(n);
  for (int i = 1; i < n; i++) g[i] = fact::fact_inv(i);
  for (int i = 0; i < n; i++) f[i] *= fact::fact(i);
  f = TransposedComposition(f, g, n);
  for (int i = 0; i < n; i++) f[i] *= fact::fact_inv(i);
  return f;
}

template <class mint>
FormalPowerSeries<mint> MonomialToNewtonBasis(FormalPowerSeries<mint> f, const vector<mint>& p) {
  using fps = FormalPowerSeries<mint>;
  assert(f.size() == p.size());
  int n = f.size();
  if (n == 0) return {};
  bool consecutive = true;
  for (int i = 0; i + 1 < n; i++) consecutive &= p[i] == mint(i);
  if (consecutive) return MonomialToFallingFactorialBasis(std::move(f));
  return monomial_to_newton_basis_internal::ConvertWithProductTree(std::move(f), p);
}

/**
 * @brief 単項式基底から Newton 基底への変換
 * @docs docs/fps/monomial-basis-to-newton-basis.md
 */
