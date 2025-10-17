#pragma once
#include "math/util.hpp"
#include "math/floor-monoid-product.hpp"

template <class T, int D1, int D2>
struct PolynomialFloorSumMonoid {
  static constexpr int D = max(D1, D2);
  using M = PolynomialFloorSumMonoid;
  using P = array<array<T, D2 + 1>, D1 + 1>;
  T x, y;
  P f;
  static M e() { return {0, 0, P{}}; }
  static M op(M a, M b) {
    static T binom[D + 1][D + 1];
    if (binom[0][0] != T(1)) {
      binom[0][0] = T(1);
      for (int i = 0; i < D; i++)
        for (int j = 0; j <= i; j++) {
          binom[i + 1][j] += binom[i][j];
          binom[i + 1][j + 1] += binom[i][j];
        }
    }
    T pow_x[D1 + 1], pow_y[D2 + 1];
    pow_x[0] = 1, pow_y[0] = 1;
    for (int i = 0; i < D1; i++) pow_x[i + 1] = pow_x[i] * a.x;
    for (int i = 0; i < D2; i++) pow_y[i + 1] = pow_y[i] * a.y;
    for (int i = 0; i <= D1; i++)
      for (int j = 0; j <= D2; j++) {
        T v = b.f[i][j];
        for (int k = i + 1; k <= D1; k++)
          b.f[k][j] += v * pow_x[k - i] * binom[k][i];
      }
    for (int i = 0; i <= D1; i++)
      for (int j = 0; j <= D2; j++) {
        T v = b.f[i][j];
        for (int k = j; k <= D2; k++)
          a.f[i][k] += v * pow_y[k - j] * binom[k][j];
      }
    return {a.x + b.x, a.y + b.y, a.f};
  }
  static M elm_x() {
    M t = e();
    t.x = 1, t.f[0][0] = 1;
    return t;
  }
  static M elm_y() {
    M t = e();
    t.y = 1;
    return t;
  }
};

// enumerate sum{k=l}^{r-1}k^i*floor((a*k+b)/m))^j
template <class T, int D1, int D2, std::signed_integral I = int64_t>
array<array<T, D2 + 1>, D1 + 1> PolynomialFloorSum(I l, I r, I m, I a, I b) {
  assert(l <= r && m != 0);
  using U = conditional_t<is_same_v<I, __int128_t>, __uint128_t, uint64_t>;
  using M = PolynomialFloorSumMonoid<T, D1, D2>;
  using P = array<array<T, D2 + 1>, D1 + 1>;
  if (m < 0) m = -m, a = -a, b = -b;
  if (a < 0) {
    P c = PolynomialFloorSum<T, D1, D2, I>(-r + 1, -l + 1, m, -a, b);
    for (int i = 1; i <= D1; i += 2)
      for (int j = 0; j <= D2; j++)
        c[i][j] = -c[i][j];
    return c;
  }
  b += a * l;
  I q = Math::floor(b, m);
  b -= q * m;
  M t = M::e();
  t.x = l, t.y = q;
  M z = FloorMonoidProduct<M, M::op, M::e, U>(r - l, m, a, b, M::elm_x(), M::elm_y());
  return M::op(t, z).f;
}

// P(x,y): 2 variables polynomial, deg_x(P)<=D1, deg_y(Q)<=D2
// find sum{k=0}^{n-1}P(k,floor((a*k+b)/m))
template <class T, int D1, int D2, std::signed_integral I = int64_t>
T PolynomialFloorSum(array<array<T, D2 + 1>, D1 + 1> poly, I l, I r, I m, I a, I b) {
  using M = PolynomialFloorSumMonoid<T, D1, D2>;
  auto c = PolynomialFloorSum<T, D1, D2, I>(l, r, m, a, b);
  T res = 0;
  for (int i = 0; i <= D1; i++)
    for (int j = 0; j <= D2; j++)
      res += poly[i][j] * c[i][j];
  return res;
}

/**
 * @brief 多項式版 floor sum
 * @docs docs/math/polynomial-floor-sum.md
 */