#define PROBLEM "https://judge.yosupo.jp/problem/stern_brocot_tree"

#include "template/template.hpp"
#include "math/stern-brocot-tree.hpp"
using sbt = SternBrocotTreeNode<ll>;

int main() {
  int t;
  in(t);
  while (t--) {
    string s;
    in(s);
    if (s == "ENCODE_PATH") {
      ll a, b;
      in(a, b);
      sbt x(a, b);
      cout << x.seq.size();
      for (auto v : x.seq) cout << " " << "LR"[v > 0] << " " << abs(v);
      cout << "\n";
    } else if (s == "DECODE_PATH") {
      sbt x;
      int k;
      in(k);
      rep(i, 0, k) {
        char dir;
        ll n;
        in(dir, n);
        if (dir == 'L')
          x.go_left(n);
        else
          x.go_right(n);
      }
      out(x.a, x.b);
    } else if (s == "LCA") {
      ll a, b, c, d;
      in(a, b, c, d);
      sbt x = sbt::lca(sbt(a, b), sbt(c, d));
      out(x.a, x.b);
    } else if (s == "ANCESTOR") {
      ll k, a, b;
      in(k, a, b);
      sbt x(a, b);
      ll d = x.depth() - k;
      if (d >= 0 && x.go_parent(d))
        out(x.a, x.b);
      else
        out(-1);
    } else if (s == "RANGE") {
      ll a, b;
      in(a, b);
      sbt x(a, b);
      out(x.lower_bound(), x.upper_bound());
    }
  }
}