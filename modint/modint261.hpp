#pragma once

// mod (2^61-1)
struct ModInt261 {
  using mint = ModInt261;
  using ll = long long;
  using ull = unsigned long long;
  static constexpr int b = 61;
  static constexpr ull m = (1ull << b) - 1;

 public:
  static constexpr ull get_mod() { return m; }
  static mint raw(int v) {
    mint x;
    x._v = v;
    return x;
  }

  ModInt261() : _v(0) {}
  ModInt261(int v) : _v(v < 0 ? m + v : v) {}
  ModInt261(ll v) : _v(calc_mod(ull(v < 0 ? m + v : v))) {}
  ModInt261(ull v) : _v(calc_mod(v)) {}
  ull val() const { return _v; }
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
    _v += rhs._v;
    if (_v >= m) _v -= m;
    return *this;
  }
  mint& operator-=(const mint& rhs) {
    _v -= rhs._v;
    if (_v >= m) _v += m;
    return *this;
  }
  mint& operator*=(const mint& rhs) {
    __uint128_t z = _v;
    z *= rhs._v;
    _v = ull(z % m);
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
    assert(_v);
    return pow(m - 2);
  }
  friend mint operator+(const mint& lhs, const mint& rhs) { return mint(lhs) += rhs; }
  friend mint operator-(const mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }
  friend mint operator*(const mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }
  friend mint operator/(const mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }
  friend bool operator==(const mint& lhs, const mint& rhs) { return lhs._v == rhs._v; }
  friend bool operator!=(const mint& lhs, const mint& rhs) { return lhs._v != rhs._v; }
  friend istream& operator>>(istream& is, mint& x) {
    ll v;
    is >> v;
    x = mint(v);
    return is;
  }
  friend ostream& operator<<(ostream& os, const mint& x) { return os << x.val(); }

 private:
  ull _v;
  ull calc_mod(ull v) {
    ull x = (v & m) + (v >> b);
    if (x >= m) x -= m;
    return x;
  }
};