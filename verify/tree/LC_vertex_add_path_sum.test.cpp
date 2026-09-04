#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "template/template.hpp"
#include "algebraic-structure/monoid.hpp"
#include "graph/graph.hpp"
#include "tree/tree-vertex-set-path-prod.hpp"

int main() {
  int n, q;
  in(n, q);
  vector<long long> a(n);
  in(a);
  GraphUnweighted g(n);
  rep(i, 0, n - 1) {
    int u, v;
    in(u, v);
    g.add_edge(u, v);
  }
  TreeVertexSetPathProdCommutative<AddMonoid<long long>> ds(g, a);
  while (q--) {
    int type, x;
    in(type, x);
    if (type == 0) {
      long long v;
      in(v);
      ds.apply(x, v);
    } else {
      int y;
      in(y);
      out(ds.prod(x, y));
    }
  }
}
