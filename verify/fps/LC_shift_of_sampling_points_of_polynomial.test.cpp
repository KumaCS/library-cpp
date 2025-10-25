#define PROBLEM "https://judge.yosupo.jp/problem/shift_of_sampling_points_of_polynomial"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "fps/fps-ntt-friendly.hpp"
using fps = FormalPowerSeries<mint>;
#include "fps/sampling-points-shift.hpp"

int main() {
  int n, m;
  mint c;
  in(n, m, c);
  vector<mint> f(n);
  in(f);
  auto g = SamplingPointsShift(f, c, m);
  out(g);
}