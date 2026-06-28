#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"

#include "template/template.hpp"
#include "data-structure/wavelet-matrix.hpp"

int main() {
  int n, q;
  in(n, q);
  vector<int> a(n);
  in(a);
  WaveletMatrix<int, 30> wm(a);
  while (q--) {
    int l, r, x;
    in(l, r, x);
    out(wm.range_freq(l, r, x, x + 1, 0));
  }
}
