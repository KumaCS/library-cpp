#pragma once

// https://maspypy.com/dirichlet-%E7%A9%8D%E3%81%A8%E3%80%81%E6%95%B0%E8%AB%96%E9%96%A2%E6%95%B0%E3%81%AE%E7%B4%AF%E7%A9%8D%E5%92%8C
/**
 * @brief Dirichlet 積の prefix sum
 */
template <class mint>
struct DirichletSeriesPrefixSum {
  using DP = DirichletSeriesPrefixSum<mint>;
  using u64 = uint64_t;
  using i64 = int64_t;

 public:
  u64 N;
  size_t K, L;
  vector<mint> a, s, S;

  DirichletSeriesPrefixSum(u64 n)
      : N(n),
        K(max(sqrt(N), pow(max(1.0, N / log(N)), 2.0 / 3))),
        L((N - 1) / K + 1) {
    a.assign(K + 1, 0);
    s.assign(K + 1, 0);
    S.assign(L + 1, 0);
  }
  DirichletSeriesPrefixSum(const DP& d)
      : N(d.N), K(d.K), L(d.L), a(d.a), s(d.s), S(d.S) {}
  static DP id(u64 n) {
    DP z(n);
    return z.add(1, 1);
  }

  // zeta(s-k)
  static DP zeta(u64 n, size_t k = 0) {
    assert(k <= 2);
    DP z(n);
    for (size_t i = 1; i <= z.K; i++) z.a[i] = mint((int)i).pow(k);
    for (size_t i = 1; i <= z.K; i++) z.s[i] = z.s[i - 1] + z.a[i];
    for (size_t i = 1; i <= z.L; i++) {
      u64 x = n / i;
      if (k == 0)
        z.S[i] = x;
      else if (k == 1)
        z.S[i] = mint(x | 1) * mint((x + 1) / 2);
      else if (k == 2) {
        array<u64, 3> xs{x, x + 1, 2 * x + 1};
        xs[x & 1] /= 2;
        xs[(3 - (x % 3)) % 3] /= 3;
        z.S[i] = mint(xs[0]) * mint(xs[1]) * mint(xs[2]);
      }
    }
    return z;
  }

  // n(n+1)...(n+k-1)/k!
  static DP rising(u64 n, size_t k) {
    if (k == 0) return zeta(n);
    DP z(n);
    for (size_t i = 1; i <= z.K; i++) z.a[i] = rising_mint(i, k);
    for (size_t i = 1; i <= z.K; i++) z.s[i] = z.s[i - 1] + z.a[i];
    for (size_t i = 1; i <= z.L; i++) {
      u64 x = n / i;
      z.S[i] = rising_mint(x, k + 1);
    }
    return z;
  }
  // n(n-1)...(n-k+1)/k!
  static DP falling(u64 n, size_t k) {
    if (k == 0) return zeta(n);
    DP z(n);
    for (size_t i = 1; i <= z.K; i++) z.a[i] = falling_mint(i, k);
    for (size_t i = 1; i <= z.K; i++) z.s[i] = z.s[i - 1] + z.a[i];
    for (size_t i = 1; i <= z.L; i++) {
      u64 x = n / i;
      z.S[i] = falling_mint(x + 1, k + 1);  // -falling_mint(1, k + 1);
    }
    return z;
  }

  inline void calc_small_sum() {
    for (size_t i = 1; i <= K; i++) s[i] = s[i - 1] + a[i];
  }

  // += v*x^(-s)
  DP add(u64 x, mint v) {
    DP f(*this);
    if (1 <= x && x <= K) {
      f.a[x] += v;
      for (size_t i = x; i <= K; i++) f.s[i] += v;
    }
    for (size_t i = 1; i <= L; i++)
      if (x <= N / i) f.S[i] += v;
    return f;
  }
  // *= x^(-s)
  DP shift(u64 x) {
    DP f(N);
    for (size_t i = 1; i <= K / x; i++) f.a[i * x] = a[i];
    f.calc_small_sum();
    for (size_t i = 1; i <= L; i++) {
      u64 y = N / i / x;
      f.S[i] = y <= K ? s[y] : S[i * x];
    }
    return f;
  }
  DP inv() { return id(N) / DP(*this); }

