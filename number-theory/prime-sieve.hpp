#pragma once

namespace PrimeSieve {
using ll = long long;

vector<int> lpf(int n) {
  assert(n >= 0);
  vector<int> ret(n + 1);
  for (size_t i = 0; i < ret.size(); i++) ret[i] = (int)i;
  for (int p = 2; (ll)p * p <= n; p++) {
    if (ret[p] != p) continue;
    for (ll x = (ll)p * p;; x += p) {
      if (ret[x] == x) ret[x] = p;
      if (n - x < p) break;
    }
  }
  return ret;
}

vector<int> table(int n) {
  assert(n >= 0);
  vector<bool> composite(n + 1, false);
  for (int p = 2; (ll)p * p <= n; p += (p & 1) + 1) {
    if (composite[p]) continue;
    for (ll x = (ll)p * p;; x += p) {
      composite[x] = true;
      if (n - x < p) break;
    }
  }
  vector<int> ps;
  for (int p = 2; p <= n;) {
    if (!composite[p]) ps.push_back(p);
    int step = (p & 1) + 1;
    if (n - p < step) break;
    p += step;
  }
  return ps;
}

vector<vector<pair<ll, int>>> factorize(int n) {
  assert(n >= 0);
  vector<vector<pair<ll, int>>> factors(n + 1);
  auto lp = lpf(n);
  for (int x = 2; x <= n;) {
    int y = x;
    while (y > 1) {
      int p = lp[y], e = 0;
      while (y % p == 0) y /= p, e++;
      factors[x].emplace_back(p, e);
    }
    if (x == n) break;
    x++;
  }
  return factors;
}
};  // namespace PrimeSieve

/**
 * @brief 素数篩
 * @docs docs/number-theory/prime-sieve.md
 */
