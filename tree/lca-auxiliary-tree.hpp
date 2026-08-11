#pragma once
#include "tree/lowest-common-ancestor.hpp"

struct LCAAuxiliaryTree : LowestCommonAncestor {
  using base = LowestCommonAncestor;
  LCAAuxiliaryTree() = default;
  template <class G>
  LCAAuxiliaryTree(const G& g, int root = 0) : base(g, root) {}
  template <class G>
  pair<int, vector<int>> calc(vector<int> vs, G& g) const {
    if (vs.empty()) return {-1, vector<int>{}};
    assert(static_cast<int>(g.size()) == n);
    for (int x : vs) assert(0 <= x && x < n);
    sort(vs.begin(), vs.end(), [&](int x, int y) { return in_time[x] < in_time[y]; });
    vs.erase(unique(vs.begin(), vs.end()), vs.end());
    int m = vs.size();
    stack<int> path;
    path.push(vs[0]);
    g[vs[0]] = {};
    for (int i = 0; i < m - 1; i++) {
      int x = vs[i], y = vs[i + 1];
      int w = lca(x, y);
      if (w != x) {
        int last = path.top();
        path.pop();
        while (!path.empty() && depth[w] < depth[path.top()]) {
          g[path.top()].push_back({last});
          last = path.top();
          path.pop();
        }
        if (path.empty() || path.top() != w) {
          path.push(w);
          vs.push_back(w);
          g[w] = {{last}};
        } else
          g[w].push_back({last});
      }
      path.push(y);
      g[y] = {};
    }
    int prv = path.top();
    path.pop();
    while (!path.empty()) {
      g[path.top()].push_back({prv});
      prv = path.top();
      path.pop();
    }
    sort(vs.begin(), vs.end(), [&](int x, int y) { return in_time[x] < in_time[y]; });
    return {prv, vs};
  }
};
/**
 * @brief LCA ベースの Auxiliary Tree
 * @docs docs/tree/lca-auxiliary-tree.md
 */