  DP& operator+=(const DP& r) {
    assert(N == r.N);
    for (size_t i = 1; i <= K; i++) a[i] += r.a[i];
    for (size_t i = 1; i <= K; i++) s[i] += r.s[i];
    for (size_t i = 1; i <= L; i++) S[i] += r.S[i];
    return *this;
  }
  DP& operator-=(const DP& r) {
    assert(N == r.N);
    for (size_t i = 1; i <= K; i++) a[i] -= r.a[i];
    for (size_t i = 1; i <= K; i++) s[i] -= r.s[i];
    for (size_t i = 1; i <= L; i++) S[i] -= r.S[i];
    return *this;
  }
  DP& operator*=(const mint& r) {
    for (auto& v : a) v *= r;
    for (auto& v : s) v *= r;
    for (auto& v : S) v *= r;
    return *this;
  }
  DP operator+(const DP& r) const { return DP(*this) += r; }
  DP operator-(const DP& r) const { return DP(*this) -= r; }
  DP operator*(const mint& r) const { return DP(*this) *= r; }

  friend DP operator*(const DP& l, const DP& r) {
    DP z(l);
    const int N = z.N;
    const int K = z.K;
    const int L = z.L;
    for (size_t i = 1; i <= L; i++) {
      mint v = 0;
      size_t m = sqrt(N / i);
      for (size_t x = 1; x <= m; x++) {
        u64 t = N / i / x;
        v += l.a[x] * (t <= K ? r.s[t] : r.S[i * x]);
      }
      for (size_t y = 1; y <= m; y++) {
        u64 t = N / i / y;
        v += r.a[y] * ((t <= K ? l.s[t] : l.S[i * y]) - l.s[m]);
      }
      z.S[i] = v;
    }
    for (size_t i = K; i >= 1; i--) {
      for (size_t j = 2; u64(i) * j <= K; j++) z.a[i * j] += l.a[i] * r.a[j];
      z.a[i] *= r.a[1];
    }
    z.calc_small_sum();
    return z;
  }
  friend DP operator/(const DP& l, const DP& r) {
    DP z(l);
    const int N = z.N;
    const int K = z.K;
    const int L = z.L;
    mint inv = r.a[1].inv();
    for (size_t i = 1; i <= K; i++) {
      z.a[i] *= inv;
      for (size_t j = 2; u64(i) * j <= K; j++) z.a[i * j] -= z.a[i] * r.a[j];
      z.s[i] = z.s[i - 1] + z.a[i];
    }
    for (size_t i = L; i >= 1; i--) {
      size_t m = sqrt(N / i);
      for (size_t x = 1; x <= m; x++) {
        u64 t = N / i / x;
        z.S[i] -= z.a[x] * (t <= K ? r.s[t] : r.S[i * x]);
      }
      for (size_t y = 2; y <= m; y++) {
        u64 t = N / i / y;
        z.S[i] -= r.a[y] * ((t <= K ? z.s[t] : z.S[i * y]) - z.s[m]);
      }
      z.S[i] *= inv;
      z.S[i] += z.s[m];
    }
    return z;
  }
  DP& operator*=(const DP& r) {
    *this = DP(*this) * r;
    return *this;
  }
  DP& operator/=(const DP& r) {
    *this = DP(*this) / r;
    return *this;
  }

  // sparse
  DP& operator*=(const vector<pair<u64, mint>>& r) {
    DP f(N);
    for (auto [x, v] : r) {
      for (size_t i = 1; i <= K / x; i++) f.a[i * x] += v * a[i];
      for (size_t i = 1; i <= L; i++) {
        u64 t = N / i / x;
        f.S[i] += v * (t <= K ? s[t] : f.S[i * x]);
      }
    }
    f.calc_small_sum();
    return f;
  }

  friend ostream& operator<<(ostream& os, const DP& f) {
    os << "a: ";
    for (size_t i = 1; i <= f.K; i++) os << f.a[i].val() << ",\n"[i == f.K];
    os << "s: ";
    for (size_t i = 1; i <= f.K; i++) os << f.s[i].val() << ",\n"[i == f.K];
    os << "S: ";
    for (size_t i = f.L; i >= 1; i--)
      os << (f.N / i) << ":" << f.S[i].val() << ",\n"[i == 1];
    return os;
  };

 private:
  static mint rising_mint(i64 x, size_t k) {
    vector<i64> xs(k);
    iota(xs.begin(), xs.end(), x);
    for (i64 v = 2; v <= k; v++) {
      i64 w = v;
      for (auto& y : xs) {
        i64 g = gcd(w, y);
        w /= g;
        y /= g;
      }
      assert(w == 1);
    }
    mint z = 1;
    for (auto& y : xs) z *= y;
    return z;
  }
  static mint falling_mint(i64 x, size_t k) {
    return rising_mint(x - k + 1, k);
  }
};