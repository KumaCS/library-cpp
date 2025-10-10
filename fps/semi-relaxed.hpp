#pragma once

template <class fps>
class SemiRelaxedConvolution {
  using mint = typename fps::value_type;
  int n;
  fps f, g, h;
  void calc(int l1, int r1, int l2, int r2) {
    fps f1(f.begin() + l1, f.begin() + r1);
    fps g1(g.begin() + l2, g.begin() + r2);
    fps h1 = f1 * g1;
    for (int i = 0; i < h1.size(); i++) h[i + l1 + l2] += h1[i];
  }

 public:
  SemiRelaxedConvolution(const fps &f_, int g_deg) : n(0), f(f_), g(g_deg, 0) {
    for (int k = 0;; k++)
      if ((1 << k) - 1 >= (int)f.size()) {
        h = fps((1 << k) - 1 + g_deg, 0);
        break;
      }
  }
  mint append(mint a) {
    g[n++] = a;
    for (int p = 1;; p <<= 1) {
      int l1 = p - 1, r1 = l1 + p, l2 = n - p, r2 = n;
      r1 = min(r1, (int)f.size());
      if (l1 >= r1) break;
      calc(l1, r1, l2, r2);
      if (p == (-n & n)) break;
    }
    return h[n - 1];
  }
};
