#pragma once

template <class mint, int n_>
struct SubsetConvolution {
  static constexpr int n = n_;
  using poly = array<mint, n_ + 1>;
  vector<int> pc;
  SubsetConvolution() {
    pc.assign(1 << n, 0);
    for (int i = 1; i < pc.size(); i++) pc[i] = pc[i >> 1] + (i & 1);
  }
  void poly_add(poly& p, const poly& q, int d) {
    for (int i = 0; i < d; i++) p[i] += q[i];
  }
  void poly_sub(poly& p, const poly& q, int d) {
    for (int i = d; i <= n; i++) p[i] -= q[i];
  }
  void poly_mul(poly& p, const poly& q) {
    poly r{};
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= n - i; j++)
        r[i + j] += p[i] * q[j];
    swap(p, r);
  }
  vector<poly> lift(const vector<mint>& a) {
    int n = a.size();
    assert(n == (n & -n));
    vector<poly> b(n);
    for (int i = 0; i < n; i++) {
      b[i].fill(0);
      b[i][pc[i]] = a[i];
    }
    return b;
  }
  vector<mint> unlift(const vector<poly>& b) {
    int n = b.size();
    assert(n == (n & -n));
    vector<mint> a(n);
    for (int i = 0; i < n; i++) a[i] = b[i][pc[i]];
    return a;
  }
  void ranked_zeta(vector<poly>& a) {
    int n = a.size();
    for (int i = 1; i < n; i <<= 1)
      for (int j = 0; j < n; j += i * 2)
        for (int k = 0; k < i; k++)
          poly_add(a[i + j + k], a[j + k], pc[i + j + k]);
  }
  void ranked_mobius(vector<poly>& a) {
    int n = a.size();
    for (int i = 1; i < n; i <<= 1)
      for (int j = 0; j < n; j += i * 2)
        for (int k = 0; k < i; k++)
          poly_sub(a[i + j + k], a[j + k], pc[i + j + k]);
  }
  void ranked_mul(vector<poly>& a, const vector<poly>& b) {
    for (int i = 0; i < a.size(); i++) poly_mul(a[i], b[i]);
  }
  vector<mint> multiply(const vector<mint>& a, const vector<mint>& b) {
    auto p = lift(a);
    auto q = lift(b);
    ranked_zeta(p);
    ranked_zeta(q);
    ranked_mul(p, q);
    ranked_mobius(p);
    return unlift(p);
  }
};

/**
 * @brief Subset Convolution
 * @docs docs/set/subset-convolution.md
 */