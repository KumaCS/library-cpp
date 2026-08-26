#pragma once

#include "graph/csr.hpp"

pair<int, vector<int>> CentroidDecomposition(const CSR<int>& g) {
  const int n = g.size();
  vector<int> parent(n, -1), bfs(n);
  int bfsi = 1;
  for (auto x : bfs)
    for (auto y : g[x])
      if (y != parent[x]) parent[y] = x, bfs[bfsi++] = y;
  vector<int> sz(n, 1);
  for (int i = n - 1; i > 0; i--) sz[parent[bfs[i]]] += sz[bfs[i]];
  bfsi = 1;
  for (auto x : bfs) {
    while (true) {
      int nx = -1;
      for (auto y : g[x])
        if (sz[y] * 2 > sz[x]) nx = y;
      if (nx == -1) break;
      parent[nx] = parent[x];
      parent[x] = nx;
      sz[x] -= sz[nx];
      sz[nx] += sz[x];
      x = nx;
    }
    sz[x] = 0;
    for (auto y : g[x])
      if (sz[y] != 0) bfs[bfsi++] = y;
  }
  int root = 0;
  while (parent[root] != -1) root++;
  return {root, parent};
}

template <class G>
pair<int, vector<int>> CentroidDecomposition(const G& g) {
  return CentroidDecomposition(CSR<int>(g));
}

/**
 * @brief 重心分解
 * @docs docs/tree/centroid-decomposition.md
 */