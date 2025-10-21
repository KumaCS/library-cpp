#pragma once

template <class fps>
class RelaxedConvolution {
  using mint = typename fps::value_type;
  int n, sz;
  fps f, g, h;
  void calc(int l1, int r1, int l2, int r2) {
    int len = r1 + r2 - 1;
    if (h.size() < len) h.resize(len);
    fps f1(f.begin() + l1, f.begin() + r1);
    fps g1(g.begin() + l2, g.begin() + r2);
    fps h1 = f1 * g1;
    for (int i = 0; i < h1.size(); i++) h[i + l1 + l2] += h1[i];
  }

 public:
  RelaxedConvolution() : n(0), sz(1) {
    n = 0;
    sz = 1;
    f.resize(sz);
    g.resize(sz);
    h.resize(sz * 2 - 1);
  }
  mint append(mint a, mint b) {
    if (n == sz) {
      sz <<= 1;
      f.resize(sz);
      g.resize(sz);
      h.resize(sz * 2 - 1);
    }
    f[n] = a, g[n] = b;
    n++;
    int m = (n + 1) & -(n + 1), s = 0;
    if (m <= n) {
      int k = 1;
      while (k <= m) {
        calc(n - k, n, s, s + k);
        calc(s, s + k, n - k, n);
        s += k;
        k <<= 1;
      }
    } else {
      int k = 1;
      while (k < (m >> 1)) {
        calc(n - k, n, s, s + k);
        calc(s, s + k, n - k, n);
        s += k;
        k <<= 1;
      }
      calc(n - k, n, s, s + k);
    }
    return h[n - 1];
  }
};
