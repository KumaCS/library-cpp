#pragma once

template <class T, T (*op)(T, T), T (*e)(), std::unsigned_integral U = uint64_t>
T FloorMonoidProduct(U n, U m, U a, U b, T x, T y, function<T(T, U)> pow = nullptr) {
  if (!pow) {
    pow = [](T t, U n) {
      T p = e();
      while (n) {
        if (n & 1) p = op(p, t);
        t = op(t, t);
        n >>= 1;
      }
      return p;
    };
  }
  assert(m != 0);
  T pl = e(), pr = e();
  while (true) {
    if (a >= m) {
      U q = a / m;
      x = op(x, pow(y, q));
      a -= m * q;
    }
    if (b >= m) {
      U q = b / m;
      pl = op(pl, pow(y, q));
      b -= m * q;
    }
    U c = a * n + b;
    if (c < m) {
      pl = op(pl, pow(x, n));
      break;
    }
    pr = op(op(y, pow(x, c % m / a)), pr);
    n = c / m - 1;
    b = m + a - b - 1;
    swap(a, m);
    swap(x, y);
  }
  return op(pl, pr);
}

/**
 * @brief モノイド版 Floor Sum
 * @docs docs/math/floor-monoid-product.md
 */