#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include "template/template.hpp"
#include "data-structure/li-chao-tree.hpp"

int main() {
  int n, q;
  in(n, q);
  vector<pair<ll, ll>> init(n);
  in(init);
  vector<tuple<int, ll, ll>> query;
  vector<ll> xs;
  rep(i, 0, q) {
    int type;
    in(type);
    if (type == 0) {
      ll a, b;
      in(a, b);
      query.emplace_back(type, a, b);
    } else {
      ll p;
      in(p);
      query.emplace_back(type, p, 0);
      xs.push_back(p);
    }
  }
  LiChaoTree<ll> cht(xs);
  for (auto [a, b] : init) cht.add_line(a, b);
  for (auto [type, a, b] : query) {
    if (type == 0)
      cht.add_line(a, b);
    else
      out(cht.get(a));
  }
}
