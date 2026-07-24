#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "data-structure/dynamic-bitset.hpp"
#include "util/xorshift.hpp"

string to_string_naive(const vector<bool>& a) {
  string s(a.size(), '0');
  rep(i, 0, a.size())
    if (a[i]) s[a.size() - 1 - i] = '1';
  return s;
}

void check(const DynamicBitset& b, const vector<bool>& a) {
  assert(b.size() == (int)a.size());
  int cnt = 0;
  bool any = false, all = true;
  rep(i, 0, a.size()) {
    assert(b.test(i) == a[i]);
    assert(b[i] == a[i]);
    cnt += a[i];
    any |= a[i];
    all &= a[i];
  }
  assert(b.count() == cnt);
  assert(b.any() == any);
  assert(b.none() == !any);
  assert(b.all() == all);
  assert(b.to_string() == to_string_naive(a));

  int p = b.find_first();
  int expected = 0;
  while (expected < (int)a.size() && !a[expected]) expected++;
  assert(p == expected);
  for (int i = -1; i < (int)a.size(); i++) {
    int q = i + 1;
    while (q < (int)a.size() && !a[q]) q++;
    assert(b.find_next(i) == q);
  }
}

vector<bool> shifted_left(vector<bool> a, int k) {
  vector<bool> ret(a.size(), false);
  rep(i, 0, a.size())
    if (a[i] && i + k < (int)a.size()) ret[i + k] = true;
  return ret;
}

vector<bool> shifted_right(vector<bool> a, int k) {
  vector<bool> ret(a.size(), false);
  rep(i, 0, a.size())
    if (a[i] && i - k >= 0) ret[i - k] = true;
  return ret;
}

void test_size(int n) {
  DynamicBitset b(n);
  vector<bool> a(n, false);
  check(b, a);

  rep(t, 0, 5000) {
    int op = XORShift::xor32() % 12;
    int i = n == 0 ? 0 : XORShift::xor32() % n;
    if (op == 0 && n > 0) {
      b.set(i);
      a[i] = true;
    } else if (op == 1 && n > 0) {
      b.reset(i);
      a[i] = false;
    } else if (op == 2 && n > 0) {
      b.flip(i);
      a[i] = !a[i];
    } else if (op == 3) {
      b.set();
      fill(a.begin(), a.end(), true);
    } else if (op == 4) {
      b.reset();
      fill(a.begin(), a.end(), false);
    } else if (op == 5) {
      b.flip();
      for (auto&& x : a) x = !x;
    } else if (op == 6 && n > 0) {
      bool v = XORShift::xor32() & 1;
      b[i] = v;
      a[i] = v;
    } else if (op == 7) {
      int k = XORShift::xor32() % (n + 70);
      b <<= k;
      a = shifted_left(a, k);
    } else if (op == 8) {
      int k = XORShift::xor32() % (n + 70);
      b >>= k;
      a = shifted_right(a, k);
    } else {
      DynamicBitset c(n);
      vector<bool> d(n, false);
      rep(j, 0, n) {
        d[j] = XORShift::xor32() & 1;
        c.set(j, d[j]);
      }
      if (op == 9) {
        b &= c;
        rep(j, 0, n) a[j] = a[j] & d[j];
      } else if (op == 10) {
        b |= c;
        rep(j, 0, n) a[j] = a[j] | d[j];
      } else {
        b ^= c;
        rep(j, 0, n) a[j] = a[j] != d[j];
      }
    }
    check(b, a);

    DynamicBitset c(n);
    vector<bool> d(n, false);
    rep(j, 0, n) {
      d[j] = XORShift::xor32() & 1;
      c.set(j, d[j]);
    }
    DynamicBitset e = b & c;
    DynamicBitset f = b | c;
    DynamicBitset g = b ^ c;
    DynamicBitset h = ~b;
    rep(j, 0, n) {
      assert(e[j] == (a[j] & d[j]));
      assert(f[j] == (a[j] | d[j]));
      assert(g[j] == (a[j] != d[j]));
      assert(h[j] == !a[j]);
    }
  }
}

void test() {
  for (int n : {0, 1, 2, 3, 63, 64, 65, 127, 128, 129, 200}) test_size(n);
  DynamicBitset b(10);
  assert(b.empty() == false);
  DynamicBitset c;
  assert(c.empty());
  assert((b << 100).none());
  assert((b >> 100).none());
}

int main() {
  test();

  int a, b;
  in(a, b);
  out(a + b);
}
