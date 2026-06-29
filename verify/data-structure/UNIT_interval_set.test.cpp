#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "data-structure/interval-set.hpp"
#include "util/xorshift.hpp"

constexpr int L = -20;
constexpr int R = 80;

vector<pair<int, int>> enumerate_naive(const vector<bool>& a, int l, int r) {
  vector<pair<int, int>> ret;
  l = max(l, L);
  r = min(r, R);
  for (int x = l; x < r;) {
    if (!a[x - L]) {
      x++;
      continue;
    }
    int y = x;
    while (y < r && a[y - L]) y++;
    ret.push_back({x, y});
    x = y;
  }
  return ret;
}

void check_points(const IntervalSet<int>& s, const vector<bool>& a) {
  rep(x, L, R) assert(s.contains(x) == a[x - L]);
  vector<pair<int, int>> intervals(s.begin(), s.end());
  assert(intervals == enumerate_naive(a, L, R));
  assert(s.empty() == intervals.empty());
}

void check_query(const IntervalSet<int>& s, const vector<bool>& a, int l, int r) {
  bool ok = true;
  rep(x, l, r) ok &= a[x - L];
  assert(s.contains(l, r) == ok);
  assert(s.enumerate(l, r) == enumerate_naive(a, l, r));
}

void check_full(const IntervalSet<int>& s, const vector<bool>& a) {
  check_points(s, a);
  rep(l, L, R + 1) rep(r, l, R + 1) {
    check_query(s, a, l, r);
  }

  rep(x, L, R) {
    auto itv = s.get(x);
    if (!a[x - L]) {
      assert(!itv);
    } else {
      int l = x, r = x + 1;
      while (L < l && a[l - 1 - L]) l--;
      while (r < R && a[r - L]) r++;
      assert(itv);
      assert(*itv == make_pair(l, r));
    }
  }

  rep(x, L, R + 1) {
    int expected = x;
    while (expected < R && a[expected - L]) expected++;
    assert(s.mex(x) == expected);
  }
}

void check_random_queries(const IntervalSet<int>& s, const vector<bool>& a) {
  check_points(s, a);
  rep(_, 0, 20) {
    int l = L + (int)(XORShift::xor32() % (R - L + 1));
    int r = L + (int)(XORShift::xor32() % (R - L + 1));
    if (l > r) swap(l, r);
    check_query(s, a, l, r);
  }
  rep(_, 0, 20) {
    int x = L + (int)(XORShift::xor32() % (R - L));
    auto itv = s.get(x);
    if (!a[x - L]) {
      assert(!itv);
    } else {
      int l = x, r = x + 1;
      while (L < l && a[l - 1 - L]) l--;
      while (r < R && a[r - L]) r++;
      assert(itv);
      assert(*itv == make_pair(l, r));
    }
  }
  rep(_, 0, 20) {
    int x = L + (int)(XORShift::xor32() % (R - L + 1));
    int expected = x;
    while (expected < R && a[expected - L]) expected++;
    assert(s.mex(x) == expected);
  }
}

void test_fixed() {
  IntervalSet<int> s;
  vector<bool> a(R - L, false);
  check_full(s, a);

  s.add(1, 3);
  s.add(3, 5);
  rep(x, 1, 5) a[x - L] = true;
  check_full(s, a);

  s.remove(2, 4);
  rep(x, 2, 4) a[x - L] = false;
  check_full(s, a);

  s.add(10);
  a[10 - L] = true;
  check_full(s, a);

  s.remove(10);
  a[10 - L] = false;
  check_full(s, a);

  s.clear();
  fill(a.begin(), a.end(), false);
  check_full(s, a);
}

void test_random() {
  IntervalSet<int> s;
  vector<bool> a(R - L, false);
  rep(_, 0, 20000) {
    int op = XORShift::xor32() % 6;
    int l = L + (int)(XORShift::xor32() % (R - L + 1));
    int r = L + (int)(XORShift::xor32() % (R - L + 1));
    if (l > r) swap(l, r);
    if (op == 0) {
      s.add(l, r);
      rep(x, l, r) a[x - L] = true;
    } else if (op == 1) {
      s.remove(l, r);
      rep(x, l, r) a[x - L] = false;
    } else if (op == 2) {
      int x = L + (int)(XORShift::xor32() % (R - L));
      s.add(x);
      a[x - L] = true;
    } else if (op == 3) {
      int x = L + (int)(XORShift::xor32() % (R - L));
      s.remove(x);
      a[x - L] = false;
    }
    check_random_queries(s, a);
  }
}

int main() {
  test_fixed();
  test_random();

  int a, b;
  in(a, b);
  out(a + b);
}
