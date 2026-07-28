#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "number-theory/pollard-rho.hpp"

int main() {
  for (long long n = 1; n <= 1000; n++) {
    vector<long long> expected;
    for (long long d = 1; d <= n; d++)
      if (n % d == 0) expected.push_back(d);
    assert(PollardRho::divisors(n) == expected);
  }

  const long long n = 1000000000000000000LL;
  auto divisors = PollardRho::divisors(n);
  assert(divisors.size() == 361);
  assert(divisors.front() == 1 && divisors.back() == n);
  assert(is_sorted(divisors.begin(), divisors.end()));
  for (long long d : divisors) assert(n % d == 0);

  long long a, b;
  in(a, b);
  cout << a + b << '\n';
}
