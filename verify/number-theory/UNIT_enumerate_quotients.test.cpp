#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "number-theory/enumerate-quotients.hpp"

using i64 = int64_t;

void check(i64 N) {
  vector<tuple<i64, i64, i64>> expected;
  for (i64 r = N; r > 0;) {
    i64 q = N / r;
    i64 l = N / (q + 1);
    expected.emplace_back(q, l, r);
    r = l;
  }

  vector<tuple<i64, i64, i64>> actual;
  EnumerateQuotients::iterate(N, [&](i64 q, i64 l, i64 r) { actual.emplace_back(q, l, r); });
  assert(actual == expected);

  for (auto [q, l, r] : expected) {
    assert((EnumerateQuotients::get_range(N, q) == pair<i64, i64>(l, r)));
  }
}

void check(i64 N, int k) {
  vector<tuple<i64, i64, i64>> expected;
  i64 r = Math::floor_root(N, k);
  while (r > 0) {
    i64 p = 1;
    rep(_, 0, k) p *= r;
    i64 q = N / p;
    i64 l = r - 1;
    while (l > 0) {
      p = 1;
      rep(_, 0, k) p *= l;
      if (N / p != q) break;
      l--;
    }
    expected.emplace_back(q, l, r);
    r = l;
  }

  vector<tuple<i64, i64, i64>> actual;
  EnumerateQuotients::iterate(N, k, [&](i64 q, i64 l, i64 r) { actual.emplace_back(q, l, r); });
  assert(actual == expected);

  vector<i64> qs;
  for (auto [q, l, r] : expected) {
    qs.push_back(q);
    assert((EnumerateQuotients::get_range(N, q, k) == pair<i64, i64>(l, r)));
  }
  assert(EnumerateQuotients::table(N, k) == qs);
}

int main() {
  rep(N, 1, 10001) check(N);
  check(1000000000000LL);
  check(1000000000001LL);
  assert((EnumerateQuotients::get_range(numeric_limits<i64>::max(), numeric_limits<i64>::max()) ==
          pair<i64, i64>(0, 1)));

  check(100, 1);
  rep(N, 1, 10001) rep(k, 2, 9) check(N, k);
  check(1000000000001LL, 2);
  check(numeric_limits<i64>::max(), 63);
  assert(EnumerateQuotients::table(42, numeric_limits<int>::max()) == vector<i64>({42}));
  assert((EnumerateQuotients::get_range(42, 42, numeric_limits<int>::max()) == pair<i64, i64>(0, 1)));

  int a, b;
  in(a, b);
  out(a + b);
}
