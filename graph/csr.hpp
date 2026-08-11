#pragma once

// Compressed Sparse Row format
template <class E>
struct CSR {
  CSR() : start(1, 0) {}
  template <class G>
  CSR(const G& g) { build(g); }
  size_t size() const { return start.size() - 1; }
  size_t edge_count() const { return edges.size(); }
  span<const E> operator[](int x) const {
    assert(0 <= x && x < static_cast<int>(size()));
    return span<const E>(edges).subspan(start[x], start[x + 1] - start[x]);
  }
  template <class G>
  void build(const G& g) {
    int n = g.size();
    start.assign(n + 1, 0);
    for (int i = 0; i < n; i++) start[i + 1] = start[i] + g[i].size();
    edges.clear();
    edges.reserve(start[n]);
    for (int x = 0; x < n; x++)
      for (const auto& e : g[x]) edges.push_back(e);
  }

 private:
  vector<E> edges;
  vector<int> start;
};

/**
 * @brief Compressed Sparse Row
 * @docs docs/graph/csr.md
 */
