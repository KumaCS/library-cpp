#pragma once
#include "tree/lowest-common-ancestor.hpp"

struct LCAAuxiliaryTree : LowestCommonAncestor {
  using base = LowestCommonAncestor;
  LCAAuxiliaryTree(int size, int root = 0) : base(size, root) {}
  LCAAuxiliaryTree(vector<vector<int>>& graph, int root = 0) : base(graph, root) {}
  pair<int, vector<int>> calc(vector<int> vs, vector<vector<int>>& g) {
    if (vs.empty()) return {-1, vector<int>{}};
    int n = vs.size();
    sort(vs.begin(), vs.end(), [&](int x, int y) { return in_time[x] < in_time[y]; });
    stack<int> st;
    st.push(vs[0]);
    g[vs[0]] = {};
    for (int i = 0; i < n - 1; i++) {
      int x = vs[i], y = vs[i + 1];
      int w = lca(x, y);
      if (w != x) {
        int last = st.top();
        st.pop();
        while (!st.empty() && depth[w] < depth[st.top()]) {
          g[st.top()].push_back(last);
          last = st.top();
          st.pop();
        }
        if (st.empty() || st.top() != w) {
          st.push(w);
          vs.push_back(w);
          g[w] = {last};
        } else
          g[w].push_back(last);
      }
      st.push(y);
      g[y] = {};
    }
    int prv = st.top();
    st.pop();
    while (!st.empty()) {
      g[st.top()].push_back(prv);
      prv = st.top();
      st.pop();
    }
    sort(vs.begin(), vs.end(), [&](int x, int y) { return in_time[x] < in_time[y]; });
    return {prv, vs};
  }
};
/**
 * @brief LCA ベースの Auxiliary Tree
 * @docs docs/tree/lca-auxiliary-tree.md
 */