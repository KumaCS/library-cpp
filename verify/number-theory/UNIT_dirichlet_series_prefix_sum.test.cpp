#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "modint/modint.hpp"
#include "number-theory/dirichlet-series-prefix-sum.hpp"

using mint = ModInt998244353;
using DP = DirichletSeriesPrefixSum<mint>;
using u64 = uint64_t;

bool power_le(u64 x, size_t k, u64 n) {
  u64 y = 1;
  rep(_, 0, k) {
    if (y > n / x) return false;
    y *= x;
  }
  return true;
}

u64 floor_root(u64 n, size_t k) {
  if (k == 1) return n;
  u64 ok = 0, ng = n == numeric_limits<u64>::max() ? n : n + 1;
  while (ok + 1 < ng) {
    u64 x = ok + (ng - ok) / 2;
    (power_le(x, k, n) ? ok : ng) = x;
  }
  return ok;
}

void check(u64 n, size_t k) {
  DP z = DP::zeta_mul(n, k);
  vector<mint> expected(z.K + 1);
  for (u64 x = 1;; x++) {
    u64 y = 1;
    rep(_, 0, k) {
      if (y > z.K / x) {
        y = z.K + 1;
        break;
      }
      y *= x;
    }
    if (y > z.K) break;
    expected[y] = 1;
  }
  for (size_t i = 1; i < expected.size(); i++) expected[i] += expected[i - 1];
  for (size_t i = 1; i <= z.K; i++) {
    assert(z.a[i] == expected[i] - expected[i - 1]);
    assert(z.s[i] == expected[i]);
  }
  for (size_t i = 1; i <= z.L; i++) assert(z.S[i] == mint(floor_root(n / i, k)));
}

void check_values(const DP& f, const vector<mint>& values) {
  vector<mint> sums(values);
  for (size_t i = 1; i < sums.size(); i++) sums[i] += sums[i - 1];
  for (size_t i = 1; i <= f.K; i++) {
    assert(f.a[i] == values[i]);
    assert(f.s[i] == sums[i]);
  }
  for (size_t i = 1; i <= f.L; i++) assert(f.S[i] == sums[f.N / i]);
}

void test_updates() {
  mt19937 rng(1234567);
  for (u64 n : {1, 2, 3, 4, 15, 16, 17, 64, 257}) {
    DP f(n);
    vector<mint> values(n + 1);
    check_values(f, values);
    for (int tc = 0; tc < 100; tc++) {
      u64 x = rng() % (n + 2) + 1;
      mint v = (int)(rng() % 21) - 10;
      assert(&f.add(x, v) == &f);
      if (x <= n) values[x] += v;
      check_values(f, values);
      if (tc % 5 == 0) {
        u64 d = tc % 10 == 0 ? 1 : rng() % (n + 2) + 1;
        vector<mint> shifted(n + 1);
        for (u64 i = 1; i * d <= n; i++) shifted[i * d] = values[i];
        assert(&f.shift(d) == &f);
        values = shifted;
        check_values(f, values);
      }
    }
    DP g = DP::id(n);
    vector<mint> unit(n + 1);
    unit[1] = 1;
    check_values(g, unit);
    check_values(f + g, [&] {
      auto a = values;
      a[1] += 1;
      return a;
    }());
    auto h = f + g;
    h -= g;
    check_values(h, values);
    h *= mint(-3);
    auto scaled = values;
    for (auto& x : scaled) x *= -3;
    check_values(h, scaled);
    for (size_t k = 0; k <= 3; k++) {
      vector<mint> a(n + 1), rising(n + 1), falling(n + 1);
      for (u64 x = 1; x <= n; x++) {
        a[x] = mint(x).pow(k);
        rising[x] = falling[x] = 1;
        for (size_t j = 0; j < k; j++) {
          rising[x] *= mint(x + j) / mint(j + 1);
          falling[x] *= mint((long long)x - (long long)j) / mint(j + 1);
        }
      }
      check_values(DP::zeta(n, k), a);
      check_values(DP::rising(n, k), rising);
      check_values(DP::falling(n, k), falling);
    }
  }
}

int main() {
  test_updates();
  for (u64 n : {1, 2, 3, 4, 7, 8, 9, 15, 16, 17, 100, 1000, 10000}) {
    for (size_t k : {1, 2, 3, 4, 5, 10, 62, 63, 64, 100}) check(n, k);
  }
  for (size_t k : {1, 2, 3, 4, 5, 10, 32, 63, 64, 100}) check(10000000000ULL, k);

  int A, B;
  in(A, B);
  out(A + B);
}
