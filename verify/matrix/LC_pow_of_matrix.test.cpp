#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_matrix"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "matrix/matrix.hpp"

int main() {
  int n;
  long long k;
  in(n, k);
  Matrix<mint> a(n);
  rep(i, 0, n) rep(j, 0, n) {
    mint x;
    in(x);
    a.set(i, j, x);
  }
  out(a.pow(k));
}
