#pragma once

template <uint64_t m>
struct ModInt64 {
  static_assert(m >= 1);
  using mint = ModInt64;
  using u64 = uint64_t;
  using u128 = __uint128_t;
  using i128 = __int128_t;

 public:
  static constexpr u64 get_mod() { return m; }
  static mint raw(u64 v) {
    mint x;
    x._v = v;
    return x;
  }

  ModInt64() : _v(0) {}
  template <class T, enable_if_t<is_integral_v<T> && is_signed_v<T>, int> = 0>
  ModInt64(T v) {
    if (v >= 0) {
      _v = u128(v) % m;
    } else {
      using U = make_unsigned_t<T>;
      U x = U(-(v + 1)) + 1;
      u64 r = u128(x) % m;
      _v = r == 0 ? 0 : m - r;
    }
  }
  template <class T, enable_if_t<is_integral_v<T> && is_unsigned_v<T>, int> = 0>
  ModInt64(T v) : _v(u128(v) % m) {}
  u64 val() const { return _v; }
  mint& operator++() {
    _v++;
    if (_v == m) _v = 0;
    return *this;
  }
  mint& operator--() {
    if (_v == 0) _v = m;
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
    u64 x = _v + rhs._v;
    if (x < _v || x >= m) x -= m;
    _v = x;
    return *this;
  }
  mint& operator-=(const mint& rhs) {
    _v = _v >= rhs._v ? _v - rhs._v : m - (rhs._v - _v);
    return *this;
  }
  mint& operator*=(const mint& rhs) {
    _v = u128(_v) * rhs._v % m;
    return *this;
  }
  mint& operator/=(const mint& rhs) { return *this *= rhs.inv(); }
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
    u64 a = m, b = _v;
    i128 x0 = 0, x1 = 1;
    while (b) {
      u64 q = a / b;
      u64 r = a - q * b;
      a = b;
      b = r;
      i128 x = x0 - i128(q) * x1;
      x0 = x1;
      x1 = x;
    }
    if (x0 < 0) x0 += m / a;
    return raw(u64(x0));
  }
  friend mint operator+(const mint& lhs, const mint& rhs) { return mint(lhs) += rhs; }
  friend mint operator-(const mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }
  friend mint operator*(const mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }
  friend mint operator/(const mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }
  friend bool operator==(const mint& lhs, const mint& rhs) { return lhs._v == rhs._v; }
  friend bool operator!=(const mint& lhs, const mint& rhs) { return lhs._v != rhs._v; }
  friend istream& operator>>(istream& is, mint& x) {
    string s;
    if (!(is >> s)) return is;
    bool neg = s[0] == '-';
    bool sign = neg || s[0] == '+';
    u64 v = 0;
    for (int i = sign; i < int(s.size()); i++) v = (u128(v) * 10 + (s[i] - '0')) % m;
    x = raw(neg && v ? m - v : v);
    return is;
  }
  friend ostream& operator<<(ostream& os, const mint& x) { return os << x.val(); }

 private:
  u64 _v;
};
