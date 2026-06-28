#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum_with_upper_bound"

#include "template/template.hpp"
#include "data-structure/wavelet-matrix-with-weight.hpp"

int main() {
  int n, q;
  in(n, q);
  vector<int> a(n);
  in(a);
  vector<ll> w(n);
  rep(i, 0, n) w[i] = a[i];
  WaveletMatrixWithWeight<int, ll, 30> wm(a, w);
  while (q--) {
    int l, r, x;
    in(l, r, x);
    int upper = x + 1;
    out(wm.range_freq(l, r, upper), wm.range_sum(l, r, 0, upper));
  }
}
