#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix_mod_2"

#include "template/template.hpp"
#include "matrix/matrix-mod2.hpp"

int main() {
  int n;
  in(n);
  MatrixMod2 a(n);
  string s;
  rep(i, 0, n) {
    in(s);
    a.set_row(i, s);
  }
  auto inv = a.inv();
  if (!inv) {
    out(-1);
  } else {
    out(*inv);
  }
}
