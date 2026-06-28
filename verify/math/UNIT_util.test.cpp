#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "math/util.hpp"

void test_division() {
  rep(a, -100, 101) rep(b, -100, 101) {
    if (b == 0) continue;
    int m = abs(b);
    int r = Math::safe_mod(a, b);
    assert(0 <= r && r < m);
    assert(((b < 0 ? -a : a) - r) % m == 0);

    int f = Math::floor(a, b);
    int c = Math::ceil(a, b);
    long double v = (long double)a / b;
    assert(f <= v && v < f + 1);
    assert(c - 1 < v && v <= c);
  }
}

void test_roots() {
  auto check_sqrt = [](long long n) {
    long long x = Math::isqrt(n);
    assert((__int128)x * x <= n);
    assert((__int128)(x + 1) * (x + 1) > n);
  };
  rep(n, 0, 100000) check_sqrt(n);
  for (long long n : {1000000000000LL, 9223372036854775807LL}) check_sqrt(n);

  rep(n, 0, 10000) rep(k, 1, 11) {
    long long x = Math::floor_root(n, k);
    auto leq = [&](long long a) {
      __int128 p = 1;
      rep(i, 0, k) p *= a;
      return p <= n;
    };
    assert(leq(x));
    assert(!leq(x + 1));
  }
  assert(Math::floor_root(9223372036854775807LL, 2) == 3037000499LL);
}

void test_number_theory() {
  rep(a, -100, 101) rep(b, -100, 101) {
    if (a == 0 && b == 0) continue;
    long long x, y;
    long long g = Math::ext_gcd((long long)a, (long long)b, x, y);
    assert(g == gcd(abs(a), abs(b)));
    assert((long long)a * x + (long long)b * y == g);
  }

  rep(m, 2, 200) rep(a, 1, m) {
    if (gcd(a, m) == 1) assert(a * Math::inv_mod(a, m) % m == 1);
  }
  rep(x, -20, 21) rep(n, 0, 20) rep(m, 1, 50) {
    long long expected = 1 % m;
    rep(i, 0, n) expected = expected * Math::safe_mod(x, m) % m;
    assert(Math::pow_mod(x, n, m) == expected);
  }
  rep(n, 0, 1000) {
    bool prime = n >= 2;
    for (int d = 2; d * d <= n; d++) prime &= n % d != 0;
    assert(Math::is_prime_constexpr(n) == prime);
  }
}

int main() {
  test_division();
  test_roots();
  test_number_theory();

  int a, b;
  in(a, b);
  out(a + b);
}
