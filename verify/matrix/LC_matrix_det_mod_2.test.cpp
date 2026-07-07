#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det_mod_2"

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
  out(a.det());
}
