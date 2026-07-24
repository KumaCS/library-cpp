#pragma once

#include "number-theory/lucy-dp.hpp"

namespace PrimeResidue {
using ll = long long;

namespace internal {
template <class T>
T triangular(ll n) {
  if (n % 2 == 0) return T(n / 2) * T(n + 1);
  return T(n) * T((n + 1) / 2);
}

template <class T>
struct Value {
  vector<T> value;
  int point = -1;

  Value() = default;
  explicit Value(int m) : value(m) {}

  Value operator-(const Value& rhs) const {
    int m = value.size();
    Value ret(m);
    for (int k = 0; k < m; k++) ret.value[k] = value[k] - rhs.value[k];
    return ret;
  }

  Value& operator-=(const Value& rhs) {
    int m = value.size();
    for (int k = 0; k < m; k++) value[k] -= rhs.value[k];
    point = -1;
    return *this;
  }

  Value operator*(const Value& rhs) const {
    assert(point == -1 && rhs.point != -1);
    int m = value.size(), b = rhs.point;
    Value ret(m);
    for (int a = 0; a < m; a++) {
      int k = (ll)a * b % m;
      ret.value[k] += value[a] * rhs.value[b];
    }
    return ret;
  }
};

template <class T, class F, class G>
pair<vector<ll>, vector<vector<T>>> run(ll n, int m, F point_coefficient, G prefix_coefficient) {
  if (n == 0) return {};

  function<Value<T>(ll)> point_value = [&](ll x) {
    Value<T> v(m);
    int k = x % m;
    v.value[k] = point_coefficient(x);
    v.point = k;
    return v;
  };
  function<Value<T>(ll)> prefix_sum = [&](ll x) {
    Value<T> v(m);
    for (int k = 0; k < m; k++) v.value[k] = prefix_coefficient(x, k);
    return v;
  };

  auto [xs, values] = LucyDP<Value<T>>(n, point_value, prefix_sum);
  vector<vector<T>> result;
  result.reserve(values.size());
  for (auto& value : values) result.push_back(move(value.value));
  return {move(xs), move(result)};
}
};  // namespace internal

pair<vector<ll>, vector<vector<ll>>> count(ll n, int m) {
  assert(n >= 0 && m >= 1);
  return internal::run<ll>(n, m, [](ll) { return 1LL; }, [&](ll x, int k) {
    ll rem = x % m;
    return x / m + (k > 0 && k <= rem);
  });
}

template <class T = __int128_t>
pair<vector<ll>, vector<vector<T>>> sum(ll n, int m) {
  assert(n >= 0 && m >= 1);
  return internal::run<T>(n, m, [](ll x) { return T(x); }, [&](ll x, int k) {
    ll count = x / m + (k > 0 && k <= x % m);
    if (count == 0) return T(0);
    ll first = k == 0 ? m : k;
    return T(count) * T(first) + T(m) * internal::triangular<T>(count - 1);
  });
}
};  // namespace PrimeResidue

/**
 * @brief 素数の剰余類別集計
 * @docs docs/number-theory/prime-residue.md
 */
