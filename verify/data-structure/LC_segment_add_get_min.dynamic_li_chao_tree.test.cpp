#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

#include "template/template.hpp"
#include "data-structure/dynamic-li-chao-tree.hpp"

int main() {
  constexpr ll C = 1000000000;
  const ll INF = 1LL << 62;
  int n, q;
  in(n, q);
  DynamicLiChaoTree<ll> cht(-C, C + 1, INF);
  rep(i, 0, n) {
    ll l, r, a, b;
    in(l, r, a, b);
    cht.add_segment(l, r, a, b);
  }
  while (q--) {
    int type;
    in(type);
    if (type == 0) {
      ll l, r, a, b;
      in(l, r, a, b);
      cht.add_segment(l, r, a, b);
    } else {
      ll p;
      in(p);
      ll ans = cht.get(p);
      if (ans == INF)
        out("INFINITY");
      else
        out(ans);
    }
  }
}
