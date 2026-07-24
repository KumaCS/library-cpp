#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "number-theory/prime-residue.hpp"

using i64 = int64_t;
using i128 = __int128_t;

void check(i64 n, int m) {
  auto [xs, count] = PrimeResidue::count(n, m);
  auto [ys, sum] = PrimeResidue::sum(n, m);
  assert(xs == ys);

  auto ps = PrimeSieve::table(n);
  vector<i64> expected_count(m);
  vector<i128> expected_sum(m);
  int j = 0;
  for (int i = 0; i < (int)xs.size(); i++) {
    while (j < (int)ps.size() && ps[j] <= xs[i]) {
      expected_count[ps[j] % m]++;
      expected_sum[ps[j] % m] += ps[j];
      j++;
    }
    assert(count[i] == expected_count);
    assert(sum[i] == expected_sum);
  }
}

int main() {
  {
    auto [xs, count] = PrimeResidue::count(10, 3);
    auto [ys, sum] = PrimeResidue::sum<i64>(10, 3);
    assert(xs == vector<i64>({1, 2, 3, 5, 10}));
    assert(xs == ys);
    assert(count.back() == vector<i64>({1, 1, 2}));
    assert(sum.back() == vector<i64>({3, 7, 7}));
  }
  rep(n, 0, 101) rep(m, 1, 13) check(n, m);
  check(1000, 137);
  check(10000, 7);
  check(100000, 20);
  check(1000000, 1);

  int A, B;
  in(A, B);
  out(A + B);
}
