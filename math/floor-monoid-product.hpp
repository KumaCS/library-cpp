#pragma once
#include "algebraic-structure/monoid.hpp"

template <class M, std::unsigned_integral U = uint64_t>
REQUIRES(Monoid<M>)
typename M::value_type FloorMonoidProduct(U n, U m, U a, U b, typename M::value_type x, typename M::value_type y,
                                          function<typename M::value_type(typename M::value_type, U)> pow = nullptr) {
  using T = typename M::value_type;
  if (!pow) {
    pow = [](T t, U n) {
      T p = M::e();
      while (n) {
        if (n & 1) p = M::op(p, t);
        t = M::op(t, t);
        n >>= 1;
      }
      return p;
    };
  }
  assert(m != 0);
  T pl = M::e(), pr = M::e();
  while (true) {
    if (a >= m) {
      U q = a / m;
      x = M::op(x, pow(y, q));
      a -= m * q;
    }
    if (b >= m) {
      U q = b / m;
      pl = M::op(pl, pow(y, q));
      b -= m * q;
    }
    U c = a * n + b;
    if (c < m) {
      pl = M::op(pl, pow(x, n));
      break;
    }
    pr = M::op(M::op(y, pow(x, c % m / a)), pr);
    n = c / m - 1;
    b = m + a - b - 1;
    swap(a, m);
    swap(x, y);
  }
  return M::op(pl, pr);
}

/**
 * @brief モノイド版 Floor Sum
 * @docs docs/math/floor-monoid-product.md
 */
