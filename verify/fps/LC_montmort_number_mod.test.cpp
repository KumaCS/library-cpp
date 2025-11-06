#define PROBLEM "https://judge.yosupo.jp/problem/montmort_number_mod"

#include "template/template.hpp"
#include "modint/dynamic-modint.hpp"
using mint = DynamicModInt<0>;
#include "fps/famous-sequences.hpp"

int main() {
  int n, m;
  in(n, m);
  mint::set_mod(m);
  auto a = MontmortNumber<mint>(n);
  a.erase(a.begin());
  out(a);
}