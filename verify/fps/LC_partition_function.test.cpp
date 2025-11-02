#define PROBLEM "https://judge.yosupo.jp/problem/partition_function"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "fps/fps-ntt-friendly.hpp"
using fps = FormalPowerSeries<mint>;
#include "fps/famous-sequences.hpp"

int main() {
  int n;
  in(n);
  out(PartitionFunction<mint>(n));
}