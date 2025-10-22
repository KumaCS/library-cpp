#pragma once

template <class mint>
struct Factorial {
  static void reserve(int n) {
    inv(n);
    fact(n);
    fact_inv(n);
  }
  static mint inv(int n) {
    static long long mod = mint::get_mod();
    static vector<mint> _inv({0, 1});
    assert(n != 0);
    if (mod != mint::get_mod()) {
      mod = mint::get_mod();
      _inv = vector<mint>({0, 1});
    }
    if (_inv.size() <= n) _inv.reserve(n + 1);
    while (_inv.size() <= n) {
      long long k = _inv.size(), q = (mod + k - 1) / k;
      _inv.push_back(q * _inv[k * q - mod]);
    }
    return _inv[n];
  }
  static mint fact(int n) {
    static long long mod = mint::get_mod();
    static vector<mint> _fact({1, 1});
    assert(n >= 0);
    if (mod != mint::get_mod()) {
      mod = mint::get_mod();
      _fact = vector<mint>({1, 1});
    }
    if (_fact.size() <= n) _fact.reserve(n + 1);
    while (_fact.size() <= n) {
      long long k = _fact.size();
      _fact.push_back(_fact.back() * k);
    }
    return _fact[n];
  }
  static mint fact_inv(int n) {
    static long long mod = mint::get_mod();
    static vector<mint> _fact_inv({1, 1});
    assert(n >= 0);
    if (mod != mint::get_mod()) {
      mod = mint::get_mod();
      _fact_inv = vector<mint>({1, 1});
    }
    if (_fact_inv.size() <= n) _fact_inv.reserve(n + 1);
    while (_fact_inv.size() <= n) {
      long long k = _fact_inv.size();
      _fact_inv.push_back(_fact_inv.back() * inv(k));
    }
    return _fact_inv[n];
  }
  static mint binom(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact(n) * fact_inv(r) * fact_inv(n - r);
  }
  static mint binom_naive(int n, int r) {
    if (r < 0 || r > n) return 0;
    mint res = fact_inv(r);
    for (int i = 0; i < r; i++) res *= n - i;
    return res;
  }
  static mint multinom(const vector<int>& r) {
    int n = 0;
    for (auto& x : r) {
      if (x < 0) return 0;
      n += x;
    }
    mint res = fact(n);
    for (auto& x : r) res *= fact_inv(x);
    return res;
  }
  static mint P(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact(n) * fact_inv(n - r);
  }
  // partition n items to r groups (allow empty group)
  static mint H(int n, int r) {
    if (n < 0 || r < 0) return 0;
    return r == 0 ? 1 : binom(n + r - 1, r);
  }
};  // namespace Factorial
/**
 * @brief 階乗, 二項係数
 */