#define PROBLEM "https://judge.yosupo.jp/problem/range_add_range_min"

#include "template/template.hpp"
#include "data-structure/range-add-range-min.hpp"

int main() {
  int n, q;
  in(n, q);
  vector<long long> a(n);
  in(a);

  RangeAddRangeMin<long long> seg(a);
  rep(_, 0, q) {
    int t, l, r;
    in(t, l, r);
    if (t == 0) {
      long long x;
      in(x);
      seg.add(l, r, x);
    } else {
      out(seg.min(l, r));
    }
  }
}
