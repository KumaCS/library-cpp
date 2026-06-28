#pragma once

#include "data-structure/persistent-array.hpp"

struct PersistentUnionFind {
 private:
  PersistentArray<int, 8> a;

 public:
  PersistentUnionFind(int n) { a.build(vector<int>(n, -1)); }
  int find(int x) { return a.get(x) < 0 ? x : find(a.get(x)); }
  int size(int x) { return -a.get(find(x)); }
  bool same(int x, int y) { return find(x) == find(y); }
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (a.get(x) > a.get(y)) swap(x, y);
    *a.mutable_get(x) += a.get(y);
    *a.mutable_get(y) = x;
    return true;
  }
  int take_snapshot() { return a.take_snapshot(); }
  void apply_snapshot(int k) { a.apply_snapshot(k); }
};
/**
 * @brief Persistent Union Find
 * @docs docs/union-find/persistent-union-find.md
 */