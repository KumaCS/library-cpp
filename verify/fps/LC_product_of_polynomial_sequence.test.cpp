#define PROBLEM "https://judge.yosupo.jp/problem/product_of_polynomial_sequence"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "fps/fps-ntt-friendly.hpp"
using fps = FormalPowerSeries<mint>;
#include "fps/product-of-polynomials.hpp"

int main() {
  int n;
  in(n);
  vector<fps> fs;
  rep(i, 0, n) {
    int d;
    in(d);
    fps f(d + 1);
    in(f);
    fs.push_back(f);
  }
  out(ProductOfPolynomials(fs));
}