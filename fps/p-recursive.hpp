#pragma once
#include "fps/formal-power-series.hpp"
#include "matrix/polynomial-matrix-prefix-product.hpp"

namespace p_recursive {

template <class T>
vector<T> NullVector(vector<vector<T>> a) {
  int h = a.size(), w = a[0].size(), rank = 0;
  vector<int> pivot;
  for (int j = 0; j < w && rank < h; j++) {
    int k = rank;
    while (k < h && a[k][j] == T{}) k++;
    if (k == h) continue;
    swap(a[rank], a[k]);
    T iv = T(1) / a[rank][j];
    for (int l = j; l < w; l++) a[rank][l] *= iv;
    for (int i = 0; i < h; i++) {
      if (i == rank || a[i][j] == T{}) continue;
      T c = a[i][j];
      for (int l = j; l < w; l++) a[i][l] -= c * a[rank][l];
    }
    pivot.push_back(j);
    rank++;
  }
  if (rank == w) return {};
  vector<bool> is_pivot(w, false);
  for (int j : pivot) is_pivot[j] = true;
  int free = 0;
  while (is_pivot[free]) free++;
  vector<T> x(w);
  x[free] = 1;
  for (int i = 0; i < rank; i++) x[pivot[i]] = -a[i][free];
  return x;
}

}  // namespace p_recursive

// sum[j=0...r] f[j](i) a[i+j] = 0 を満たす f を降順に返す
template <class mint>
vector<FormalPowerSeries<mint>> FindPRecursive(const vector<mint>& a, int d) {
  using fps = FormalPowerSeries<mint>;
  assert(d >= 0);
  int n = a.size();
  int r = (n + 2) / (d + 2) - 1;
  if (r <= 0) return {};
  int m = (r + 1) * (d + 1);
  vector<vector<mint>> mat(m - 1, vector<mint>(m));
  for (int i = 0; i < m - 1; i++) {
    for (int j = 0; j <= r; j++) {
      mint x = 1;
      for (int l = 0; l <= d; l++) {
        mat[i][(d + 1) * j + l] = x * a[i + j];
        x *= i + j;
      }
    }
  }
  auto c = p_recursive::NullVector(mat);
  if (c.empty()) return {};
  while ((int)c.size() > d + 1 &&
         all_of(c.end() - d - 1, c.end(), [](mint x) { return x == mint(0); }))
    c.erase(c.end() - d - 1, c.end());
  vector<fps> ret;
  for (int i = 0, j = 0; i < (int)c.size(); i += d + 1, j++) {
    fps f{1}, base{mint(j), mint(1)}, sum;
    for (int l = 0; l <= d; l++) {
      sum += f * c[i + l];
      f *= base;
    }
    sum.shrink();
    ret.push_back(sum);
  }
  reverse(ret.begin(), ret.end());
  return ret;
}

template <class mint>
mint PRecursiveTerm(const vector<mint>& a, long long k, int d) {
  if (k < (long long)a.size()) return a[k];
  if (all_of(a.begin(), a.end(), [](mint x) { return x == mint(0); })) return 0;
  auto f = FindPRecursive(a, d);
  assert(f.size() >= 2);
  int r = f.size() - 1;
  Matrix<FormalPowerSeries<mint>> m(r), denom(1);
  for (int i = 0; i < r; i++) m.set(0, i, -f[i + 1]);
  for (int i = 1; i < r; i++) m.set(i, i - 1, f[0]);
  denom.set(0, 0, f[0]);
  Matrix<mint> init(r, 1);
  for (int i = 0; i < r; i++) init.set(i, 0, a[r - 1 - i]);
  mint ret = (PolynomialMatrixPrefixProduct(m, k - r + 1) * init).get(0, 0);
  ret /= PolynomialMatrixPrefixProduct(denom, k - r + 1).get(0, 0);
  return ret;
}

template <class mint>
vector<mint> EnumeratePRecursive(const vector<mint>& a, long long n, int d) {
  assert(n >= 0);
  if (n <= (long long)a.size()) return vector<mint>(a.begin(), a.begin() + n);
  if (all_of(a.begin(), a.end(), [](mint x) { return x == mint(0); })) return vector<mint>(n);
  auto f = FindPRecursive(a, d);
  if (f.size() < 2) return {};
  int r = f.size() - 1;
  reverse(f.begin(), f.end());
  vector<mint> ret(a);
  ret.resize(n);
  for (long long k = a.size(); k < n; k++) {
    long long i = k - r;
    mint sum = 0;
    for (int j = 0; j < r; j++) sum += ret[i + j] * f[j].eval(mint(i));
    mint c = f[r].eval(mint(i));
    assert(c != mint(0));
    ret[k] = -sum / c;
  }
  return ret;
}

template <class mint>
mint PRecursiveTerm(const vector<mint>& a, long long k) {
  if (k < (long long)a.size()) return a[k];
  if (all_of(a.begin(), a.end(), [](mint x) { return x == mint(0); })) return 0;
  assert(a.size() >= 2);
  vector<mint> b(a.begin(), a.end() - 1);
  int n = a.size() - 1;
  for (int d = 0; (n + 2) / (d + 2) > 1; d++) {
    auto f = FindPRecursive(b, d);
    if (f.size() < 2) continue;
    auto c = EnumeratePRecursive(b, n + 1, d);
    if (!c.empty() && c.back() == a.back()) return PRecursiveTerm(a, k, d);
  }
  assert(false);
  return 0;
}

/**
 * @brief P-recursive
 * @docs docs/fps/p-recursive.md
 */
