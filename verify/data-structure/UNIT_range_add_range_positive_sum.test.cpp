#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "data-structure/range-add-range-positive-sum.hpp"
#include "util/xorshift.hpp"

long long naive_sum(const vector<long long>& a, int l, int r) {
  long long ret = 0;
  rep(i, l, r) ret += max(0LL, a[i]);
  return ret;
}

void check_all(const RangeAddRangePositiveSum<long long>& ds, const vector<long long>& a) {
  int n = a.size();
  rep(l, 0, n + 1) rep(r, l, n + 1) {
    assert(ds.sum(l, r) == naive_sum(a, l, r));
  }
}

void add_naive(vector<long long>& a, int l, int r, long long v) {
  rep(i, l, r) a[i] += v;
}

pair<int, int> random_interval(int n) {
  int l = n == 0 ? 0 : XORShift::xor32() % (n + 1);
  int r = n == 0 ? 0 : XORShift::xor32() % (n + 1);
  if (l > r) swap(l, r);
  return {l, r};
}

void test_fixed() {
  rep(n, 0, 80) {
    vector<long long> a(n);
    rep(i, 0, n) a[i] = i % 7 - 3;
    RangeAddRangePositiveSum<long long> ds(a);
    check_all(ds, a);

    vector<tuple<int, int, long long>> qs;
    qs.push_back({0, n, 5});
    qs.push_back({0, min(n, 1), -10});
    qs.push_back({n / 2, n, 4});
    qs.push_back({0, n / 2, -3});
    qs.push_back({n, n, 100});
    if (n >= 2) qs.push_back({1, n - 1, 2});

    for (auto [l, r, v] : qs) {
      ds.add(l, r, v);
      add_naive(a, l, r, v);
      check_all(ds, a);
    }
  }
}

void test_random() {
  rep(n, 0, 120) {
    vector<long long> a(n);
    rep(i, 0, n) a[i] = (long long)(XORShift::xor32() % 21) - 10;
    RangeAddRangePositiveSum<long long> ds(a);
    check_all(ds, a);

    rep(_, 0, 500) {
      auto [l, r] = random_interval(n);
      if (XORShift::xor32() % 2) {
        long long v = (long long)(XORShift::xor32() % 41) - 20;
        ds.add(l, r, v);
        add_naive(a, l, r, v);
      } else {
        assert(ds.sum(l, r) == naive_sum(a, l, r));
      }
    }
    check_all(ds, a);
  }
}

void test_random_large() {
  for (int n : {128, 257, 511, 1000, 2000}) {
    vector<long long> a(n);
    rep(i, 0, n) a[i] = (long long)(XORShift::xor32() % 2001) - 1000;
    RangeAddRangePositiveSum<long long> ds(a);

    rep(_, 0, 3000) {
      auto [l, r] = random_interval(n);
      if (XORShift::xor32() % 2) {
        long long v = (long long)(XORShift::xor32() % 2001) - 1000;
        ds.add(l, r, v);
        add_naive(a, l, r, v);
      } else {
        assert(ds.sum(l, r) == naive_sum(a, l, r));
      }
    }

    rep(_, 0, 200) {
      auto [l, r] = random_interval(n);
      assert(ds.sum(l, r) == naive_sum(a, l, r));
    }
  }
}

int main() {
  test_fixed();
  test_random();
  test_random_large();

  int a, b;
  in(a, b);
  out(a + b);
}
