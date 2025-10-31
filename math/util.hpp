#pragma once

namespace Math {
template <class T>
T safe_mod(T a, T b) {
  assert(b != 0);
  if (b < 0) a = -a, b = -b;
  a %= b;
  return a >= 0 ? a : a + b;
}
template <class T>
T floor(T a, T b) {
  assert(b != 0);
  if (b < 0) a = -a, b = -b;
  return a >= 0 ? a / b : (a + 1) / b - 1;
}
template <class T>
T ceil(T a, T b) {
  assert(b != 0);
  if (b < 0) a = -a, b = -b;
  return a > 0 ? (a - 1) / b + 1 : a / b;
}
long long isqrt(long long n) {
  if (n <= 0) return 0;
  long long x = sqrt(n);
  while ((x + 1) * (x + 1) <= n) x++;
  while (x * x > n) x--;
  return x;
}
// return g=gcd(a,b)
// a*x+b*y=g
// - b!=0 -> 0<=x<|b|/g
// - b=0  -> ax=g
template <class T>
T ext_gcd(T a, T b, T& x, T& y) {
  T a0 = a, b0 = b;
  bool sgn_a = a < 0, sgn_b = b < 0;
  if (sgn_a) a = -a;
  if (sgn_b) b = -b;
  if (b == 0) {
    x = sgn_a ? -1 : 1;
    y = 0;
    return a;
  }
  T x00 = 1, x01 = 0, x10 = 0, x11 = 1;
  while (b != 0) {
    T q = a / b, r = a - b * q;
    x00 -= q * x01;
    x10 -= q * x11;
    swap(x00, x01);
    swap(x10, x11);
    a = b, b = r;
  }
  x = x00, y = x10;
  if (sgn_a) x = -x;
  if (sgn_b) y = -y;
  if (b0 != 0) {
    a0 /= a, b0 /= a;
    if (b0 < 0) a0 = -a0, b0 = -b0;
    T q = x >= 0 ? x / b0 : (x + 1) / b0 - 1;
    x -= b0 * q;
    y += a0 * q;
  }
  return a;
}
template <class T>
T inv_mod(T x, T m) {
  x %= m;
  if (x < 0) x += m;
  T a = m, b = x;
  T y0 = 0, y1 = 1;
  while (b > 0) {
    T q = a / b;
    swap(a -= q * b, b);
    swap(y0 -= q * y1, y1);
  }
  if (y0 < 0) y0 += m / a;
  return y0;
}
template <class T>
T pow_mod(T x, T n, T m) {
  x = (x % m + m) % m;
  T y = 1;
  while (n) {
    if (n & 1) y = y * x % m;
    x = x * x % m;
    n >>= 1;
  }
  return y;
}
constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
  if (m == 1) return 0;
  unsigned int _m = (unsigned int)(m);
  unsigned long long r = 1;
  unsigned long long y = x % m;
  if (y >= m) y += m;
  while (n) {
    if (n & 1) r = (r * y) % _m;
    y = (y * y) % _m;
    n >>= 1;
  }
  return r;
}
constexpr bool is_prime_constexpr(int n) {
  if (n <= 1) return false;
  if (n == 2 || n == 7 || n == 61) return true;
  if (n % 2 == 0) return false;
  long long d = n - 1;
  while (d % 2 == 0) d /= 2;
  constexpr long long bases[3] = {2, 7, 61};
  for (long long a : bases) {
    long long t = d;
    long long y = pow_mod_constexpr(a, t, n);
    while (t != n - 1 && y != 1 && y != n - 1) {
      y = y * y % n;
      t <<= 1;
    }
    if (y != n - 1 && t % 2 == 0) {
      return false;
    }
  }
  return true;
}
template <int n>
constexpr bool is_prime = is_prime_constexpr(n);
};  // namespace Math