#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

#include "template/template.hpp"
#include "number-theory/prime-sieve.hpp"

int main() {
  int N, A, B;
  in(N, A, B);
  auto ps = PrimeSieve(N);
  vector<int> xs;
  for (int k = B; k < ps.size(); k += A) xs.push_back(ps[k]);
  out(ps.size(), xs.size());
  out(xs);
}
