#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "number-theory/pell-equation.hpp"

int main() {
  for (long long n = 2; n <= 50; n++) {
    long long r = Math::isqrt(n);
    if (r * r == n) continue;
    auto [x, y] = PellEquation::minimum_solution(n);
    assert(x > 0 && y > 0);
    assert((__int128)x * x - (__int128)n * y * y == 1);
    long long expected_y = 1;
    for (;; expected_y++) {
      long long z = 1 + n * expected_y * expected_y;
      long long expected_x = Math::isqrt(z);
      if (expected_x * expected_x == z) {
        assert(x == expected_x && y == expected_y);
        break;
      }
    }
  }
  assert((PellEquation::minimum_solution(61LL) == pair<long long, long long>{1766319049, 226153980}));
  assert((PellEquation::minimum_solution<int>(2) == pair<int, int>{3, 2}));
  int a, b;
  in(a, b);
  out(a + b);
}
