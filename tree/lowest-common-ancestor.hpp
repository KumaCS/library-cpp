#pragma once
#include "data-structure/sparse-table.hpp"

struct LowestCommonAncestor {
  using P = pair<int, int>;
  static P lca_st_op(P x, P y) { return x.second <= y.second ? x : y; }

 protected:
  int n, r;
  vector<vector<int>> g;
  SparseTable<P, lca_st_op> st;
  vector<int> in_time, depth, parent, euler_tour;

 public:
  const int size() { return n; }
  const int root() { return r; }
  LowestCommonAncestor() {}
  LowestCommonAncestor(int size, int root = 0) : n(size), r(root), g(n) {}
  LowestCommonAncestor(const vector<vector<int>>& graph, int root = 0) : n(graph.size()), r(root), g(graph) {
    build();
  }
  void add_edge(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
  }
  void build() {
    parent.resize(n, -1);
    depth.resize(n, 0);
    in_time.resize(n, 0);
    euler_tour.reserve(2 * n - 1);
    {
      stack<int> st;
      st.push(r);
      vector<int> idx(n);
      while (!st.empty()) {
        int x = st.top();
        st.pop();
        if (idx[x] == 0) in_time[x] = euler_tour.size();
        euler_tour.push_back(x);
        if (idx[x] < g[x].size()) {
          st.push(x);
          int y = g[x][idx[x]++];
          if (y != parent[x]) {
            parent[y] = x;
            depth[y] = depth[x] + 1;
            st.push(y);
          }
        }
      }
    }
    vector<P> data;
    data.reserve(euler_tour.size());
    for (auto v : euler_tour)
      data.push_back({v, depth[v]});
    st = SparseTable<P, lca_st_op>(data);
  }
  int lca(int u, int v) {
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