#define PROBLEM "https://judge.yosupo.jp/problem/sharp_p_subset_sum"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "fps/fps-ntt-friendly.hpp"
using fps = FormalPowerSeries<mint>;
#include "fps/count-subset-sum.hpp"

int main() {
  int n, t;
  in(n, t);
  vector<int> a(n);
  in(a);
  auto b = CountSubsetSum<mint>(a, t);
  b.erase(b.begin());
  out(b);
}