#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind_fixed_k"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "fps/fps-ntt-friendly.hpp"
using fps = FormalPowerSeries<mint>;
#include "fps/famous-sequences.hpp"

int main() {
  int n, k;
  in(n, k);
  out(SecondKindStirlingNumbersFixedK<mint>(n, k));
}