#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include "template/template.hpp"
#include "graph/graph.hpp"
#include "modint/modint.hpp"
#include "tree/tree-vertex-set-path-prod.hpp"

using mint = ModInt998244353;
struct F {
  mint a, b;
  mint eval(mint x) const { return a * x + b; }
};
struct CompositeMonoid {
  using value_type = F;
  static F op(F f, F g) { return {f.a * g.a, f.b * g.a + g.b}; }
  static F e() { return {1, 0}; }
};
int main() {
  int n, q;
  in(n, q);
  vector<F> f(n);
  rep(x, 0, n) in(f[x].a, f[x].b);
  GraphUnweighted g(n);
  rep(i, 0, n - 1) {
    int u, v;
    in(u, v);
    g.add_edge(u, v);
  }
  TreeVertexSetPathProd<CompositeMonoid> ds(g, f);
  while (q--) {
    int type;
    in(type);
    if (type == 0) {
      int p;
      F v;
      in(p, v.a, v.b);
      ds.set(p, v);
    } else {
      int u, v;
      mint x;
      in(u, v, x);
      out(ds.prod(u, v).eval(x));
    }
  }
}
