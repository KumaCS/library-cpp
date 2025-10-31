#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "modint/multi-inverse.hpp"

void test(vector<mint> a) {
  vector<mint> b = MultiInverse(a);
  rep(i, 0, a.size()) assert(a[i] * b[i] == 1);
}

int main() {
  {
    vector<mint> a(1000000);
    iota(ALL(a), 1);
    test(a);
  }
  {
    vector<mint> a(1000000);
    a[0] = 998;
    rep(i, 1, a.size()) a[i] = a[i - 1] * 244 + 353;
    test(a);
  }

  int a, b;
  in(a, b);
  out(a + b);
}