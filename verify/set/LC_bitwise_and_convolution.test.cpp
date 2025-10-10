#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "set/and-convolution.hpp"

int main() {
  int n;
  cin >> n;
  vector<mint> a(1 << n), b(1 << n);
  cin >> a >> b;
  auto c = AndConvolution(a, b);
  cout << c << "\n";
}