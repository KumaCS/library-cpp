#pragma once

namespace ShortestPath {
namespace Internal {
template <class G, class F>
vector<optional<int>> bfs(const G& g, int root, F on_relax) {
  assert(0 <= root && root < static_cast<int>(g.size()));
  vector<optional<int>> dist(g.size(), nullopt);
  dist[root] = 0;
  queue<int> qu;
  qu.push(root);
  while (!qu.empty()) {
    int x = qu.front();
    qu.pop();
    for (const auto& e : g[x]) {
      int y = e.to;
      if (chmin_opt(dist[y], *dist[x] + 1)) {
        on_relax(x, y);
        qu.push(y);
      }
    }
  }
  return dist;
}
template <class T, class G, class F>
vector<optional<T>> zero_one_bfs(const G& g, int root, F on_relax) {
  assert(0 <= root && root < static_cast<int>(g.size()));
  const T zero = T(0), one = T(1);
  vector<optional<T>> dist(g.size(), nullopt);
  dist[root] = zero;
  deque<int> deq;
  deq.push_back(root);
  while (!deq.empty()) {
    int x = deq.front();
    deq.pop_front();
    for (const auto& e : g[x]) {
      int y = e.to;
      const T& w = e.weight;
      if (w == zero) {
        if (chmin_opt(dist[y], *dist[x])) {
          on_relax(x, y);
          deq.push_front(y);
        }
      } else if (w == one) {
        if (chmin_opt(dist[y], *dist[x] + one)) {
          on_relax(x, y);
          deq.push_back(y);
        }
      } else {
        assert(false);
      }
    }
  }
  return dist;
}
template <class T, class G, class F>
vector<optional<T>> dijkstra(const G& g, const T zero, int root, F on_relax) {
  assert(0 <= root && root < static_cast<int>(g.size()));
  vector<optional<T>> dist(g.size(), nullopt);
  dist[root] = zero;
  priority_queue_asc<pair<T, int>> pq;
  pq.push({zero, root});
  while (!pq.empty()) {
    auto [dx, x] = pq.top();
    pq.pop();
    if (!dist[x] || dx != *dist[x]) continue;
    for (const auto& e : g[x]) {
      int y = e.to;
      T nd = dx + e.weight;
      if (chmin_opt(dist[y], nd)) {
        on_relax(x, y);
        pq.push({nd, y});
      }
    }
  }
  return dist;
}
}  // namespace Internal

template <class G>
vector<optional<int>> BFS(const G& g, int root) {
  return Internal::bfs(g, root, [](int, int) {});
}
template <class G>
pair<vector<optional<int>>, vector<optional<int>>> BFSWithPrev(const G& g, int root) {
  vector<optional<int>> prev(g.size(), nullopt);
  auto dist = Internal::bfs(g, root, [&](int x, int y) { prev[y] = x; });
  return {dist, prev};
}

template <class T = int, class G>
vector<optional<T>> ZeroOneBFS(const G& g, int root) {
  return Internal::zero_one_bfs<T>(g, root, [](int, int) {});
}
template <class T = int, class G>
pair<vector<optional<T>>, vector<optional<int>>> ZeroOneBFSWithPrev(const G& g, int root) {
  vector<optional<int>> prev(g.size(), nullopt);
  auto dist = Internal::zero_one_bfs<T>(g, root, [&](int x, int y) { prev[y] = x; });
  return {dist, prev};
}

template <class T, class G>
vector<optional<T>> Dijkstra(const G& g, const T zero, int root) {
  return Internal::dijkstra<T>(g, zero, root, [](int, int) {});
}
template <class T, class G>
pair<vector<optional<T>>, vector<optional<int>>> DijkstraWithPrev(const G& g, const T zero, int root) {
  vector<optional<int>> prev(g.size(), nullopt);
  auto dist = Internal::dijkstra<T>(g, zero, root, [&](int x, int y) { prev[y] = x; });
  return {dist, prev};
}
vector<int> EnumeratePath(const vector<optional<int>>& prev, int goal) {
  assert(0 <= goal && goal < static_cast<int>(prev.size()));
  vector<int> path{goal};
  for (int x = goal;;) {
    if (!prev[x]) break;
    x = *prev[x];
    path.push_back(x);
  }
  reverse(path.begin(), path.end());
  return path;
}
}  // namespace ShortestPath

/**
 * @brief Shortest Path
 * @docs docs/graph/shortest-path.md
 */
