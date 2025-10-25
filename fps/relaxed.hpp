#pragma once
#include "modint/factorial.hpp"
#include "fps/formal-power-series.hpp"
#include "modint/mod-sqrt.hpp"

template <class mint>
class RelaxedMultiply {
  const int B = 6;
  using fps = FormalPowerSeries<mint>;
  int n;
  fps f, g, h;
  vector<fps> f0, g0;

 public:
  RelaxedMultiply() : n(0), f(1), g(1), f0(B), g0(B) {}
  mint append(mint a, mint b) {
    f[n] = a, g[n] = b;
    n++;
    int m = n & -n;
    int l = __builtin_ctz((unsigned int)m);
    if (n == m) {
      f.resize(2 * m);
      g.resize(2 * m);
      h.resize(2 * m);
      if (l < B) {
        for (int i = 0; i < m; i++)
          for (int j = m - 1 - i; j < m; j++)
            h[i + j] += f[i] * g[j];
      } else {
        auto f1 = f;
        f1.ntt();
        f0.push_back(fps(f1.begin(), f1.begin() + m));
        auto g1 = g;
        g1.ntt();
        g0.push_back(fps(g1.begin(), g1.begin() + m));
        for (int i = 0; i < 2 * m; i++) f1[i] *= g1[i];
        f1.intt();
        for (int i = m - 1; i < 2 * m - 1; i++) h[i] += f1[i];
      }
    } else {
      if (l < B) {
        int s = n - m;
        for (int i = 0; i < m; i++) {
          int t = m - 1 - i;
          for (int j = 0; j < m; j++)
            h[n - 1 + j] += f[s + i] * g[t + j] + g[s + i] * f[t + j];
        }
      } else {
        fps f1(2 * m), g1(2 * m), h1(2 * m);
        copy(f.begin() + (n - m), f.begin() + n, f1.begin());
        copy(g.begin() + (n - m), g.begin() + n, g1.begin());
        f1.ntt(), g1.ntt();
        for (int i = 0; i < 2 * m; i++) h1[i] += f1[i] * g0[l + 1][i] + f0[l + 1][i] * g1[i];
        h1.intt();
        for (int i = m - 1; i < 2 * m - 1; i++) h[n - m + i] += h1[i];
      }
    }
    return h[n - 1];
  }
};

template <class mint>
class SemiRelaxedMultiply {
  const int B = 6;
  using fps = FormalPowerSeries<mint>;
  int n, m0;
  fps f, g, h;
  vector<fps> g0;

 public:
  SemiRelaxedMultiply(const fps& g_) : n(0), m0(1 << B), f(1), g(g_) {
    while (m0 < g.size()) m0 <<= 1;
    g.resize(m0);
    for (int k = 1; k <= m0; k <<= 1) {
      fps g1(2 * k);
      copy(g.begin(), g.begin() + min(2 * k, m0), g1.begin());
      g1.ntt();
      g0.push_back(g1);
    }
  }
  mint append(mint a) {
    f[n] = a;
    n++;
    int m = n & -n;
    int l = __builtin_ctz((unsigned int)m);
    if (n == m) {
      f.resize(2 * m);
      h.resize(2 * m);
    }
    while (l >= g0.size()) {
      g0.push_back(g0.back());
      g0.back().ntt_doubling();
    }
    if (l < B) {
      int s = n - m;
      for (int i = 0; i < m; i++) {
        int t = m - 1 - i;
        for (int j = 0; j < m; j++)
          h[n - 1 + j] += f[s + i] * g[t + j];
      }
    } else {
      fps f1(2 * m);
      copy(f.begin() + (n - m), f.begin() + n, f1.begin());
      f1.ntt();
      for (int i = 0; i < 2 * m; i++) f1[i] *= g0[l][i];
      f1.intt();
      for (int i = m - 1; i < 2 * m - 1; i++) h[n - m + i] += f1[i];
    }
    return h[n - 1];
  }
};

// f(x)/g(x)
template <class mint>
class RelaxedDivide {
  RelaxedMultiply<mint> mul;
  int n;
  mint c, v;

 public:
  RelaxedDivide() : n(0) {}
  mint append(mint a, mint b) { return v = n++ == 0 ? a * (c = b.inv()) : (a - mul.append(v, b)) * c; }
};

template <class mint>
class RelaxedInv {
  RelaxedMultiply<mint> mul;
  int n;
  mint c, v;

 public:
  RelaxedInv() : n(0) {}
  mint append(mint a) { return v = n++ == 0 ? (c = a.inv()) : -mul.append(v, a) * c; }
};

template <class mint>
class RelaxedExp {
  using fact = Factorial<mint>;
  RelaxedMultiply<mint> mul;
  int n;
  mint v;

 public:
  RelaxedExp() : n(0) {}
  mint append(mint a) {
    if (n++ == 0) {
      assert(a == 0);
      v = 1;
    } else {
      v = mul.append((n - 1) * a, v) * fact::inv(n - 1);
    }
    return v;
  }
};

template <class mint>
class RelaxedLog {
  using fact = Factorial<mint>;
  RelaxedMultiply<mint> mul;
  int n;
  mint a0, v;

 public:
  RelaxedLog() : n(0) {}
  mint append(mint a) {
    if (n == 0) {
      assert(a == 1);
      n++;
      return 0;
    } else if (n == 1) {
      a0 = a, n++;
      return v = a;
    } else {
      v = n * a - mul.append(v, a0);
      a0 = a;
      return v * fact::inv(n++);
    }
  }
};

template <class mint>
class RelaxedSqrt {
  RelaxedMultiply<mint> mul;
  int n;
  mint c, v;

 public:
  RelaxedSqrt() : n(0) {}
  mint append(mint a) {
    if (n == 0) {
      long long sq = ModSqrt(a.val(), mint::get_mod());
      assert(sq != -1 && sq != 0);
      c = mint(2 * sq).inv();
      n++;
      return sq;
    } else {
      return v = (n++ == 1 ? a : a - mul.append(v, v)) * c;
    }
  }
};

/**
 * @brief Relaxed 畳み込み
 * @docs docs/fps/relaxed.md
 */