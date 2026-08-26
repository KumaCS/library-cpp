#define PROBLEM "https://judge.yosupo.jp/problem/range_reverse_range_sum"

#include "template/template.hpp"
#include "binary-search-tree/rbst-segment-tree.hpp"

int main() {
  int n, q;
  in(n, q);
  vector<long long> a(n);
  in(a);

  RBSTSegmentTree<AddMonoid<long long>> seg;
  auto t = n == 0 ? seg.make_tree() : seg.build(a);
  while (q--) {
    int type, l, r;
    in(type, l, r);
    if (type == 0)
      seg.reverse(t, l, r);
    else
      out(seg.prod(t, l, r));
  }
}
