#pragma once
#include "math/util.hpp"

template <class T>
T MinOfModOfLinear(T n, T m, T a, T b) {
  assert(n > 0 && m > 0);
  auto [xs, dxs] = PrefixMinOfModOfLinear(a, b, m);
  if (xs.back() < n) return (a * xs.back() + b) % m;
  int i = 0;
  while (xs[i + 1] < n) i++;
  T t = Math::ceil(n - xs[i], dxs[i]) - 1;
  return (a * (xs[i] + t * dxs[i]) + b) % m;
}

template <class T>
pair<vector<T>, vector<T>> PrefixMinOfModOfLinear(T a, T b, T mod) {
  assert(0 <= a && a < mod);
  assert(0 <= b && b < mod);
  T g = gcd(a, mod);
  a /= g, b /= g, mod /= g;

  vector<T> xs{0}, dxs;
  T la = 0, lb = 1, ra = 1, rb = 1;
  T l = mod - a, r = a;
  T x = 0, y = b;
  while (y != 0) {
    T k = r / l;
    r -= l * k;
    if (r == 0) {
      --k;
      r = l;
    }
    ra += k * la, rb += k * lb;
    while (true) {
      T k = max(T(0), Math::ceil(l - y, r));
      if (l - k * r <= 0) break;
      l -= k * r;
      la += k * ra, lb += k * rb;
      k = y / l;
      y -= k * l;
      x += lb * k;
      xs.push_back(x);
      dxs.push_back(lb);
    }
    k = l / r;
    l -= k * r;
    la += k * ra, lb += k * rb;
    assert(la >= 0 && lb >= 0 && ra >= 0 && rb >= 0);
  }
  return {xs, dxs};
}

/**
 * @brief Min of Mod of Linear
 * @docs docs/math/min-of-mod-of-linear.md
 */