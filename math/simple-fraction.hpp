#pragma once

template <class T>
struct SimpleFraction {
  T a, b;
  SimpleFraction() : a(0), b(1) {}
  SimpleFraction(T _a) : a(_a), b(1) {}
  SimpleFraction(T _a, T _b) { init(_a, _b); }
  template <class V>
  V get() const { return V(a) / b; }
  using frac = SimpleFraction;
  frac &init(T _a, T _b) {
    a = _a, b = _b;
    if (b < 0) a = -a, b = -b;
    if (a == 0) b = 1;
    return *this;
  }
  frac operator-() const { return frac(-a, b); }
  frac &operator+=(const frac &x) { return init(a * x.b + x.a * b, b * x.b); }
  frac &operator-=(const frac &x) { return init(a * x.b - x.a * b, b * x.b); }
  frac &operator*=(const frac &x) { return init(a * x.a, b * x.b); }
  frac &operator/=(const frac &x) { return init(a * x.b, b * x.a); }
  frac operator+(const frac &x) const { return frac(*this) += x; }
  frac operator-(const frac &x) const { return frac(*this) -= x; }
  frac operator*(const frac &x) const { return frac(*this) *= x; }
  frac operator/(const frac &x) const { return frac(*this) /= x; }
  bool operator<(const frac &x) const { return a * x.b < b * x.a; }
  bool operator>(const frac &x) const { return a * x.b > b * x.a; }
  bool operator<=(const frac &x) const { return a * x.b <= b * x.a; }
  bool operator>=(const frac &x) const { return a * x.b >= b * x.a; }
  bool operator==(const frac &x) const { return a * x.b == b * x.a; }
  bool operator!=(const frac &x) const { return a * x.b != b * x.a; }
  friend istream &operator>>(istream &is, frac &x) { return is >> x.a >> x.b; }
  friend ostream &operator<<(ostream &os, const frac &x) { return os << x.a << '/' << x.b; }
};

/**
 * @brief 有理数 (約分なし)
 */