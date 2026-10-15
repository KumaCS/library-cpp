#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "template/template.hpp"
#include "data-structure/range-min-query.hpp"

int main() {
  int n, q;
  in(n, q);
  vector<int> a(n);
  in(a);
  RangeMinQuery<int> rmq(a);
  while (q--) {
    int l, r;
    in(l, r);
    out(rmq.query(l, r));
  }
}
