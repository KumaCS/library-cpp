#pragma once

#include "algebraic-structure/monoid.hpp"

template <class M, bool vertex, bool edge>
REQUIRES(Monoid<M>)
struct StaticTreePathProd {
  static_assert(vertex || edge);
  using T = M::value_type;

  StaticTreePathProd() {}
  template <class G>
  StaticTreePathProd(const G& g, const vector<T>& vertex_value, int root = 0)
      : n(g.size()), data(vertex_value) {
    static_assert(vertex);
    assert((int)data.size() == n);
    build(g, root);
  }
  template <class G>
  StaticTreePathProd(const G& g, int root = 0) : n(g.size()) {
    static_assert(edge && !vertex);
    build(g, root);
  }

  int lca(int x, int y) const {
    assert(0 <= x && x < n && 0 <= y && y < n);
    if (depth[x] < depth[y]) swap(x, y);
    x = climb(x, depth[x] - depth[y]);
    if (x == y) return x;
    for (int k = log - 1; k >= 0; k--) {
      if (parent[k][x] != parent[k][y]) x = parent[k][x], y = parent[k][y];
    }
    return parent[0][x];
  }
  T prod(int x, int y) const {
    assert(0 <= x && x < n && 0 <= y && y < n);
    int z = lca(x, y);
    T pl = M::e(), pr = M::e();
    for (int d = depth[x] - depth[z]; d > 0;) {
      int k = topbit(d);
      pl = M::op(pl, prod_up[k][x]);
      x = parent[k][x];
      d -= 1 << k;
    }
    for (int d = depth[y] - depth[z]; d > 0;) {
      int k = topbit(d);
      pr = M::op(prod_down[k][y], pr);
      y = parent[k][y];
      d -= 1 << k;
    }
    if constexpr (vertex) pl = M::op(pl, data[z]);
    return M::op(pl, pr);
  }

 private:
  int n = 0, log = 0;
  vector<T> data;
  vector<int> depth;
  vector<vector<int>> parent;
  vector<vector<T>> prod_up, prod_down;

  int climb(int x, int d) const {
    for (int k = 0; d > 0; k++, d >>= 1)
      if (d & 1) x = parent[k][x];
    return x;
  }
  template <class G>
  void build(const G& g, int root) {
    assert(n > 0);
    assert(0 <= root && root < n);
    log = 1;
    while ((1 << log) <= n) log++;
    depth.assign(n, 0);
    parent.assign(log, vector<int>(n, root));
    prod_up.assign(log, vector<T>(n, M::e()));
    prod_down.assign(log, vector<T>(n, M::e()));
    vector<int> order = {root};
    for (int i = 0; i < (int)order.size(); i++) {
      int x = order[i];
      for (const auto& e : g[x]) {
        int y = e.to;
        if (y == parent[0][x]) continue;
        parent[0][y] = x;
        depth[y] = depth[x] + 1;
        if constexpr (edge) {
          prod_up[0][y] = vertex ? M::op(data[y], e.weight) : e.weight;
          prod_down[0][y] = vertex ? M::op(e.weight, data[y]) : e.weight;
        } else {
          prod_up[0][y] = prod_down[0][y] = data[y];
        }
        order.push_back(y);
      }
    }
    assert((int)order.size() == n);
    for (int k = 0; k + 1 < log; k++) {
      for (int x = 0; x < n; x++) {
        int p = parent[k][x];
        parent[k + 1][x] = parent[k][p];
        prod_up[k + 1][x] = M::op(prod_up[k][x], prod_up[k][p]);
        prod_down[k + 1][x] = M::op(prod_down[k][p], prod_down[k][x]);
      }
    }
  }
};

template <class M, bool vertex, bool edge>
REQUIRES(Monoid<M>)
struct StaticTreePathProdCommutative {
  static_assert(vertex || edge);
  using T = M::value_type;

  StaticTreePathProdCommutative() {}
  template <class G>
  StaticTreePathProdCommutative(const G& g, const vector<T>& vertex_value, int root = 0)
      : n(g.size()), data(vertex_value) {
    static_assert(vertex);
    assert((int)data.size() == n);
    build(g, root);
  }
  template <class G>
  StaticTreePathProdCommutative(const G& g, int root = 0) : n(g.size()) {
    static_assert(edge && !vertex);
    build(g, root);
  }

  int lca(int x, int y) const {
    assert(0 <= x && x < n && 0 <= y && y < n);
    if (depth[x] < depth[y]) swap(x, y);
    x = climb(x, depth[x] - depth[y]);
    if (x == y) return x;
    for (int k = log - 1; k >= 0; k--) {
      if (parent[k][x] != parent[k][y]) x = parent[k][x], y = parent[k][y];
    }
    return parent[0][x];
  }
  T prod(int x, int y) const {
    assert(0 <= x && x < n && 0 <= y && y < n);
    int z = lca(x, y);
    T p = M::e();
    for (int d = depth[x] - depth[z]; d > 0;) {
      int k = topbit(d);
      p = M::op(p, prod_db[k][x]);
      x = parent[k][x];
      d -= 1 << k;
    }
    for (int d = depth[y] - depth[z]; d > 0;) {
      int k = topbit(d);
      p = M::op(p, prod_db[k][y]);
      y = parent[k][y];
      d -= 1 << k;
    }
    if constexpr (vertex) p = M::op(p, data[z]);
    return p;
  }

 private:
  int n = 0, log = 0;
  vector<T> data;
  vector<int> depth;
  vector<vector<int>> parent;
  vector<vector<T>> prod_db;

  int climb(int x, int d) const {
    for (int k = 0; d > 0; k++, d >>= 1)
      if (d & 1) x = parent[k][x];
    return x;
  }
  template <class G>
  void build(const G& g, int root) {
    assert(n > 0);
    assert(0 <= root && root < n);
    log = 1;
    while ((1 << log) <= n) log++;
    depth.assign(n, 0);
    parent.assign(log, vector<int>(n, root));
    prod_db.assign(log, vector<T>(n, M::e()));
    vector<int> order = {root};
    for (int i = 0; i < (int)order.size(); i++) {
      int x = order[i];
      for (const auto& e : g[x]) {
        int y = e.to;
        if (y == parent[0][x]) continue;
        parent[0][y] = x;
        depth[y] = depth[x] + 1;
        if constexpr (edge)
          prod_db[0][y] = vertex ? M::op(data[y], e.weight) : e.weight;
        else
          prod_db[0][y] = data[y];
        order.push_back(y);
      }
    }
    assert((int)order.size() == n);
    for (int k = 0; k + 1 < log; k++) {
      for (int x = 0; x < n; x++) {
        int p = parent[k][x];
        parent[k + 1][x] = parent[k][p];
        prod_db[k + 1][x] = M::op(prod_db[k][x], prod_db[k][p]);
      }
    }
  }
};

/**
 * @brief Static Tree Path Product
 * @docs docs/tree/static-tree-path-prod.md
 */
