#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"

#include "template/template.hpp"
#include "number-theory/miller-rabin.hpp"

int main() {
  int Q;
  in(Q);
  while (Q--) {
    long long n;
    in(n);
    out(MillerRabin::is_prime(n) ? "Yes" : "No");
  }
}
