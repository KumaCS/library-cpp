#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "binary-search-tree/rbst-segment-tree.hpp"
#include "util/xorshift.hpp"

struct StringMonoid {
  using value_type = string;
  static string op(const string& x, const string& y) { return x + y; }
  static string e() { return ""; }
};

void test() {
  vector<string> a = {"a", "bc", "d"};
  RBSTSegmentTree<StringMonoid> seg;
  auto t = seg.build(a);

  rep(loop, 0, 10000) {
    int type = XORShift::xor32() % 5;
    if (a.empty()) type = 0;
    if (type == 0) {
      int k = XORShift::xor32() % (a.size() + 1);
      string x = to_string(XORShift::xor32() % 10);
      a.insert(a.begin() + k, x);
      seg.insert(t, k, x);
    } else if (type == 1) {
      int k = XORShift::xor32() % a.size();
      a.erase(a.begin() + k);
      seg.erase(t, k);
    } else if (type == 2) {
      int k = XORShift::xor32() % a.size();
      string x = to_string(XORShift::xor32() % 10);
      a[k] = x;
      seg.set(t, k, x);
    } else if (type == 3) {
      int k = XORShift::xor32() % a.size();
      assert(seg.get(t, k) == a[k]);
    } else {
      int l = XORShift::xor32() % (a.size() + 1);
      int r = XORShift::xor32() % (a.size() + 1);
      if (l > r) swap(l, r);
      string expected;
      rep(i, l, r) expected += a[i];
      assert(seg.prod(t, l, r) == expected);
    }
    assert(seg.size(t) == (int)a.size());
    assert(seg.prod(t, 0, 0) == "");
    string expected;
    for (const string& x : a) expected += x;
    assert(seg.prod(t, 0, a.size()) == expected);
  }
}

int main() {
  test();

  int a, b;
  in(a, b);
  out(a + b);
}
