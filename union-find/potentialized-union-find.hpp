#pragma once

template <class T>
struct PotentializedUnionFind {
 private:
  vector<int> a;
  vector<T> p;

 public:
  PotentializedUnionFind(int n) : a(n, -1), p(n, 0) {}
  int find(int v) {
    if (a[v] < 0) return v;
    int r = find(a[v]);
    p[v] += p[a[v]];
    return a[v] = r;
  }
  int size(int v) { return -a[find(v)]; }
  bool same(int u, int v) { return find(u) == find(v); }
  // p[u]-p[v]=w
  bool unite(int u, int v, T w) {
    int x = find(u), y = find(v);
    if (x == y) return p[u] - p[v] == w;
    w -= p[u], w += p[v];
    if (a[x] < a[y]) {
      p[y] = p[x] - w;
      a[x] += a[y];
      a[y] = x;
    } else {
      p[x] = p[y] + w;
      a[y] += a[x];
      a[x] = y;
    }
    return true;
  }
  // p[u]-p[v]
  T diff(int u, int v) { return p[u] - p[v]; }
};
/**
 * @brief ポテンシャル付き Union Find
 * @docs docs/union-find/potentialized-union-find.md
 */