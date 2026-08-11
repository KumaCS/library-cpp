#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include "template/template.hpp"
#include "graph/graph.hpp"
#include "graph/shortest-path.hpp"

int main() {
  int n, m, s, t;
  in(n, m, s, t);
  GraphWeighted<ll> g(n);
  rep(i, 0, m) {
    int a, b;
    ll c;
    in(a, b, c);
    g.add_edge_directed(a, b, c);
  }
  auto dist_only = ShortestPath::Dijkstra(g, 0LL, s);
  auto [dist, prev] = ShortestPath::DijkstraWithPrev(g, 0LL, s);
  assert(dist_only == dist);
  if (!dist[t]) {
    out(-1);
    return 0;
  }
  auto path = ShortestPath::EnumeratePath(prev, t);
  out(*dist[t], path.size() - 1);
  rep(i, 0, (int)path.size() - 1) out(path[i], path[i + 1]);
}
