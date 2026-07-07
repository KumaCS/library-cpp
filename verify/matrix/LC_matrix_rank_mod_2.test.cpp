#define PROBLEM "https://judge.yosupo.jp/problem/matrix_rank_mod_2"

#include "template/template.hpp"
#include "matrix/matrix-mod2.hpp"

int main() {
  int n, m;
  in(n, m);
  MatrixMod2 a(n, m);
  string s;
  rep(i, 0, n) {
    if (m > 0) {
      in(s);
      a.set_row(i, s);
    }
  }
  out(a.rank());
}
