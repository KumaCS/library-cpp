#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "template/template.hpp"
#include "data-structure/binary-indexed-tree.hpp"

int main() {
  int n, q;
  in(n, q);
  vector<ll> a(n);
  in(a);
  BinaryIndexedTree<ll> bit(n);
  rep(i, 0, n) bit.add(i, a[i]);
  while (q--) {
    int type, x, y;
    in(type, x, y);
    if (type == 0) {
      bit.add(x, y);
    } else {
      out(bit.sum(x, y));
    }
  }
}