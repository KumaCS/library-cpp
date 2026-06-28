#define PROBLEM "https://judge.yosupo.jp/problem/min_of_mod_of_linear"

#include "template/template.hpp"
#include "math/min-of-mod-of-linear.hpp"

int main() {
  int t;
  in(t);
  while (t--) {
    ll n, m, a, b;
    in(n, m, a, b);
    out(MinOfModOfLinear(n, m, a, b));
  }
}
