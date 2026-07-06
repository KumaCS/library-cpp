#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "matrix/matrix.hpp"

int main() {
  int n, m, k;
  in(n, m, k);
  Matrix<mint> a(n, m), b(m, k);
  rep(i, 0, n) rep(j, 0, m) {
    mint x;
    in(x);
    a.set(i, j, x);
  }
  rep(i, 0, m) rep(j, 0, k) {
    mint x;
    in(x);
    b.set(i, j, x);
  }
  out(a * b);
}
