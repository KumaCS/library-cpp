#pragma once

#include "math/util.hpp"
#include "number-theory/prime-sieve.hpp"

namespace MobiusFunction {
using ll = long long;

vector<int> table(int n) {
  vector<int> mu(n + 1, 1);
  mu[0] = 0;
  auto lpf = PrimeSieve::lpf(n);
  for (int x = 2; x <= n; x++) {
    int p = lpf[x];
    if (x / p % p == 0)
      mu[x] = 0;
    else
      mu[x] = -mu[x / p];
  }
  return mu;
}

ll sum(ll n) {
  if (n <= 0) return 0;

  ll k = ceil(pow((long double)n, 2.0L / 3.0L));
  __int128 n2 = (__int128)n * n;
  auto enough = [&](ll x) { return (__int128)x * x * x >= n2; };
  while (k > 1 && enough(k - 1)) k--;
  while (!enough(k)) k++;
  assert(k <= numeric_limits<int>::max());

  int lim = (int)k;
  vector<ll> small(lim + 1);
  auto mu = table(lim);
  for (int i = 1; i <= lim; i++) small[i] = small[i - 1] + mu[i];

  ll len = n / k + (n % k != 0);
  vector<ll> large(len + 1);
  for (ll i = len; i >= 1; i--) {
    ll x = n / i;
    ll m = Math::isqrt(x);
    ll v = 1;
    for (ll j = 2; j <= m; j++) v -= i * j <= len ? large[i * j] : small[x / j];
    for (ll j = 1; j <= m; j++) v -= (x / j - m) * (small[j] - small[j - 1]);
    large[i] = v;
  }
  return large[1];
}
};  // namespace MobiusFunction

/**
 * @brief Mobius Function
 * @docs docs/number-theory/mobius-function.md
 */
