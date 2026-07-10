#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

#include "template/template.hpp"
#include "data-structure/li-chao-tree.hpp"

int main() {
  const ll INF = 1LL << 62;
  int n, q;
  in(n, q);
  vector<tuple<ll, ll, ll, ll>> init(n);
  rep(i, 0, n) {
    ll l, r, a, b;
    in(l, r, a, b);
    init[i] = {l, r, a, b};
  }
  vector<tuple<int, ll, ll, ll, ll>> query;
  vector<ll> xs;
  rep(i, 0, q) {
    int type;
    in(type);
    if (type == 0) {
      ll l, r, a, b;
      in(l, r, a, b);
      query.emplace_back(type, l, r, a, b);
    } else {
      ll p;
      in(p);
      query.emplace_back(type, p, 0, 0, 0);
      xs.push_back(p);
    }
  }
  LiChaoTree<ll> cht(xs, INF);
  for (auto [l, r, a, b] : init) cht.add_segment(l, r, a, b);
  for (auto [type, l, r, a, b] : query) {
    if (type == 0) {
      cht.add_segment(l, r, a, b);
    } else {
      ll ans = cht.get(l);
      if (ans == INF)
        out("INFINITY");
      else
        out(ans);
    }
  }
}
