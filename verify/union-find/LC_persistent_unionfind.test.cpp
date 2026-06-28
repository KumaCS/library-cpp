#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include "template/template.hpp"
#include "union-find/persistent-union-find.hpp"

int main() {
  int n, q;
  in(n, q);
  PersistentUnionFind uf(n);
  while (q--) {
    uf.take_snapshot();
    int t, k, u, v;
    in(t, k, u, v);
    uf.apply_snapshot(k + 1);
    if (t == 0)
      uf.unite(u, v);
    else
      out(uf.same(u, v));
  }
}