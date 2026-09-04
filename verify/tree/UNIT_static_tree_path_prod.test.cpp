#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "algebraic-structure/monoid.hpp"
#include "graph/graph.hpp"
#include "tree/static-tree-path-prod.hpp"
#include "util/xorshift.hpp"

struct StringMonoid {
  using value_type = string;
  static string op(const string& x, const string& y) { return x + y; }
  static string e() { return ""; }
};

vector<int> get_path(const GraphUnweighted& g, int s, int t) {
  int n = g.size();
  vector<int> p(n, -1), st = {s};
  p[s] = s;
  for (int i = 0; i < (int)st.size(); i++) {
    int x = st[i];
    for (auto e : g[x]) {
      if (p[e.to] != -1) continue;
      p[e.to] = x;
      st.push_back(e.to);
    }
  }
  vector<int> path;
  for (int x = t;; x = p[x]) {
    path.push_back(x);
    if (x == s) break;
  }
  reverse(path.begin(), path.end());
  return path;
}

int main() {
  rep(_, 0, 100) {
    int n = XORShift::xor32() % 24 + 1;
    int root = XORShift::xor32() % n;
    GraphUnweighted g(n);
    GraphWeighted<string> gs(n);
    GraphWeighted<long long> gl(n);
    vector<vector<string>> es(n, vector<string>(n));
    vector<vector<long long>> el(n, vector<long long>(n));
    rep(x, 1, n) {
      int p = XORShift::xor32() % x;
      string s(1, 'a' + XORShift::xor32() % 26);
      long long v = XORShift::xor32() % 100;
      g.add_edge(p, x);
      gs.add_edge(p, x, s);
      gl.add_edge(p, x, v);
      es[p][x] = es[x][p] = s;
      el[p][x] = el[x][p] = v;
    }
    vector<string> sv(n);
    vector<long long> lv(n);
    rep(x, 0, n) {
      sv[x] = string(1, 'A' + XORShift::xor32() % 26);
      lv[x] = XORShift::xor32() % 100;
    }

    StaticTreePathProd<StringMonoid, true, false> vs(g, sv, root);
    StaticTreePathProd<StringMonoid, false, true> es_ds(gs, root);
    StaticTreePathProd<StringMonoid, true, true> bs(gs, sv, root);
    StaticTreePathProdCommutative<AddMonoid<long long>, true, false> vl(g, lv, root);
    StaticTreePathProdCommutative<AddMonoid<long long>, false, true> el_ds(gl, root);
    StaticTreePathProdCommutative<AddMonoid<long long>, true, true> bl(gl, lv, root);

    vector<int> par(n, -1), dep(n), st = {root};
    for (int i = 0; i < (int)st.size(); i++) {
      int x = st[i];
      for (auto e : g[x]) {
        if (e.to == par[x]) continue;
        par[e.to] = x;
        dep[e.to] = dep[x] + 1;
        st.push_back(e.to);
      }
    }
    rep(s, 0, n) rep(t, 0, n) {
      vector<int> path = get_path(g, s, t);
      string ev, ee, eb = sv[path[0]];
      long long av = 0, ae = 0, ab = lv[path[0]];
      for (int i = 0; i < (int)path.size(); i++) {
        ev += sv[path[i]];
        av += lv[path[i]];
        if (i == 0) continue;
        int x = path[i - 1], y = path[i];
        ee += es[x][y];
        eb += es[x][y] + sv[y];
        ae += el[x][y];
        ab += el[x][y] + lv[y];
      }
      assert(vs.prod(s, t) == ev);
      assert(es_ds.prod(s, t) == ee);
      assert(bs.prod(s, t) == eb);
      assert(vl.prod(s, t) == av);
      assert(el_ds.prod(s, t) == ae);
      assert(bl.prod(s, t) == ab);

      int x = s, y = t;
      while (dep[x] > dep[y]) x = par[x];
      while (dep[y] > dep[x]) y = par[y];
      while (x != y) x = par[x], y = par[y];
      assert(vs.lca(s, t) == x);
      assert(vl.lca(s, t) == x);
    }
  }
  int a, b;
  in(a, b);
  out(a + b);
}
