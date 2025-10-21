#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation_on_geometric_sequence"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "fps/fps-ntt-friendly.hpp"
using fps = FormalPowerSeries<mint>;
#include "fps/multipoint-evaluation.hpp"

int main() {
  int n, m;
  mint a, r;
  in(n, m, a, r);
  fps c(n);
  in(c);
  out(MultipointEvaluationGeometric(c, a, r, m));
}