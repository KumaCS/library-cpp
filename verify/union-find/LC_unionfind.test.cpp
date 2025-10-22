#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "template/template.hpp"
#include "union-find/union-find.hpp"

int main() {
  int n, q;
  in(n, q);
  UnionFind uf(n);
  while (q--) {
    int t, u, v;
    in(t, u, v);
    if (t == 0)
      uf.unite(u, v);
    else
      out(uf.same(u, v));
  }
}