#pragma once

#include "template/template.hpp"

struct UnionFind {
 private:
  vector<int> a;

 public:
  UnionFind(int n) : a(n, -1) {}
  int find(int x) { return a[x] < 0 ? x : a[x] = find(a[x]); }
  int size(int x) { return -a[find(x)]; }
  bool same(int x, int y) { return find(x) == find(y); }
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (a[x] > a[y]) swap(x, y);
    a[x] += a[y];
    a[y] = x;
    return true;
  }
  template <class F>
  bool unite(int x, int y, F f) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (a[x] > a[y]) swap(x, y);
    a[x] += a[y];
    a[y] = x;
    f(x, y);
    return true;
  }
  vector<vector<int>> groups() {
    vector<int> root(a.size()), gsize(a.size());
    for (int i = 0; i < a.size(); i++) gsize[root[i] = find(i)]++;
    vector<vector<int>> res(a.size());
    for (int i = 0; i < res.size(); i++) res[i].reserve(gsize[i]);
    for (int i = 0; i < root.size(); i++) res[root[i]].push_back(i);
    res.erase(remove_if(res.begin(), res.end(), [&](const vector<int>& v) { return v.empty(); }), res.end());
    return res;
  }
};

/**
 * @brief Union Find
 * @docs docs/union-find/union-find.md
 */