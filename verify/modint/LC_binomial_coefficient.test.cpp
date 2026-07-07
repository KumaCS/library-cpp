#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient"

#include "template/template.hpp"
#include "modint/binomial-general-mod.hpp"

int main() {
  int t, m;
  in(t, m);
  BinomialGeneralMod binom(m);
  while (t--) {
    ll n, k;
    in(n, k);
    out(binom.binom(n, k));
  }
}