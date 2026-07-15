#define PROBLEM "https://judge.yosupo.jp/problem/tree_path_composite_sum"

#include "template/template.hpp"
#include "modint/modint.hpp"
#include "tree/rerooting-dp.hpp"

using mint = ModInt998244353;
using T = pair<mint, mint>;
using E = pair<mint, mint>;

T merge(T x, T y) { return {x.first + y.first, x.second + y.second}; }
T add_edge(T x, E e) { return {e.first * x.first + e.second * x.second, x.second}; }
T add_vertex(T x, mint v) { return {x.first + v, x.second + 1}; }

int main() {
  int n;
  in(n);
  vector<mint> a(n);
  in(a);

  ReRootingDP<T, mint, E, merge, add_edge, add_vertex> dp(n, {0, 0});
  rep(i, 0, n) dp.set_vertex(i, a[i]);
  vector<int> edge_ids;
  rep(i, 0, n - 1) {
    int u, v;
    mint b, c;
    in(u, v, b, c);
    edge_ids.push_back(dp.add_edge(u, v, {b, c}));
  }

  auto ans = dp.calc();
  rep(i, 0, n - 1) {
    assert(edge_ids[i] == i);
    assert(dp.edge_subtree(i, 0).second + dp.edge_subtree(i, 1).second == n);
  }
  vector<mint> res(n);
  rep(i, 0, n) res[i] = ans[i].first;
  out(res);
}
