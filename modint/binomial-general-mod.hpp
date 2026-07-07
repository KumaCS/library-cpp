#pragma once

#include "math/barrett.hpp"

struct BinomialGeneralMod {
  using u32 = unsigned int;
  using u64 = unsigned long long;
  BinomialGeneralMod() : m(1) {}
  BinomialGeneralMod(u32 mod) : m(mod) {
    u32 m1 = m;
    for (u32 p = 2; (u64)p * p <= m1; p += (p & 1) + 1) {
      if (m1 % p == 0) add_prime_power(p, m1);
    }
    if (m1 > 1) add_prime_power(m1, m1);
    u32 crt_mod = 1;
    for (u32 q : qs) {
      crt_inv.push_back(inv_mod(crt_mod % q, q));
      crt_mod *= q;
    }
  }
  u32 get_mod() const { return m; }
  u32 binom(u64 n, u64 k) const {
    if (n < k) return 0;
    u32 val = 0, mod = 1;
    for (u32 i = 0; i < ps.size(); i++) {
      u32 p = ps[i], e = es[i], q = qs[i];
      auto& f = fs[i];
      auto& fi = fis[i];
      const barrett& bt = brs[i];
      u32 val1 = 1;
      u64 e1 = 0;
      for (u64 x = n; x;) {
        val1 = bt.mul(bt.mul(val1, f[x % q]), block_pow(bt, f[q - 1], x / q));
        e1 += x /= p;
      }
      for (u64 x = k; x;) {
        val1 = bt.mul(bt.mul(val1, fi[x % q]), block_pow(bt, fi[q - 1], x / q));
        e1 -= x /= p;
      }
      for (u64 x = n - k; x;) {
        val1 = bt.mul(bt.mul(val1, fi[x % q]), block_pow(bt, fi[q - 1], x / q));
        e1 -= x /= p;
      }
      val1 = e1 >= e ? 0 : bt.mul(val1, pow(bt, p, e1));
      val += (u64)bt.mul(val1 + q - val % q, crt_inv[i]) * mod;
      mod *= q;
    }
    return val;
  }

 private:
  const u32 m;
  vector<u32> ps, es, qs, crt_inv;
  vector<barrett> brs;
  vector<vector<u32>> fs, fis;
  void add_prime_power(u32 p, u32& m1) {
    u32 e = 0, q = 1;
    while (m1 % p == 0) m1 /= p, e++, q *= p;
    barrett bt(q);
    ps.push_back(p);
    es.push_back(e);
    qs.push_back(q);
    brs.push_back(bt);
    vector<u32> f(q, 1), fi(q, 1);
    for (u32 i = 1; i < q; i++) f[i] = i % p == 0 ? f[i - 1] : bt.mul(f[i - 1], i);
    fs.push_back(f);
    fi[q - 1] = inv_mod(f[q - 1], q);
    for (u32 i = q - 1; i > 0; i--) fi[i - 1] = i % p == 0 ? fi[i] : bt.mul(fi[i], i);
    fis.push_back(fi);
  }
  u32 block_pow(const barrett& bt, u32 x, u64 n) const {
    u32 mod = bt.umod();
    if (x == 1 || mod == 1) return 1 % mod;
    if (x + 1 == mod) return n % 2 ? x : 1;
    return pow(bt, x, n);
  }
  u32 pow(const barrett& bt, u32 x, u64 n) const {
    u32 y = 1;
    while (n) {
      if (n & 1) y = bt.mul(x, y);
      x = bt.mul(x, x);
      n >>= 1;
    }
    return y;
  }
  u32 inv_mod(u32 a, u32 mod) const {
    long long x = a, y = mod;
    long long u = 1, v = 0;
    while (y) {
      long long t = x / y;
      swap(x -= t * y, y);
      swap(u -= t * v, v);
    }
    if (u < 0) u += mod;
    return u;
  }
};

/**
 * @brief 一般 mod での二項係数
 * @docs docs/modint/binomial-general-mod.md
 */
