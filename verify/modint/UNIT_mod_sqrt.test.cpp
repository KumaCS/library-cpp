#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "modint/mod-sqrt.hpp"

void test(int mod) {
  rep(i, 0, 10000) {
    ll sq = ModSqrt(i, mod);
    if (sq != -1) assert(sq * sq % mod == i % mod);
  }
  {
    ll a = 998;
    rep(i, 0, 10000) {
      a = (a * 244 + 353) % mod;
      {
        ll sq = ModSqrt(a, mod);
        if (sq != -1) assert(sq * sq % mod == a);
      }
      {
        ll sq = ModSqrt(a * a, mod);
        assert(sq == a || sq == mod - a);
      }
    }
  }
}

int main() {
  vector<int> psmall{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
  for (auto p : psmall) test(p);
  vector<int> plarge{998244353, 1000000007};
  for (auto p : plarge) test(p);

  int a, b;
  in(a, b);
  out(a + b);
}