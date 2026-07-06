#pragma once

#include "number-theory/mobius-function.hpp"
#include "math/util.hpp"

long long CountSquareFree(long long n) {
  using ll = long long;
  if (n <= 0) return 0;
  ll ret = 0;
  if (n < 100) {
    auto mu = MobiusFunction::table((int)n);
    for (int i = 1; i <= n; i++) ret += n / i / i * mu[i];
  } else {
    ll l = Math::floor_root(n, 5);
    ll d = Math::floor_root(n / l, 2);
    auto mu = MobiusFunction::table(d);
    for (int i = 1; i <= d; i++) ret += n / i / i * mu[i];
    for (int i = 1; i <= d; i++) mu[i] += mu[i - 1];  // mu 自体はもういらないので使い回し
    vector<ll> a(l + 1);
    for (int k = l; k > 0; k--) {
      ll x = Math::floor_root(n / k, 2);
      ll sq = Math::floor_root(x, 2);
      ll m = x / (sq + 1);
      ll v = 1;
      for (ll i = 1; i <= m; i++) v -= (x / i - x / (i + 1)) * mu[i];
      for (ll i = 2; i <= sq; i++) v -= x / i <= d ? mu[x / i] : a[k * i * i];
      a[k] = v;
      if (k < l) ret += a[k];
    }
    ret -= (l - 1) * a[l];
  }
  return ret;
}

/**
 * @brief Count Square Free
 * @docs docs/number-theory/count-square-free.md
 */