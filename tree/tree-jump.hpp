#pragma once

struct TreeJump {
  inline static int topbit(int x) {
    return (x == 0 ? -1 : 31 - __builtin_clz((unsigned int)x));
  }
  int n;
  vector<vector<int>> p;
  vector<int> depth;
  TreeJump() : n(0) {}
  template <class G>
  TreeJump(const G& g, int root = 0) {
    build(g, root);
  }
  template <class G>
  void build(const G& g, int root = 0) {
    n = g.size();
    assert(n > 0);
    assert(0 <= root && root < n);
    p.assign(n, {});
    depth.assign(n, 0);
    stack<int> st;
    st.push(root);
    while (!st.empty()) {
      int x = st.top();
      st.pop();
      for (int k = 0; k < static_cast<int>(p[x].size()); k++) {
        int y = p[x][k];
        if (k >= static_cast<int>(p[y].size())) break;
        p[x].push_back(p[y][k]);
      }
      int par = p[x].empty() ? -1 : p[x][0];
      for (const auto& e : g[x]) {
        int y = e.to;
        if (y == par) continue;
        p[y].push_back(x);
        depth[y] = depth[x] + 1;
        st.push(y);
      }
    }
  }
  int ancestor(int x, int k = 1) const {
    assert(0 <= x && x < n);
    assert(k >= 0);
    if (depth[x] < k) return -1;
    while (k > 0) {
      int l = topbit(k);
      x = p[x][l];
      k ^= 1 << l;
    }
    return x;
  }
  int lca(int x, int y) const {
    assert(0 <= x && x < n);
    assert(0 <= y && y < n);
    if (depth[x] < depth[y]) y = ancestor(y, depth[y] - depth[x]);
    if (depth[x] > depth[y]) x = ancestor(x, depth[x] - depth[y]);
    if (x == y) return x;
    for (int l = topbit(depth[x]); l >= 0; l--) {
      int ml = min((int)p[x].size(), (int)p[y].size()) - 1;
      if (ml < l) l = ml;
      int x1 = p[x][l];
      int y1 = p[y][l];
      if (x1 != y1) x = x1, y = y1;
    }
    return p[x][0];
  }
  int dist(int x, int y) const {
    return depth[x] + depth[y] - depth[lca(x, y)] * 2;
  }
  int jump(int x, int y, int k = 1) const {
    assert(0 <= k);
    int z = lca(x, y);
    int dx = depth[x] - depth[z];
    int dy = depth[y] - depth[z];
    if (k <= dx) return ancestor(x, k);
    int d = dx + dy;
    return k <= d ? ancestor(y, d - k) : -1;
  }
};
/**
 * @brief Tree Jump
 * @docs docs/tree/tree-jump.md
 */
