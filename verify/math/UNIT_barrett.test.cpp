#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "math/barrett.hpp"

void test_mod(unsigned int mod) {
  barrett bt(mod);
  assert(bt.umod() == mod);
  vector<unsigned int> xs{0, 1, 2, mod - 1, mod / 2, 123456789u, 4000000000u};
  for (unsigned int a : xs) {
    a %= mod;
    for (unsigned int b : xs) {
      b %= mod;
      assert(bt.mul(a, b) == (unsigned long long)a * b % mod);
    }
  }
}

int main() {
  for (unsigned int mod : {1u, 2u, 3u, 998244353u, 1000000007u, 2147483647u, 4000000007u}) {
    test_mod(mod);
  }

  int a, b;
  in(a, b);
  out(a + b);
}
