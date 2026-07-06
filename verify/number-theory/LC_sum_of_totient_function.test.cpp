#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_totient_function"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "number-theory/totient-function.hpp"

int main() {
  ll n;
  in(n);
  out(TotientFunction::sum<mint>(n));
}
