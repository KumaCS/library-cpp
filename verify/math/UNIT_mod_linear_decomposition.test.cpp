#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "math/mod-linear-decomposition.hpp"

void check(long long n, long long m, long long a, long long b) {
  auto res = ModLinearDecomposition(n, m, a, b);
  vector<int> seen(n);
  for (auto seq : res.sequences) {
    assert(seq.size > 0);
    for (long long j = 0; j < seq.size; j++) {
      long long x = seq.x0 + j * res.dx, y = seq.y0 + j * res.dy;
      assert(0 <= x && x < n && 0 <= y && y < m);
      assert(y == (a * x + b) % m);
      assert(++seen[x] == 1);
    }
  }
  for (int x : seen) assert(x == 1);
}

int main() {
  for (int n = 0; n <= 30; n++)
    for (int m = 1; m <= 15; m++)
      for (int a = 0; a < m; a++)
        for (int b = 0; b < m; b++) check(n, m, a, b);
  mt19937 rng(1234567);
  for (int tc = 0; tc < 1000; tc++) {
    long long m = rng() % 1000000000 + 1;
    check(rng() % 500, m, rng() % m, rng() % m);
  }
  for (long long m : {1LL, 7LL, 1000000007LL}) {
    auto res = ModLinearDecomposition(1000000000000LL, m, 0LL, m - 1);
    assert(res.dy == 0 && res.dx == 1);
    assert(res.sequences.size() == 1);
    auto seq = res.sequences[0];
    assert(seq.size == 1000000000000LL && seq.x0 == 0 && seq.y0 == m - 1);
  }
  auto res = ModLinearDecomposition<int>(10, 7, 3, 4);
  int size = 0;
  for (auto seq : res.sequences) size += seq.size;
  assert(size == 10);
  int a, b;
  in(a, b);
  out(a + b);
}
