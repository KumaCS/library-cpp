#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "modint/modint.hpp"

template <unsigned int mod>
void test() {
  using mint = ModInt<mod>;
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
        if((x / y) * y != x)show(m,x,y,x/y,x/y*y);
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
  test<998244353>();
  test<1000000007>();
  test<1>();
  test<2>();
  test<3>();
  test<1000000000>();

  int a, b;
  in(a, b);
  out(a + b);
}