#pragma once

// T[x]/(x^s-r)
template <class T, int s, auto r>
struct RootExtension {
  using F = RootExtension;
  array<T, s> a;
  RootExtension() { a.fill(T{}); }
  RootExtension(const T& x) {
    a.fill(T{});
    a[0] = x;
  }
  T& operator[](int k) { return a[k]; }
  F& operator+=(const F& o) {
    for (int i = 0; i < s; i++) a[i] += o.a[i];
    return *this;
  }
  F& operator-=(const F& o) {
    for (int i = 0; i < s; i++) a[i] -= o.a[i];
    return *this;
  }
  F& operator*=(const F& o) {
    const T _r = T{r};
    array<T, s> b{};
    for (int i = 0; i < s; i++) {
      for (int j = 0; j < s - i; j++) b[i + j] += a[i] * o.a[j];
      for (int j = s - i; j < s; j++) b[i + j - s] += _r * a[i] * o.a[j];
    }
    swap(a, b);
    return *this;
  }
  F operator+(const F& o) const { return F(*this) += o; }
  F operator-(const F& o) const { return F(*this) -= o; }
  F operator*(const F& o) const { return F(*this) *= o; }
  F operator-() const {
    F ret(*this);
    for (auto& v : ret.a) v = -v;
    return ret;
  }
  F pow(long long n) const {
    F ret = T{1}, x = *this;
    while (n) {
      if (n & 1) ret *= x;
      x *= x;
      n >>= 1;
    }
    return ret;
  }
  T test() const { return T{r}; }
};
