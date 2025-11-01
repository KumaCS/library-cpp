#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "modint/dynamic-modint.hpp"

template <int id>
void test(int mod) {
  using mint = DynamicModInt<id>;
  mint::set_mod(mod);
  unsigned int m = mint::get_mod();
  rep(i, -100, 100) {
    ll n = i * 100000000ll;
    assert(mint(n).val() == ((n % m) + m) % m);
  }
  {
    ll a = 314, b = 271;
    rep(i, 0, 100) {
      mint x(a), y(b);
      assert((x + y).val() == (a + b) % m);
      assert((x - y).val() == (a - b + m) % m);
      assert((x * y).val() == (a * b) % m);
      if (gcd(m, b) == 1) {
        if ((x / y) * y != x) show(m, x, y, x / y, x / y * y);
        assert((x / y) * y == x);
      }
      mint z = 1;
      rep(j, 0, 100) {
        assert(z == x.pow(j));
        z *= x;
      }
      a = (a * 159 + 265) % m;
      b = (b * 828 + 182) % m;
    }
  }
}

int main() {
  test<0>(998244353);
  test<1>(1000000007);
  rep(m, 1, 5) test<2>(m);
  {
    ll m = 998;
    rep(i, 0, 10) {
      test<3>(m);
      m = (m * 244 + 353) % 1000000007;
    }
  }

  int a, b;
  in(a, b);
  out(a + b);
}