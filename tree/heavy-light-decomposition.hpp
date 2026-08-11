#pragma once

struct HeavyLightDecomposition {
  vector<int> vertices, pos, parent, depth, heavy_root;
  HeavyLightDecomposition() {}
  template <class G>
  HeavyLightDecomposition(const G& g, int root = 0) { build(g, root); }

  template <class F>
  void path(int x, int y, F f) const {
    int n = parent.size();
    assert(0 <= x && x < n);
    assert(0 <= y && y < n);
    array<pair<int, int>, numeric_limits<unsigned int>::digits> right;
    int right_size = 0;
    while (heavy_root[x] != heavy_root[y]) {
      int hx = heavy_root[x], hy = heavy_root[y];
      if (depth[hx] >= depth[hy]) {
        f(pos[hx], pos[x] + 1, true);
        x = parent[hx];
      } else {
        assert(right_size < static_cast<int>(right.size()));
        right[right_size++] = {pos[hy], pos[y] + 1};
        y = parent[hy];
      }
    }
    if (pos[x] <= pos[y])
      f(pos[x], pos[y] + 1, false);
    else
      f(pos[y], pos[x] + 1, true);
    for (int i = right_size - 1; i >= 0; i--) f(right[i].first, right[i].second, false);
  }

  template <class G>
  void build(const G& g, int root = 0) {
    int n = g.size();
    assert(n > 0);
    assert(0 <= root && root < n);
    parent.assign(n, -2);
    depth.assign(n, 0);
    parent[root] = -1;
    vertices.clear();
    vertices.reserve(n);
    stack<int> st;
    st.push(root);
    while (!st.empty()) {
      int x = st.top();
      st.pop();
      vertices.push_back(x);
      for (const auto& e : g[x]) {
        int y = e.to;
        if (parent[y] != -2) continue;
        parent[y] = x;
        depth[y] = depth[x] + 1;
        st.push(y);
      }
    }
    assert(static_cast<int>(vertices.size()) == n);
    vector<int> subtree_size(n, 1), heavy(n, -1);
    for (auto it = vertices.rbegin(); it != vertices.rend(); it++) {
      int x = *it, p = parent[x];
      if (p != -1) {
        subtree_size[p] += subtree_size[x];
        if (heavy[p] == -1 || subtree_size[x] > subtree_size[heavy[p]]) heavy[p] = x;
      }
    }
    vertices.clear();
    pos.resize(n);
    heavy_root.resize(n);
    stack<pair<int, int>> paths;
    paths.push({root, root});
    while (!paths.empty()) {
      auto [start, head] = paths.top();
      paths.pop();
      for (int x = start; x != -1; x = heavy[x]) {
        pos[x] = static_cast<int>(vertices.size());
        vertices.push_back(x);
        heavy_root[x] = head;
        for (const auto& e : g[x]) {
          int y = e.to;
          if (parent[y] == x && y != heavy[x]) paths.push({y, y});
        }
      }
    }
  }
};

/**
 * @brief Heavy Light Decomposition
 * @docs docs/tree/heavy-light-decomposition.md
 */
