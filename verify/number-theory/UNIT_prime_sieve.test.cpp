#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "number-theory/prime-sieve.hpp"

int main() {
  assert(PrimeSieve::table(0).empty());
  assert((PrimeSieve::factorize(0) == vector<vector<pair<long long, int>>>(1)));

  const int N = 1000;
  auto factors = PrimeSieve::factorize(N);
  auto ps = PrimeSieve::table(N);
  vector<bool> is_prime(N + 1);
  for (int p : ps) is_prime[p] = true;
  for (int x = 1; x <= N; x++) {
    long long y = 1;
    long long prv = 1;
    for (auto [p, e] : factors[x]) {
      assert(is_prime[p]);
      assert(prv < p);
      prv = p;
      while (e--) y *= p;
    }
    assert(y == x);
  }

  int A, B;
  in(A, B);
  out(A + B);
}
