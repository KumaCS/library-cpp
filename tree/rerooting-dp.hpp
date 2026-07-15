#pragma once

template <class T, class V, class E, T (*merge)(T, T), T (*add_edge_fn)(T, E), T (*add_vertex_fn)(T, V)>
struct ReRootingDP {
 private:
  struct Edge {
    int to, idx, rev;
    E data;
  };

  int n;
  T id;
  vector<vector<Edge>> g;
  vector<V> vertex_data;
  vector<T> dp;
  vector<T> ans;
  vector<array<int, 2>> edge_pos;
  int edge_count = 0;

 public:
  ReRootingDP() {}
  ReRootingDP(int n, T id) : n(n), id(id), g(n), vertex_data(n) {}
  void set_vertex(int u, V data) { vertex_data[u] = data; }
  int add_edge(int u, int v, E data) { return add_edge(u, v, data, data); }
  int add_edge(int u, int v, E data, E rdata) {
    int did = dp.size();
    dp.push_back(id);
    dp.push_back(id);
    g[u].push_back({v, did, did + 1, data});
    g[v].push_back({u, did + 1, did, rdata});
    edge_pos.push_back({did, did + 1});
    return edge_count++;
  }
  vector<T> calc() {
    fill(dp.begin(), dp.end(), id);
    ans.assign(n, id);
    int max_deg = 0;
    for (int i = 0; i < n; i++) max_deg = max(max_deg, (int)g[i].size());
    vector<int> parent(n, -2), parent_edge(n, -1), order;
    order.reserve(n);
    for (int root = 0; root < n; root++) {
      if (parent[root] != -2) continue;
      parent[root] = -1;
      stack<int> st;
      st.push(root);
      while (!st.empty()) {
        int x = st.top();
        st.pop();
        order.push_back(x);
        for (int i = 0; i < (int)g[x].size(); i++) {
          int y = g[x][i].to;
          if (parent[y] != -2) continue;
          parent[y] = x;
          parent_edge[y] = g[x][i].rev;
          st.push(y);
        }
      }
    }
    for (int i = (int)order.size() - 1; i >= 0; i--) {
      int x = order[i];
      T val = id;
      for (auto& e : g[x]) {
        if (e.to == parent[x]) continue;
        val = merge(val, add_edge_fn(dp[e.rev], e.data));
      }
      if (parent[x] == -1)
        ans[x] = add_vertex_fn(val, vertex_data[x]);
      else
        dp[parent_edge[x]] = add_vertex_fn(val, vertex_data[x]);
    }
    vector<T> sum_r(max_deg + 1, id);
    for (int x : order) {
      int deg = g[x].size();
      sum_r[deg] = id;
      for (int i = deg - 1; i >= 0; i--) {
        auto& e = g[x][i];
        sum_r[i] = merge(sum_r[i + 1], add_edge_fn(dp[e.rev], e.data));
      }
      ans[x] = add_vertex_fn(sum_r[0], vertex_data[x]);
      T sum_l = id;
      for (int i = 0; i < deg; i++) {
        auto& e = g[x][i];
        if (e.to != parent[x]) {
          dp[e.idx] = add_vertex_fn(merge(sum_l, sum_r[i + 1]), vertex_data[x]);
        }
        sum_l = merge(sum_l, add_edge_fn(dp[e.rev], e.data));
      }
    }
    return ans;
  }
  T operator[](int i) const { return ans[i]; }
  T edge_subtree(int edge_id, int side) const {
    assert(0 <= edge_id && edge_id < edge_count);
    assert(0 <= side && side < 2);
    return dp[edge_pos[edge_id][side]];
  }
};

/**
 * @brief 全方位木 DP
 * @docs docs/tree/rerooting-dp.md
 */
