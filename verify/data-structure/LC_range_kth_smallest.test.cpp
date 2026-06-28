#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include "template/template.hpp"
#include "data-structure/wavelet-matrix.hpp"

int main() {
  int n, q;
  in(n, q);
  vector<int> a(n);
  in(a);
  WaveletMatrix<int, 30> wm(a);
  while (q--) {
    int l, r, k;
    in(l, r, k);
    out(wm.kth_smallest(l, r, k));
  }
}
