#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "template/template.hpp"
#include "data-structure/sparse-table.hpp"

int main() {
  int n, q;
  in(n, q);
  vector<int> a(n);
  in(a);
  SparseTable<MinMagma<int, 0>> st(a);
  while (q--) {
    int l, r;
    in(l, r);
    out(st.prod(l, r));
  }
}
