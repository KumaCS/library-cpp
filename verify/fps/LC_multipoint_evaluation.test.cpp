#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "fps/fps-ntt-friendly.hpp"
using fps = FormalPowerSeries<mint>;
#include "fps/multipoint-evaluation.hpp"

int main() {
  int n, m;
  in(n, m);
  fps a(n);
  vector<mint> c(m);
  in(a, c);
  out(MultipointEvaluation(a, c));
}