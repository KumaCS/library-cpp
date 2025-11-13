#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "binary-search-tree/rbst-array.hpp"
#include "util/xorshift.hpp"

void test() {
  vector<int> a;
  RBSTArray<int> ar;
  auto t = ar.make_tree();

  rep(loop, 0, 10000) {
    int type = XORShift::xor32() % 3;
    if (a.empty()) type = 0;
    if (type == 0) {
      int x = XORShift::xor32() % (a.size() + 1);
      int v = XORShift::xor32();
      a.insert(a.begin() + x, v);
      ar.insert(t, x, v);
    } else if (type == 1) {
      int x = XORShift::xor32() % a.size();
      int v = XORShift::xor32();
      a[x] = v;
      ar.set(t, x, v);
    } else {
      int x = XORShift::xor32() % a.size();
      a.erase(a.begin() + x);
      ar.erase(t, x);
    }
    assert(a.size() == ar.size(t));
    rep(i, 0, a.size()) assert(a[i] == ar.get(t, i));
  }
}

int main() {
  test();

  int a, b;
  in(a, b);
  out(a + b);
}