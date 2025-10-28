#define PROBLEM "https://judge.yosupo.jp/problem/subset_convolution"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "set/subset-convolution.hpp"

int main() {
  int n;
  in(n);
  vector<mint> a(1 << n), b(1 << n);
  in(a, b);
  SubsetConvolution<mint, 20> sc;
  auto c = sc.multiply(a, b);
  out(c);
}