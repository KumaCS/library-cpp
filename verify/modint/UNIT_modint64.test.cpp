#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "modint/modint64.hpp"

template <uint64_t mod>
void test() {
  using mint = ModInt64<mod>;

  assert(mint::get_mod() == mod);
  assert(mint(0).val() == 0);
  assert(mint(-1).val() == mod - 1);
  assert(mint(numeric_limits<long long>::min()).val() ==
         uint64_t((__uint128_t(mod) - (__uint128_t(1) << 63) % mod) % mod));
  assert(mint(numeric_limits<uint64_t>::max()).val() ==
         numeric_limits<uint64_t>::max() % mod);

  mint hi = mint::raw(mod - 1);
  assert((hi + hi).val() == uint64_t((__uint128_t(mod - 1) * 2) % mod));
  assert((mint(0) - hi).val() == uint64_t(1 % mod));
  assert((hi * hi).val() == uint64_t(__uint128_t(mod - 1) * (mod - 1) % mod));

  uint64_t a = 314 % mod, b = 271 % mod;
  rep(i, 0, 200) {
    mint x = mint::raw(a), y = mint::raw(b);
    assert((x + y).val() == uint64_t((__uint128_t(a) + b) % mod));
    assert((x - y).val() == uint64_t((__uint128_t(a) + mod - b) % mod));
    assert((x * y).val() == uint64_t(__uint128_t(a) * b % mod));
    if (gcd(b, mod) == 1) assert((x / y) * y == x);

    mint z = 1;
    rep(j, 0, 100) {
      assert(z == x.pow(j));
      z *= x;
    }
    a = (__uint128_t(a) * 159 + 265) % mod;
    b = (__uint128_t(b) * 828 + 182) % mod;
  }

  mint x = mint::raw(mod - 1);
  assert((++x).val() == 0);
  assert((--x).val() == mod - 1);
}

int main() {
  test<1>();
  test<2>();
  test<3>();
  test<1000000000000000000ULL>();
  test<18446744073709551557ULL>();
  test<18446744073709551615ULL>();

  using mint = ModInt64<1000000000000000003ULL>;
  stringstream ss("18446744073709551615 -18446744073709551615 +1000000000000000004");
  mint x, y, z;
  ss >> x >> y >> z;
  assert(x.val() == 446744073709551561ULL);
  assert(y.val() == 553255926290448442ULL);
  assert(z.val() == 1);
  stringstream os;
  os << x;
  assert(os.str() == "446744073709551561");

  int a, b;
  in(a, b);
  out(a + b);
}
