#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"

#include "template/template.hpp"
#include "number-theory/prime-count.hpp"

int main() {
  ll n;
  cin >> n;
  cout << PrimeCount::count(n) << "\n";
}