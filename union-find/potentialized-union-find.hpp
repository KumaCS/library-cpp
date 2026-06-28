#pragma once
#include "algebraic-structure/group.hpp"

template <class G>
REQUIRES(Group<G>)
struct PotentializedUnionFind {
  using T = typename G::value_type;

 private:
  vector<int> a;
  vector<T> p;

 public:
  PotentializedUnionFind(int n) : a(n, -1), p(n, G::e()) {}
  int find(int v) {
    if (a[v] < 0) return v;
    int r = find(a[v]);
    p[v] = G::op(p[v], p[a[v]]);
    return a[v] = r;
  }
  int size(int v) { return -a[find(v)]; }
  bool same(int u, int v) { return find(u) == find(v); }
  // p[u]-p[v]=w
  bool unite(int u, int v, T w) {
    int x = find(u), y = find(v);
    if (x == y) return p[u] == G::op(p[v], w);
    w = G::op(G::op(w, G::inv(p[u])), p[v]);
    if (a[x] < a[y]) {
      p[y] = G::op(p[x], G::inv(w));
      a[x] += a[y];
      a[y] = x;
    } else {
      p[x] = G::op(p[y], w);
      a[y] += a[x];
      a[x] = y;
    }
    return true;
  }
  // p[u]-p[v]
  T diff(int u, int v) {
    find(u);
    find(v);
    return G::op(p[u], G::inv(p[v]));
  }
};
/**
 * @brief ポテンシャル付き Union Find
 * @docs docs/union-find/potentialized-union-find.md
 */
