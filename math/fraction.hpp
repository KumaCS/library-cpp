#pragma once

template <class T>
struct Fraction {
  T a, b;
  Fraction() : a(0), b(1) {}
  Fraction(T _a) : a(_a), b(1) {}
  Fraction(T _a, T _b) { init(_a, _b); }
  T floor() const { return a >= 0 ? a / b : (a + 1) / b - 1; }
  T ceil() const { return a > 0 ? (a - 1) / b + 1 : a / b; }
  template <class V>
  V get() const { return V(a) / b; }
  using frac = Fraction;
  static frac raw(T _a, T _b) { a = _a, b = _b; }
  frac &init(T _a, T _b) {
    T g = gcd(_a, _b);
    a = _a / g, b = _b / g;
    if (b < 0) a = -a, b = -b;
    return *this;
  }
  frac inv() const { return a >= 0 ? raw(b, a) : raw(-b, -a); }
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
 * @brief 有理数
 */