#pragma once
#include "math/util.hpp"
#include "math/barrett.hpp"

template <int id>
struct DynamicModInt {
  using mint = DynamicModInt;
  static void set_mod(int m) {
    assert(1 <= m);
    bar = barrett(m);
  }
  static constexpr unsigned int get_mod() { return (int)bar.umod(); }
  static mint raw(int v) {
    mint x;
    x._v = v;
    return x;
  }
  DynamicModInt() : _v(0) {}
  DynamicModInt(int64_t v) {
    long long x = (long long)(v % (long long)(bar.umod()));
    if (x < 0) x += umod();
    _v = (unsigned int)(x);
  }
  unsigned int val() const { return _v; }
  mint& operator++() {
    _v++;
    if (_v == umod()) _v = 0;
    return *this;
  }
  mint& operator--() {
    if (_v == 0) _v = umod();
    _v--;
    return *this;
  }
  mint operator++(int) {
    mint result = *this;
    ++*this;
    return result;
  }
  mint operator--(int) {
    mint result = *this;
    --*this;
    return result;
  }
  mint& operator+=(const mint& rhs) {
    _v += rhs._v;
    if (_v >= umod()) _v -= umod();
    return *this;
  }
  mint& operator-=(const mint& rhs) {
    _v -= rhs._v;
    if (_v >= umod()) _v += umod();
    return *this;
  }
  mint& operator*=(const mint& rhs) {
    _v = bar.mul(_v, rhs._v);
    return *this;
  }
  mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }
  mint operator+() const { return *this; }
  mint operator-() const { return mint() - *this; }
  mint pow(long long n) const {
    assert(0 <= n);
    mint x = *this, r = 1;
    while (n) {
      if (n & 1) r *= x;
      x *= x;
      n >>= 1;
    }
    return r;
  }
  mint inv() const {
    auto inv = Math::inv_mod(_v, umod());
    return raw(inv);
  }
  friend mint operator+(const mint& lhs, const mint& rhs) { return mint(lhs) += rhs; }
  friend mint operator-(const mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }
  friend mint operator*(const mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }
  friend mint operator/(const mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }
  friend bool operator==(const mint& lhs, const mint& rhs) { return lhs._v == rhs._v; }
  friend bool operator!=(const mint& lhs, const mint& rhs) { return lhs._v != rhs._v; }
  friend istream& operator>>(istream& is, mint& x) { return is >> x._v; }
  friend ostream& operator<<(ostream& os, const mint& x) { return os << x.val(); }

 private:
  unsigned int _v;
  static constexpr unsigned int umod() { return bar.umod(); }
  static barrett bar;
};
template <int id>
barrett DynamicModInt<id>::bar(998244353);