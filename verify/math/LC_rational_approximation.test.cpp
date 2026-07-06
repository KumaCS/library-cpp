#define PROBLEM "https://judge.yosupo.jp/problem/rational_approximation"

#include "template/template.hpp"
#include "math/stern-brocot-tree.hpp"
using sbt = SternBrocotTreeNode<ll>;

int main() {
  int t;
  in(t);
  while (t--) {
    ll n, x, y;
    in(n, x, y);
    auto [lower, upper] = sbt::binary_search(n, [&](ll p, ll q) {
      return q == 0 || (__int128)x * q < (__int128)y * p;
    });
    out(lower, upper);
  }
}
