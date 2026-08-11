#pragma once

#include "template/template.hpp"

template <class E>
struct GraphBase {
 public:
  GraphBase() : GraphBase(0) {}
  GraphBase(int size) : n(size) {
    assert(size >= 0);
    g.resize(size);
  }
  size_t size() const { return n; }
  const vector<E>& operator[](int x) const {
    assert(0 <= x && x < n);
    return g[x];
  }
  vector<E>& operator[](int x) {
    assert(0 <= x && x < n);
    return g[x];
  }

 protected:
  int n;
  vector<vector<E>> g;
};

struct EdgeUnweighted {
  int to;
};
struct GraphUnweighted : GraphBase<EdgeUnweighted> {
  using base = GraphBase<EdgeUnweighted>;

 public:
  GraphUnweighted() : base(0) {}
  GraphUnweighted(int size) : base(size) {}
  GraphUnweighted(const vector<vector<int>>& graph) : base(graph.size()) {
    for (int x = 0; x < n; x++) {
      base::g[x].reserve(graph[x].size());
      for (int y : graph[x]) base::g[x].push_back({y});
    }
  }
  void add_edge(int x, int y) {
    (*this)[x].push_back({y});
    (*this)[y].push_back({x});
  }
  void add_edge_directed(int from, int to) { (*this)[from].push_back({to}); }
};

template <class T>
struct EdgeWeighted {
  int to;
  T weight;
};
template <class T>
struct GraphWeighted : GraphBase<EdgeWeighted<T>> {
  using base = GraphBase<EdgeWeighted<T>>;

 public:
  GraphWeighted() : base(0) {}
  GraphWeighted(int size) : base(size) {}
  GraphWeighted(const vector<vector<pair<int, T>>>& graph) : base(graph.size()) {
    for (int x = 0; x < base::n; x++) {
      base::g[x].reserve(graph[x].size());
      for (const auto& [y, w] : graph[x]) base::g[x].push_back({y, w});
    }
  }
  void add_edge(int x, int y, T w) {
    (*this)[x].push_back({y, w});
    (*this)[y].push_back({x, w});
  }
  void add_edge_directed(int from, int to, T w) { (*this)[from].push_back({to, w}); }
};

inline GraphWeighted<int> GraphUnweightedToWeighted(const GraphUnweighted& g) {
  GraphWeighted<int> h(g.size());
  for (int x = 0; x < static_cast<int>(g.size()); x++) {
    h[x].reserve(g[x].size());
    for (const auto& e : g[x]) h[x].push_back({e.to, 1});
  }
  return h;
}

/**
 * @brief Graph
 * @docs docs/graph/graph.md
 */
