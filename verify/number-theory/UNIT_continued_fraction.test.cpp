#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "number-theory/continued-fraction.hpp"

int main() {
  using namespace ContinuedFraction;
  assert((calc(vector<long long>{}) == pair<long long, long long>{1, 0}));
  assert((calc(vector<long long>{3, 7, 16}) == pair<long long, long long>{355, 113}));
  assert((calc(vector<long long>{1, 2}, 3LL, 2LL) == pair<long long, long long>{11, 8}));
  assert((calc(vector<long long>{1, 2}, pair<long long, long long>{3, 2}) == pair<long long, long long>{11, 8}));
  mt19937 rng(1234567);
  for (int tc = 0; tc < 1000; tc++) {
    vector<long long> terms(rng() % 10 + 1);
    long long p0 = 0, p1 = 1, q0 = 1, q1 = 0;
    for (auto& a : terms) {
      a = rng() % 5 + 1;
      long long p = a * p1 + p0, q = a * q1 + q0;
      p0 = p1, p1 = p, q0 = q1, q1 = q;
    }
    assert((calc(terms) == pair<long long, long long>{p1, q1}));
  }
  for (long long n = 2; n <= 200; n++) {
    long long a0 = Math::isqrt(n);
    if (a0 * a0 == n) continue;
    auto cf = ContinuedFraction::sqrt(n);
    vector<long long> cycle;
    long long m = 0, d = 1, a = a0;
    do {
      m = d * a - m;
      d = (n - m * m) / d;
      a = (a0 + m) / d;
      cycle.push_back(a);
    } while (a != 2 * a0);
    assert(cf.prefix == vector<long long>{a0});
    assert(cf.cycle == cycle);
  }
  int a, b;
  in(a, b);
  out(a + b);
}
