#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"

#include "template/template.hpp"
#include "modint/dynamic-modint.hpp"
using mint = DynamicModInt<0>;
#include "modint/factorial.hpp"
using fact = Factorial<mint>;

int main() {
  int t, m;
  in(t, m);
  mint::set_mod(m);
  while (t--) {
    int n, k;
    in(n, k);
    out(fact::binom(n, k));
  }
}