#pragma once
#include "data-structure/sparse-table.hpp"

struct LowestCommonAncestor {
  using P = pair<int, int>;
  struct LcaMagma {
    using value_type = P;
    static P op(P x, P y) { return x.second <= y.second ? x : y; }
  };

 protected:
  int n, r;
  SparseTable<LcaMagma> st;
  vector<int> in_time, depth, parent, euler_tour;

 public:
  size_t size() const { return n; }
  int root() const { return r; }
  LowestCommonAncestor() : n(0), r(0) {}
  template <class G>
  LowestCommonAncestor(const G& g, int root = 0) {
    build(g, root);
  }
  template <class G>
  void build(const G& g, int root = 0) {
    n = g.size(), r = root;
    assert(n > 0);
    assert(0 <= r && r < n);
    parent.assign(n, -1);
    depth.assign(n, 0);
    in_time.assign(n, 0);
    euler_tour.clear();
    euler_tour.reserve(2 * n - 1);
    {
      stack<int> dfs;
      dfs.push(r);
      vector<int> idx(n);
      while (!dfs.empty()) {
        int x = dfs.top();
        dfs.pop();
        if (idx[x] == 0) in_time[x] = euler_tour.size();
        euler_tour.push_back(x);
        if (idx[x] < static_cast<int>(g[x].size())) {
          dfs.push(x);
          int y = g[x][idx[x]++].to;
          if (y != parent[x]) {
            parent[y] = x;
            depth[y] = depth[x] + 1;
            dfs.push(y);
          }
        }
      }
    }
    vector<P> data;
    data.reserve(euler_tour.size());
    for (auto v : euler_tour)
      data.push_back({v, depth[v]});
    st = SparseTable<LcaMagma>(data);
  }
  int lca(int u, int v) const {
    assert(0 <= u && u < n);
    assert(0 <= v && v < n);
    int x = in_time[u], y = in_time[v];
    if (x > y) swap(x, y);
    return st.prod(x, y + 1).first;
  }
};
/**
 * @brief Lowest Common Ancestor
 * @docs docs/tree/lowest-common-ancestor.md
 */
