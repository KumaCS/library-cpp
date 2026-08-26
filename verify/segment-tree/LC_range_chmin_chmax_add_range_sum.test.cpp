#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include "template/template.hpp"
#include "segment-tree/range-chmin-chmax-add-range-sum.hpp"

int main() {
  int n, q;
  in(n, q);
  vector<ll> a(n);
  in(a);
  RangeChminChmaxAddRangeSum<ll> seg(a);
  while (q--) {
    int t, l, r;
    in(t, l, r);
    if (t == 0) {
      ll b;
      in(b);
      seg.chmin(l, r, b);
    } else if (t == 1) {
      ll b;
      in(b);
      seg.chmax(l, r, b);
    } else if (t == 2) {
      ll b;
      in(b);
      seg.add(l, r, b);
    } else {
      out(seg.sum(l, r));
    }
  }
}
