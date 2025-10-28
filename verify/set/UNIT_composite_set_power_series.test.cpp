#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "set/subset-convolution.hpp"
#include "set/exp-of-set-power-series.hpp"
#include "set/composite-set-power-series.hpp"

SubsetConvolution<mint, 21> sc;

void test_log(vector<mint> a) {
  a[0] = 0;
  {
    auto b = SetPowerSeries::exp(a);
    b = SetPowerSeries::log(b);
    assert(a == b);
  }
  a[0] = 1;
  {
    auto b = SetPowerSeries::log(a);
    b = SetPowerSeries::exp(b);
    assert(a == b);
  }
  {
    auto b = SetPowerSeries::log(a);
    auto c = SetPowerSeries::log_arbitrary(a);
    assert(b == c);
  }
}

void test_pow(vector<mint> a) {
  a[0] = 1;
  {
    // sqrt
    auto b = SetPowerSeries::pow(a, mint(2).inv());
    b = sc.multiply(b, b);
    assert(a == b);
  }
  {
    mint m = 12345;
    auto b = SetPowerSeries::pow(a, m);
    auto c = SetPowerSeries::pow_arbitrary(a, m);
    assert(b == c);

    auto d = SetPowerSeries::log(a);
    for (auto& v : d) v *= m;
    d = SetPowerSeries::exp(d);
    assert(b == d);
  }
}

int main() {
  rep(k, 0, 10) {
    vector<mint> a(1 << k);
    iota(ALL(a), 0);
    test_log(a);
  }
  rep(k, 0, 10) {
    vector<mint> a(1 << k);
    iota(ALL(a), 0);
    test_pow(a);
  }

  int a, b;
  in(a, b);
  out(a + b);
}