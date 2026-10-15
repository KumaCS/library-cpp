#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "math/garner-online.hpp"
#include "modint/dynamic-modint.hpp"

using mint = DynamicModInt<0>;

template <class T>
void test() {
  vector<int> mods{2, 3, 5, 7, 11};
  for (int x = 0; x < 2310; x++) {
    GarnerOnline<T> g;
    assert(g.get() == 0 && g.get(1) == 0);
    T product = 1;
    for (int i = 0; i < (int)mods.size(); i++) {
      int m = mods[i];
      if (i & 1) {
        mint::set_mod(m);
        g.push(mint(x));
      } else {
        g.push(T(x % m), T(m));
      }
      product *= m;
      assert(g.get() == x % product);
      for (int mod : {1, 2, 4, 6, 1000}) assert(g.get(mod) == (x % product) % mod);
    }
    for (int i = mods.size() - 1; i >= 0; i--) {
      g.pop();
      product /= mods[i];
      assert(g.get() == x % product);
    }
    g.push(T(2), T(3));
    g.init();
    assert(g.get() == 0);
    g.push(T(4), T(5));
    assert(g.get() == 4);
  }
}

int main() {
  test<long long>();
  test<__int128_t>();
  GarnerOnline<> g;
  g.push((__int128_t)123456789, (__int128_t)1000000007);
  g.push((__int128_t)987654321, (__int128_t)1000000009);
  auto x = g.get();
  assert(x % 1000000007 == 123456789 && x % 1000000009 == 987654321);
  int a, b;
  in(a, b);
  out(a + b);
}
