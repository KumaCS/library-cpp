#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "matrix/matrix.hpp"

int main() {
  int n;
  in(n);
  Matrix<mint> a(n);
  rep(i, 0, n) rep(j, 0, n) {
    mint x;
    in(x);
    a.set(i, j, x);
  }
  if (a.det() == mint(0)) {
    out(-1);
  } else {
    out(a.inv());
  }
}
