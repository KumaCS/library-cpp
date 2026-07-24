#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "number-theory/mobius-function.hpp"
#include "util/xorshift.hpp"

int main() {
  assert(MobiusFunction::sum(-1) == 0);
  assert(MobiusFunction::sum(0) == 0);

  const int N = 1000000;
  auto mu = MobiusFunction::table(N);
  vector<long long> sum(N + 1);
  for (int i = 1; i <= N; i++) sum[i] = sum[i - 1] + mu[i];

  for (int n = 1; n <= 1000; n++) assert(MobiusFunction::sum(n) == sum[n]);
  rep(_, 0, 100) {
    int n = XORShift::xor32() % N + 1;
    assert(MobiusFunction::sum(n) == sum[n]);
  }
  assert(MobiusFunction::sum(N) == sum[N]);

  int A, B;
  in(A, B);
  out(A + B);
}
