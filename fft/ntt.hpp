#pragma once

template <class mint>
struct NTT {
  static constexpr unsigned int mod = mint::get_mod();
  static constexpr unsigned long long pow_constexpr(unsigned long long x, unsigned long long n, unsigned long long m) {
    unsigned long long y = 1;
    while (n) {
      if (n & 1) y = y * x % m;
      x = x * x % m;
      n >>= 1;
    }
    return y;
  }
  static constexpr unsigned int get_g() {
    unsigned long long x = 2;
    while (pow_constexpr(x, (mod - 1) >> 1, mod) == 1) x += 1;
    return x;
  }
  static constexpr unsigned int g = get_g();
  static constexpr int rank2 = __builtin_ctzll(mod - 1);
  array<mint, rank2 + 1> root;
  array<mint, rank2 + 1> iroot;
  array<mint, max(0, rank2 - 2 + 1)> rate2;
  array<mint, max(0, rank2 - 2 + 1)> irate2;
  array<mint, max(0, rank2 - 3 + 1)> rate3;
  array<mint, max(0, rank2 - 3 + 1)> irate3;

  NTT() {
    root[rank2] = mint(g).pow((mod - 1) >> rank2);
    iroot[rank2] = root[rank2].inv();
    for (int i = rank2 - 1; i >= 0; i--) {
      root[i] = root[i + 1] * root[i + 1];
      iroot[i] = iroot[i + 1] * iroot[i + 1];
    }
    {
      mint prod = 1, iprod = 1;
      for (int i = 0; i <= rank2 - 2; i++) {
        rate2[i] = root[i + 2] * prod;
        irate2[i] = iroot[i + 2] * iprod;
        prod *= iroot[i + 2];
        iprod *= root[i + 2];
      }
    }
    {
      mint prod = 1, iprod = 1;
      for (int i = 0; i <= rank2 - 3; i++) {
        rate3[i] = root[i + 3] * prod;
        irate3[i] = iroot[i + 3] * iprod;
        prod *= iroot[i + 3];
        iprod *= root[i + 3];
      }
    }
  }
  void ntt(vector<mint> &a) {
    int n = int(a.size());
    int h = __builtin_ctzll((unsigned int)n);
    a.resize(1 << h);
    int len = 0;  // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed
    while (len < h) {
      if (h - len == 1) {
        int p = 1 << (h - len - 1);
        mint rot = 1;
        for (int s = 0; s < (1 << len); s++) {
          int offset = s << (h - len);
          for (int i = 0; i < p; i++) {
            auto l = a[i + offset];
            auto r = a[i + offset + p] * rot;
            a[i + offset] = l + r;
            a[i + offset + p] = l - r;
          }
          if (s + 1 != (1 << len))
            rot *= rate2[__builtin_ctzll(~(unsigned int)(s))];
        }
        len++;
      } else {
        // 4-base
        int p = 1 << (h - len - 2);
        mint rot = 1, imag = root[2];
        for (int s = 0; s < (1 << len); s++) {
          mint rot2 = rot * rot;
          mint rot3 = rot2 * rot;
          int offset = s << (h - len);
          for (int i = 0; i < p; i++) {
            auto mod2 = 1ULL * mint::get_mod() * mint::get_mod();
            auto a0 = 1ULL * a[i + offset].val();
            auto a1 = 1ULL * a[i + offset + p].val() * rot.val();
            auto a2 = 1ULL * a[i + offset + 2 * p].val() * rot2.val();
            auto a3 = 1ULL * a[i + offset + 3 * p].val() * rot3.val();
            auto a1na3imag = 1ULL * mint(a1 + mod2 - a3).val() * imag.val();
            auto na2 = mod2 - a2;
            a[i + offset] = a0 + a2 + a1 + a3;
            a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));
            a[i + offset + 2 * p] = a0 + na2 + a1na3imag;
            a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);
          }
          if (s + 1 != (1 << len))
            rot *= rate3[__builtin_ctzll(~(unsigned int)(s))];
        }
        len += 2;
      }
    }
  }
  void intt(vector<mint> &a) {
    int n = int(a.size());
    int h = __builtin_ctzll((unsigned int)n);
    a.resize(1 << h);

    int len = h;  // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed
    while (len) {
      if (len == 1) {
        int p = 1 << (h - len);
        mint irot = 1;
        for (int s = 0; s < (1 << (len - 1)); s++) {
          int offset = s << (h - len + 1);
          for (int i = 0; i < p; i++) {
            auto l = a[i + offset];
            auto r = a[i + offset + p];
            a[i + offset] = l + r;
            a[i + offset + p] =
                (unsigned long long)(mint::get_mod() + l.val() - r.val()) *
                irot.val();
          }
          if (s + 1 != (1 << (len - 1)))
            irot *= irate2[__builtin_ctzll(~(unsigned int)(s))];
        }
        len--;
      } else {
        // 4-base
        int p = 1 << (h - len);
        mint irot = 1, iimag = iroot[2];
        for (int s = 0; s < (1 << (len - 2)); s++) {
          mint irot2 = irot * irot;
          mint irot3 = irot2 * irot;
          int offset = s << (h - len + 2);
          for (int i = 0; i < p; i++) {
            auto a0 = 1ULL * a[i + offset + 0 * p].val();
            auto a1 = 1ULL * a[i + offset + 1 * p].val();
            auto a2 = 1ULL * a[i + offset + 2 * p].val();
            auto a3 = 1ULL * a[i + offset + 3 * p].val();
            auto a2na3iimag =
                1ULL * mint((mint::get_mod() + a2 - a3) * iimag.val()).val();
            a[i + offset] = a0 + a1 + a2 + a3;
            a[i + offset + 1 * p] =
                (a0 + (mint::get_mod() - a1) + a2na3iimag) * irot.val();
            a[i + offset + 2 * p] =
                (a0 + a1 + (mint::get_mod() - a2) + (mint::get_mod() - a3)) *
                irot2.val();
            a[i + offset + 3 * p] =
                (a0 + (mint::get_mod() - a1) + (mint::get_mod() - a2na3iimag)) *
                irot3.val();
          }
          if (s + 1 != (1 << (len - 2)))
            irot *= irate3[__builtin_ctzll(~(unsigned int)(s))];
        }
        len -= 2;
      }
    }
    mint e = mint(n).inv();
    for (auto &x : a) x *= e;
  }
  vector<mint> multiply(const vector<mint> &a, const vector<mint> &b) {
    if (a.empty() || b.empty()) return vector<mint>();
    int n = a.size(), m = b.size();
    int sz = n + m - 1;
    if (n <= 30 || m <= 30) {
      if (n > 30) return multiply(b, a);
      vector<mint> res(sz);
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) res[i + j] += a[i] * b[j];
      return res;
    }
    int sz1 = 1;
    while (sz1 < sz) sz1 <<= 1;
    vector<mint> res(sz1);
    for (int i = 0; i < n; i++) res[i] = a[i];
    ntt(res);
    if (a == b)
      for (int i = 0; i < sz1; i++) res[i] *= res[i];
    else {
      vector<mint> c(sz1);
      for (int i = 0; i < m; i++) c[i] = b[i];
      ntt(c);
      for (int i = 0; i < sz1; i++) res[i] *= c[i];
    }
    intt(res);
    res.resize(sz);
    return res;
  }
  void ntt_doubling(vector<mint> &a) {
    int n = (int)a.size();
    auto b = a;
    intt(b);
    mint r = 1, zeta = mint(g).pow((mint::get_mod() - 1) / (n << 1));
    for (int i = 0; i < n; i++) b[i] *= r, r *= zeta;
    ntt(b);
    copy(b.begin(), b.end(), back_inserter(a));
  }
};
