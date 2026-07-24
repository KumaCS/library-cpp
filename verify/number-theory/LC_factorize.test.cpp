#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include "template/template.hpp"
#include "number-theory/pollard-rho.hpp"

int main() {
  int Q;
  in(Q);
  while (Q--) {
    long long n;
    in(n);
    vector<long long> factors;
    for (auto [p, e] : PollardRho::factorize(n))
      while (e--) factors.push_back(p);
    cout << factors.size();
    for (long long p : factors) cout << ' ' << p;
    cout << '\n';
  }
}
