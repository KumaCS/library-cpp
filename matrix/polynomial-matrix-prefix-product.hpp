#pragma once
#include "fps/formal-power-series.hpp"
#include "fps/sampling-points-shift.hpp"
#include "matrix/matrix.hpp"

// a(k-1) a(k-2) ... a(0)
template <class mint>
Matrix<mint> PolynomialMatrixPrefixProduct(const Matrix<FormalPowerSeries<mint>>& a, long long k) {
  using mat = Matrix<mint>;
  assert(k >= 0 && a.h == a.w);
  int n = a.h, deg = 1;
  for (const auto& f : a.a) deg = max(deg, (int)f.size() - 1);
  while (deg & (deg - 1)) deg++;

  auto shift = [&](const vector<mat>& g, mint x) {
    int d = g.size();
    vector<mat> h(d, mat(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        vector<mint> y(d);
        for (int l = 0; l < d; l++) y[l] = g[l].get(i, j);
        auto z = SamplingPointsShift(y, x, d);
        for (int l = 0; l < d; l++) h[l].set(i, j, z[l]);
      }
    }
    return h;
  };

  long long v = 1;
  while ((__int128)deg * v * v < k) v *= 2;
  vector<mat> g(deg + 1, mat(n));
  for (int i = 0; i <= deg; i++) {
    mint x = mint(v) * i;
    for (int j = 0; j < n; j++)
      for (int l = 0; l < n; l++) g[i].set(j, l, a.get(j, l).eval(x));
  }
  mint iv = mint(v).inv();
  for (long long w = 1; w < v; w *= 2) {
    auto g1 = shift(g, mint(w) * iv);
    auto g2 = shift(g, mint(w * deg * v + v) * iv);
    auto g3 = shift(g, mint(w * deg * v + v + w) * iv);
    for (int i = 0; i <= w * deg; i++) {
      g[i] = g1[i] * g[i];
      g2[i] = g3[i] * g2[i];
    }
    g.insert(g.end(), g2.begin(), g2.end() - 1);
  }

  mat ret = mat::id(n);
  long long i = 0;
  while (i + v <= k) {
    ret = g[i / v] * ret;
    i += v;
  }
  while (i < k) {
    mat m(n);
    for (int j = 0; j < n; j++)
      for (int l = 0; l < n; l++) m.set(j, l, a.get(j, l).eval(mint(i)));
    ret = m * ret;
    i++;
  }
  return ret;
}

/**
 * @brief 多項式行列の prefix product
 */
