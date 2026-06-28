#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "template/template.hpp"
#include "data-structure/binary-indexed-tree.hpp"

int main() {
  int n, q;
  in(n, q);
  BinaryIndexedTree<ll> bit(n);
  rep(i, 0, n) {
    ll a;
    in(a);
    bit.add(i, a);
  }
  while (q--) {
    int l, r;
    in(l, r);
    out(bit.sum(l, r));
  }
}
