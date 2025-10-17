#pragma once

// sum{i=0}^{n-1}floor((a*i+b)/m)
template <class T>
T FloorSumUnsigned(unsigned long long n, unsigned long long m, unsigned long long a, unsigned long long b) {
  assert(m != 0);
  if (n == 0) return 0;
  T res = 0;
  while (true) {
    if (a >= m) {
      unsigned long long q = a / m;
      res += T(q) * (n / 2) * ((n - 1) | 1);
      a -= m * q;
    }
    if (b >= m) {
      unsigned long long q = b / m;
      res += T(q) * n;
      b -= m * q;
    }
    unsigned long long y = a * n + b;
    if (y < m) break;
    n = y / m, b = y - m * n;
    swap(a, m);
  }
  return res;
}

// sum{i=0}^{n-1}floor((a*i+b)/m)
template <class T>
T FloorSum(long long n, long long m, long long a, long long b) {
  assert(m != 0);
  if (n <= 0) return 0;
  if (m < 0) a = -a, b = -b, m = -m;
  T res = 0;
  if (a < 0) {
    long long q = (a + 1) / m - 1;
    res += T(q) * (n / 2) * ((n - 1) | 1);
    a -= m * q;
  }
  if (b < 0) {
    long long q = (b + 1) / m - 1;
    res += T(q) * n;
    b -= m * q;
  }
  return res + FloorSumUnsigned<T>(n, m, a, b);
}

/**
 * @brief Floor Sum
 * @docs docs/math/floor-sum.md
 */