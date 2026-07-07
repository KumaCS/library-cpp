#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product_mod_2"

#include "template/template.hpp"
#include "matrix/matrix-mod2.hpp"

int main() {
  int n, m, k;
  in(n, m, k);
  MatrixMod2 a(n, m), b(m, k);
  string s;
  rep(i, 0, n) {
    in(s);
    a.set_row(i, s);
  }
  rep(i, 0, m) {
    in(s);
    b.set_row(i, s);
  }
  out(a * b);
}
