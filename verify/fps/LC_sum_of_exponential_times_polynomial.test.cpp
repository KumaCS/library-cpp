#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "modint/factorial.hpp"
#include "modint/power-table.hpp"
#include "fps/sum-of-exp-poly.hpp"

int main() {
  mint r;
  int d;
  ll n;
  in(r, d, n);
  auto f = PowerTable<mint>(d, d);
  out(SumOfExpPoly(n, r, f));
}