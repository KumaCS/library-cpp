#define PROBLEM "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "fps/fps-ntt-friendly.hpp"
using fps = FormalPowerSeries<mint>;
#include "fps/linearly-recurrent-sequence.hpp"

int main() {
  int d;
  ll k;
  in(d, k);
  fps a(d), c(d);
  in(a, c);
  out(LinearyRecurrentSequence(a, c, k));
}