#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "number-theory/range-sieve.hpp"

int main() {
  assert(RangeSieve::table(1, 30) == vector<long long>({2, 3, 5, 7, 11, 13, 17, 19, 23, 29}));
  assert(RangeSieve::internal::primes(9).back() == 13);
  auto small = RangeSieve::factorize(1, 30);
  assert(small[0].empty());
  assert((small[11] == vector<pair<long long, int>>({{2, 2}, {3, 1}})));
  assert((small[16] == vector<pair<long long, int>>({{17, 1}})));
  assert((small[29] == vector<pair<long long, int>>({{2, 1}, {3, 1}, {5, 1}})));

  const long long L = 1000000000000LL, R = L + 1000;
  auto ps = RangeSieve::table(L, R);
  auto lpf = RangeSieve::lpf(L, R);
  auto factors = RangeSieve::factorize(L, R);
  size_t k = 0;
  for (long long x = L; x <= R; x++) {
    if (lpf[x - L] == x) {
      assert(k < ps.size());
      assert(ps[k++] == x);
    }
    long long y = 1;
    long long prv = 1;
    for (auto [p, e] : factors[x - L]) {
      assert(prv < p);
      prv = p;
      while (e--) y *= p;
    }
    assert(y == x);
  }
  assert(k == ps.size());
  assert(RangeSieve::table(1, 30) == vector<long long>({2, 3, 5, 7, 11, 13, 17, 19, 23, 29}));

  int A, B;
  in(A, B);
  out(A + B);
}
