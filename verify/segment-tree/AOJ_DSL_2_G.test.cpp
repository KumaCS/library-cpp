#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include "template/template.hpp"
#include "segment-tree/lazy-segment-tree-util.hpp"

int main() {
  int n, q;
  in(n, q);
  LazySegmentTreeAddSum<ll> seg(n);
  while (q--) {
    int t, s, e;
    in(t, s, e);
    if (t == 0) {
      ll x;
      in(x);
      if (s == e) seg.apply(s - 1, x);
      else seg.apply(s - 1, e, x);
    } else {
      out(seg.prod(s - 1, e));
    }
  }
}
