#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "modint/factorial.hpp"
#include "modint/power-table.hpp"
#include "fps/sum-of-exp-poly.hpp"

int main() {
  mint r;
  int d;
  in(r, d);
  auto f = PowerTable<mint>(d, d);
  out(SumOfExpPolyLimit(r, f));
}