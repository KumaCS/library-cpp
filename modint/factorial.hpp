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
    static vector<mint> buf({0, 1});
    assert(n != 0);
    if (mod != mint::get_mod()) {
      mod = mint::get_mod();
      buf = vector<mint>({0, 1});
    }
    if ((int)buf.size() <= n) buf.reserve(n + 1);
    while ((int)buf.size() <= n) {
      long long k = buf.size(), q = (mod + k - 1) / k;
      buf.push_back(q * buf[k * q - mod]);
    }
    return buf[n];
  }
  static mint fact(int n) {
    static long long mod = mint::get_mod();
    static vector<mint> buf({1, 1});
    assert(n >= 0);
    if (mod != mint::get_mod()) {
      mod = mint::get_mod();
      buf = vector<mint>({1, 1});
    }
    if ((int)buf.size() <= n) buf.reserve(n + 1);
    while ((int)buf.size() <= n) {
      long long k = buf.size();
      buf.push_back(buf.back() * k);
    }
    return buf[n];
  }
  static mint fact_inv(int n) {
    static long long mod = mint::get_mod();
    static vector<mint> buf({1, 1});
    assert(n >= 0);
    if (mod != mint::get_mod()) {
      mod = mint::get_mod();
      buf = vector<mint>({1, 1});
    }
    if ((int)buf.size() <= n) {
      inv(n);
      buf.reserve(n + 1);
    }
    while ((int)buf.size() <= n) {
      long long k = buf.size();
      buf.push_back(buf.back() * inv(k));
    }
    return buf[n];
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
};
/**
 * @brief 階乗, 二項係数
 */