#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "fft/ntt.hpp"
NTT<mint> ntt;

int main() {
  int n, m;
  cin >> n >> m;
  vector<mint> a(n), b(m);
  cin >> a >> b;
  auto c = ntt.multiply(a, b);
  cout << c << "\n";
}