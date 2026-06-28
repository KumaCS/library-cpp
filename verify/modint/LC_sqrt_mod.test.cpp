#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"

#include "template/template.hpp"
#include "modint/mod-sqrt.hpp"

int main() {
  int t;
  in(t);
  while (t--) {
    ll y, p;
    in(y, p);
    ll x = ModSqrt(y, p);
    if (x != -1) x = min(x, p - x);
    out(x);
  }
}
