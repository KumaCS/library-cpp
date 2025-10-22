#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "template/template.hpp"
#include "data-structure/sparse-table.hpp"

int op(int x, int y) { return min(x, y); }

int main() {
  int n, q;
  in(n, q);
  vector<int> a(n);
  in(a);
  SparseTable<int, op> st(a);
  while (q--) {
    int l, r;
    in(l, r);
    out(st.prod(l, r));
  }
}