#pragma once

#include "data-structure/persistent-array.hpp"
#include "algebraic-structure/group.hpp"

template <class G>
REQUIRES(Group<G>)
struct PersistentPotentializedUnionFind {
  using T = typename G::value_type;

 private:
  PersistentArray<int, 8> a;
  PersistentArray<T, 8> p;

 public:
  PersistentPotentializedUnionFind(int n) {
    a.build(vector<int>(n, -1));
    p.build(vector<T>(n, G::e()));
  }
  int find(int x) { return a.get(x) < 0 ? x : find(a.get(x)); }
  T pot(int x) {
    int y = a.get(x);
    return y < 0 ? p.get(x) : G::op(p.get(x), pot(y));
  }
  T diff(int x, int y) { return G::op(pot(x), G::inv(pot(y))); }
  int size(int x) { return -a.get(find(x)); }
  bool same(int x, int y) { return find(x) == find(y); }
  // pot(u) - pot(v) = w
  // return : consistent
  bool unite(int u, int v, T w) {
    int x = find(u), y = find(v);
    if (x == y) return diff(u, v) == w;
    w = G::op(G::op(w, G::inv(pot(u))), pot(v));
    auto ax = a.get(x);
    auto ay = a.get(y);
    if (ax < ay) {
      *p.mutable_get(y) = G::op(p.get(x), G::inv(w));
      *a.mutable_get(x) += ay;
      *a.mutable_get(y) = x;
    } else {
      *p.mutable_get(x) = G::op(p.get(y), w);
      *a.mutable_get(y) += ax;
      *a.mutable_get(x) = y;
    }
    return true;
  }
  int take_snapshot() {
    a.take_snapshot();
    return p.take_snapshot();
  }
  void apply_snapshot(int k) {
    a.apply_snapshot(k);
    p.apply_snapshot(k);
  }
};
/**
 * @brief Persistent Potentialized Union Find
 * @docs docs/union-find/persistent-potentialized-union-find.md
 */
