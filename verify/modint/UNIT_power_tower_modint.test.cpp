#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "modint/power-tower-modint.hpp"

uint64_t mod_pow(uint64_t a, uint64_t n, uint64_t mod) {
  uint64_t res = 1 % mod;
  while (n) {
    if (n & 1) res = __uint128_t(res) * a % mod;
    a = __uint128_t(a) * a % mod;
    n >>= 1;
  }
  return res;
}

uint64_t pow_u64(uint64_t a, uint64_t n) {
  uint64_t res = 1;
  while (n) {
    if (n & 1) res *= a;
    a *= a;
    n >>= 1;
  }
  return res;
}

template <uint32_t mod>
void test() {
  using mint = PowerTowerModInt<mod>;
  static_assert(mint::get_mod() == mod);
  const vector<uint64_t> values = {
      0, 1, mod - 1, mod, uint64_t(mod) + 1, uint64_t(mod) * 2,
      numeric_limits<uint32_t>::max(), numeric_limits<uint64_t>::max()};
  for (uint64_t a : values)
    for (uint64_t b : values) {
      mint x = a, y = b;
      assert(x.val() == a % mod);
      assert(x.large_val() == (a < mod ? a : mod + a % mod));
      assert((x + y).val() == uint64_t((__uint128_t(a) + b) % mod));
      assert((x * y).val() == uint64_t(__uint128_t(a) * b % mod));
      assert(x.pow(y).val() == mod_pow(a % mod, b, mod));
      if (__uint128_t(a) >= __uint128_t(b) + mod) {
        mint z = x;
        z.unsafe_subtract(y);
        assert(z.val() == (a - b) % mod);
        assert(mint(7).pow(z).val() == mod_pow(7, a - b, mod));
      }
      if (a >= mod) {
        mint z = x + y;
        z.unsafe_subtract(y);
        assert(z.val() == a % mod);
        assert(mint(7).pow(z).val() == mod_pow(7, a, mod));
      }
    }
  for (uint64_t a = 0; a <= 5; a++)
    for (uint64_t b = 0; b <= 5; b++)
      for (uint64_t c = 0; c <= 8; c++) {
        uint64_t exponent = pow_u64(b, c);
        assert(mint(a).pow(mint(b).pow(mint(c))).val() == mod_pow(a, exponent, mod));
      }
  for (uint64_t x = 0; x <= min<uint64_t>(mod - 1, 100); x++)
    for (uint64_t y = 0; y <= x; y++) {
      mint difference = x;
      difference.unsafe_subtract(int64_t(y));
      assert(difference.val() == x - y);
      assert(difference.large_val() == x - y);
      assert(mint(7).pow(difference).val() == mod_pow(7, x - y, mod));
      difference = mint(x);
      difference.unsafe_subtract(mint(y));
      assert(difference.val() == x - y);
      assert(difference.large_val() == x - y);
      assert(mint(7).pow(difference).val() == mod_pow(7, x - y, mod));
    }
  mint large_difference = mint(uint64_t(mod) + 123);
  large_difference.unsafe_subtract(int64_t(123));
  assert(large_difference.val() == 0);
  assert(large_difference.large_val() == mod);
  assert(mint(7).pow(large_difference).val() == mod_pow(7, mod, mod));
  assert(mint(0).pow(mint(0)).val() == 1 % mod);
  assert(mint(0).pow(mint(0).pow(mint(0))).val() == 0);
  assert(mint(0).pow(mint(0).pow(mint(1))).val() == 1 % mod);
  assert(mint(0) == mint(mod));
  mint huge = mint(2).pow(mint(100));
  mint difference = huge + mint(mod);
  difference.unsafe_subtract(huge);
  assert(difference.val() == 0);
  assert(difference.large_val() == mod);
  assert(mint(7).pow(difference).val() == mod_pow(7, mod, mod));
  stringstream ss;
  ss << mint(numeric_limits<uint64_t>::max());
  assert(ss.str() == to_string(numeric_limits<uint64_t>::max() % mod));
}

int main() {
  test<1>();
  test<2>();
  test<3>();
  test<4>();
  test<6>();
  test<10>();
  test<998244353>();
  test<2147483647>();

  using mint = PowerTowerModInt<10>;
  assert(mint(2).pow(mint(1)).val() == 2);
  assert(mint(2).pow(mint(4)).val() == 6);
  assert(mint(2).pow(mint(8)).val() == 6);

  int a, b;
  in(a, b);
  out(a + b);
}
