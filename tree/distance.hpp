#pragma once
#include "tree/lowest-common-ancestor.hpp"

template <class T>
struct TreeDistance {
 private:
  int n;
  vector<vector<pair<int, T>>> g;
  LowestCommonAncestor lca;
  vector<T> d;
  void dfs(int x, int p) {
    for (auto [y, w] : g[x]) {
      if (y == p) continue;
      d[y] = d[x] + w;
      dfs(y, x);
    }
  }

 public:
  const int size() { return n; }
  TreeDistance() {}
  TreeDistance(int size) : n(size), g(n) {}
  TreeDistance(const vector<vector<int>>& graph) : n(graph.size()), g(n) {
    for (int x = 0; x < n; x++)
      for (auto y : graph[x])
        g[x].push_back({y, (T)1});
    build();
  }
  TreeDistance(const vector<vector<pair<int, T>>>& graph) : n(graph.size()), g(graph) {
    build();
  }
  void add_edge(int u, int v, T w) {
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  void build() {
    lca = LowestCommonAncestor(n, 0);
    for (int u = 0; u < n; u++)
      for (auto [v, _] : g[u])
        if (u < v) lca.add_edge(u, v);
    lca.build();
    d = vector<T>(n);
    dfs(0, -1);
  }
  int dist(int u, int v) {
    assert(0 <= u && u < n);
    assert(0 <= v && v < n);
    return d[u] + d[v] - 2 * d[lca.lca(u, v)];
  }
};
/**
 * @brief 木上の距離
 * @docs docs/tree/distance.md
 */