#pragma once
#include "fps/formal-power-series.hpp"

// f(x0),f(x1),...
template <class mint>
vector<mint> MultipointEvaluation(FormalPowerSeries<mint> f, const vector<mint>& x) {
  using fps = FormalPowerSeries<mint>;
  int m = x.size();
  if (m == 0) return {};
  vector<fps> prod(2 * m);
  for (int i = 0; i < m; i++) prod[i + m] = {-x[i], 1};
  for (int i = m - 1; i > 0; i--) prod[i] = prod[i * 2] * prod[i * 2 + 1];
  vector<fps> rem(2 * m);
  rem[1] = f % prod[1];
  for (int i = 2; i < 2 * m; i++) rem[i] = rem[i / 2] % prod[i];
  vector<mint> y(m);
  for (int i = 0; i < m; i++) y[i] = rem[i + m].empty() ? 0 : rem[i + m][0];
  return y;
}

// f(a),f(ar),...,f(ar^{n-1})
template <class mint>
vector<mint> MultipointEvaluationGeometric(FormalPowerSeries<mint> f, mint a, mint r, int n) {
  using fps = FormalPowerSeries<mint>;
  assert(n >= 0);
  if (n == 0) return {};
  if (f.empty()) return vector<mint>(n);
  mint pa = 1;
  for (int i = 1; i < f.size(); i++) f[i] *= (pa *= a);
  if (r == 0) {
    vector<mint> res(n, f[0]);
    for (int i = 1; i < f.size(); i++) res[0] += f[i];
    return res;
  }
  mint ir = r.inv();
  int sz = n - 1 + (int)f.size();
  fps rs(sz, 1), irs(sz, 1);
  mint pr = 1, pir = 1;
  for (int i = 2; i < sz; i++) {
    rs[i] = rs[i - 1] * (pr *= r);
    irs[i] = irs[i - 1] * (pir *= ir);
  }
  for (int i = 0; i < f.size(); i++) f[i] *= irs[i];
  f = f.middle_product(rs);
  for (int i = 0; i < f.size(); i++) f[i] *= irs[i];
  return f;
}

/**
 * @brief Multipoint Evaluation
 * @docs docs/fps/multipoint-evaluation.md
 */