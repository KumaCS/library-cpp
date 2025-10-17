#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#include "template/template.hpp"
#include "flow/max-flow.hpp"

int main() {
  int n, m;
  in(n, m);
  MaxFlow<int> g(n);
  rep(i, 0, m) {
    int u, v, w;
    in(u, v, w);
    g.add_edge(u, v, w);
  }
  out(g.flow(0, n - 1));
}