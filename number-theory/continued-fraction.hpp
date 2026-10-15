#pragma once

#include "math/util.hpp"

namespace ContinuedFraction {
template <class I>
struct Finite {
  vector<I> terms;
};
template <class I>
struct Periodic {
  vector<I> prefix, cycle;
};

template <class I = long long>
pair<I, I> calc(const vector<I>& terms, I a = 1, I b = 0) {
  for (int i = terms.size() - 1; i >= 0; i--) {
    swap(a, b);
    a += terms[i] * b;
  }
  return {a, b};
}
template <class I = long long>
pair<I, I> calc(const vector<I>& terms, pair<I, I> ab) { return calc(terms, ab.first, ab.second); }

template <class I = long long>
Periodic<I> sqrt(I n) {
  assert(n >= 1);
  I _sq = Math::isqrt(n);
  assert(_sq * _sq != n);
  I a = 0, b = 1, c = 1;
  map<array<I, 3>, int> mp;
  vector<I> xs;
  int p = -1;
  for (int i = 0;; i++) {
    if (mp.contains({a, b, c})) {
      p = mp[{a, b, c}];
      break;
    }
    mp[{a, b, c}] = i;
    assert(b != 0);
    I sq = Math::isqrt(n * b * b);
    I x = Math::floor(b > 0 ? a + sq : a - (sq + 1), c);
    xs.push_back(x);
    a -= c * x;
    I z = a * a - n * b * b;
    a *= c, b *= -c, c = z;
    if (c < 0) a = -a, b = -b, c = -c;
    I g = gcd(gcd(a, b), c);
    a /= g, b /= g, c /= g;
  }
  return Periodic{vector<I>(xs.begin(), xs.begin() + p), vector<I>(xs.begin() + p, xs.end())};
}
};  // namespace ContinuedFraction

/**
 * @brief 連分数
 * @docs docs/number-theory/continued-fraction.md
 */
