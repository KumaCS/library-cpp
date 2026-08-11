#pragma once

#include "tree/lowest-common-ancestor.hpp"

template <class T>
struct TreeDistance {
 private:
  int n;
  LowestCommonAncestor lca;
  vector<T> d;

 public:
  size_t size() const { return n; }
  TreeDistance() : n(0) {}
  template <class G>
  TreeDistance(const G& g) : n(g.size()), lca(g, 0), d(n) {
    assert(n > 0);
    d[0] = T(0);
    vector<int> parent(n, -1);
    parent[0] = 0;
    queue<int> qu;
    qu.push(0);
    while (!qu.empty()) {
      int x = qu.front();
      qu.pop();
      for (const auto& e : g[x]) {
        int y = e.to;
        if (parent[y] == -1) {
          parent[y] = x;
          d[y] = d[x] + e.weight;
          qu.push(y);
        }
      }
    }
  }
  T dist(int u, int v) const {
    assert(0 <= u && u < n);
    assert(0 <= v && v < n);
    return d[u] + d[v] - 2 * d[lca.lca(u, v)];
  }
};
/**
 * @brief 木上の距離
 * @docs docs/tree/distance.md
 */
