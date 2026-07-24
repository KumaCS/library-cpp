#pragma once

// mod (2^127-1)
struct ModIntM127 {
  using mint = ModIntM127;
  using u64 = unsigned long long;
  using u128 = __uint128_t;
  static constexpr int B = 127;
  static constexpr u128 M = (u128(1) << B) - 1;
  static constexpr int H = 64;
  static constexpr u128 MASK_LOW = (u128(1) << H) - 1;
  static constexpr u128 MASK_HIGH = (u128(1) << (B - H)) - 1;

 public:
  static constexpr u128 get_mod() { return M; }
  static mint raw(int v) {
    mint x;
    x._v = v;
    return x;
  }

  ModIntM127() : _v(0) {}
  ModIntM127(int v) : _v(v < 0 ? M + v : v) {}
  ModIntM127(long long v) : _v(v < 0 ? M + v : v) {}
  ModIntM127(unsigned long long v) : _v(v) {}
  ModIntM127(u128 v) : _v(calc_mod(v)) {}
  u128 val() const { return _v; }
  mint& operator++() {
    _v++;
    if (_v == M) _v = 0;
    return *this;
  }
  mint& operator--() {
    if (_v == 0) _v = M;
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
    if (_v >= M) _v -= M;
    return *this;
  }
  mint& operator-=(const mint& rhs) {
    _v -= rhs._v;
    if (_v >= M) _v += M;
    return *this;
  }
  mint& operator*=(const mint& rhs) {
    u128 lo1 = _v & MASK_LOW, hi1 = _v >> H;
    u128 lo2 = rhs._v & MASK_LOW, hi2 = rhs._v >> H;
    _v = hi1 * hi2;
    _v = ((_v & MASK_HIGH) << H) + (_v >> (B - H));
    _v += calc_mod(lo1 * hi2 + hi1 * lo2);
    _v = ((_v & MASK_HIGH) << H) + (_v >> (B - H));
    _v += calc_mod(lo1 * lo2);
    _v = calc_mod(_v);
    return *this;
  }
  mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }
  mint operator+() const { return *this; }
  mint operator-() const { return mint() - *this; }
  mint pow(u128 n) const {
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
    return pow(M - 2);
  }
  friend mint operator+(const mint& lhs, const mint& rhs) { return mint(lhs) += rhs; }
  friend mint operator-(const mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }
  friend mint operator*(const mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }
  friend mint operator/(const mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }
  friend bool operator==(const mint& lhs, const mint& rhs) { return lhs._v == rhs._v; }
  friend bool operator!=(const mint& lhs, const mint& rhs) { return lhs._v != rhs._v; }

 private:
  u128 _v;
  u128 calc_mod(u128 v) {
    u128 x = (v & M) + (v >> B);
    if (x >= M) x -= M;
    return x;
  }
};
