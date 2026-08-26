#pragma once

#include "graph/graph.hpp"

template <class G>
optional<vector<int>> CycleDetection(const G& g) {
  int n = g.size();
  vector<unsigned char> state(n);
  vector<int> iter(n), path_pos(n), st, path;
  st.reserve(n);
  path.reserve(n);
  for (int root = 0; root < n; root++) {
    if (state[root] != 0) continue;
    state[root] = 1;
    path_pos[root] = 0;
    st.push_back(root);
    while (!st.empty()) {
      int x = st.back();
      if (iter[x] == static_cast<int>(g[x].size())) {
        state[x] = 2;
        st.pop_back();
        if (!st.empty()) path.pop_back();
        continue;
      }
      const auto& e = g[x][iter[x]++];
      int y = e.to;
      if (state[y] == 0) {
        state[y] = 1;
        path.push_back(e.id);
        path_pos[y] = path.size();
        st.push_back(y);
      } else if (state[y] == 1) {
        vector<int> cycle(path.begin() + path_pos[y], path.end());
        cycle.push_back(e.id);
        return cycle;
      }
    }
  }
  return nullopt;
}

/**
 * @brief Cycle Detection
 * @docs docs/graph/cycle-detection.md
 */
