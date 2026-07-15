#define PROBLEM "https://judge.yosupo.jp/problem/factorial"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt998244353;
#include "fps/fps-ntt-friendly.hpp"
#include "fps/p-recursive.hpp"

int main() {
  int t;
  in(t);
  vector<mint> a(8, 1);
  for (int i = 1; i < (int)a.size(); i++) a[i] = a[i - 1] * i;
  while (t--) {
    int n;
    in(n);
    out(PRecursiveTerm(a, n, 1));
  }
}
