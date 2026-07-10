#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include "template/template.hpp"
#include "data-structure/dynamic-li-chao-tree.hpp"

int main() {
  constexpr ll C = 1000000000;
  int n, q;
  in(n, q);
  DynamicLiChaoTree<ll> cht(-C, C + 1);
  rep(i, 0, n) {
    ll a, b;
    in(a, b);
    cht.add_line(a, b);
  }
  while (q--) {
    int type;
    in(type);
    if (type == 0) {
      ll a, b;
      in(a, b);
      cht.add_line(a, b);
    } else {
      ll p;
      in(p);
      out(cht.get(p));
    }
  }
}
