#pragma once

namespace PowerTowerModIntInternal {
constexpr uint32_t totient(uint32_t n) {
  uint32_t res = n;
  for (uint32_t p = 2; p <= n / p; p++)
    if (n % p == 0) {
      res = res / p * (p - 1);
      do n /= p;
      while (n % p == 0);
    }
  if (n > 1) res = res / n * (n - 1);
  return res;
}
}  // namespace PowerTowerModIntInternal

template <uint32_t m>
struct PowerTowerModInt {
  static_assert(1 <= m && m < 0x80000000u);
  using mint = PowerTowerModInt;

 private:
  static constexpr uint32_t phi = PowerTowerModIntInternal::totient(m);
  using lower_mint = PowerTowerModInt<phi>;

 public:
  static constexpr uint32_t get_mod() { return m; }
  PowerTowerModInt() : _v(0), _lower(0) {}
  PowerTowerModInt(uint64_t v) : _v(normalize(v)), _lower(v) {}
  uint32_t val() const { return _v < m ? _v : _v - m; }
  uint32_t large_val() const { return _v; }
  mint& operator+=(const mint& rhs) {
    _v = normalize(uint64_t(_v) + rhs._v);
    _lower += rhs._lower;
    return *this;
  }
  mint& operator*=(const mint& rhs) {
    _v = normalize(uint64_t(_v) * rhs._v);
    _lower *= rhs._lower;
    return *this;
  }
  mint& unsafe_subtract(const mint& rhs) {
    if (_v < m) {
      assert(rhs._v < m && rhs._v <= _v);
      return *this = mint(_v - rhs._v);
    }
    _v = m + uint32_t((uint64_t(val()) + m - rhs.val()) % m);
    _lower.unsafe_subtract(rhs._lower);
    return *this;
  }
  mint& unsafe_subtract(int64_t rhs) {
    assert(rhs >= 0);
    if (_v < m) {
      assert(uint64_t(rhs) <= _v);
      return *this = mint(_v - uint64_t(rhs));
    }
    return unsafe_subtract(mint(uint64_t(rhs)));
  }
  mint pow(const mint& exponent) const {
    return raw(pow_mod(_v, exponent._lower._v), _lower.pow(exponent._lower));
  }
  friend mint operator+(const mint& lhs, const mint& rhs) { return mint(lhs) += rhs; }
  friend mint operator*(const mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }
  friend bool operator==(const mint& lhs, const mint& rhs) { return lhs.val() == rhs.val(); }
  friend bool operator!=(const mint& lhs, const mint& rhs) { return !(lhs == rhs); }
  friend ostream& operator<<(ostream& os, const mint& x) { return os << x.val(); }

 private:
  uint32_t _v;
  lower_mint _lower;
  template <uint32_t>
  friend struct PowerTowerModInt;
  static uint32_t normalize(uint64_t v) {
    if (v < uint64_t(m) * 2) return uint32_t(v);
    return uint32_t(v % m) + m;
  }
  static uint32_t pow_mod(uint32_t a, uint32_t n) {
    uint32_t res = 1;
    while (n) {
      if (n & 1) res = normalize(uint64_t(res) * a);
      a = normalize(uint64_t(a) * a);
      n >>= 1;
    }
    return res;
  }
  static mint raw(uint32_t v, const lower_mint& lower) {
    mint res;
    res._v = v;
    res._lower = lower;
    return res;
  }
};

template <>
struct PowerTowerModInt<1> {
  using mint = PowerTowerModInt;

  static constexpr uint32_t get_mod() { return 1; }
  PowerTowerModInt() : _v(false) {}
  PowerTowerModInt(uint64_t v) : _v(v != 0) {}
  uint32_t val() const { return 0; }
  uint32_t large_val() const { return _v; }
  mint& operator+=(const mint& rhs) {
    _v = _v || rhs._v;
    return *this;
  }
  mint& operator*=(const mint& rhs) {
    _v = _v && rhs._v;
    return *this;
  }
  mint& unsafe_subtract(const mint& rhs) {
    if (!_v) assert(!rhs._v);
    return *this;
  }
  mint& unsafe_subtract(int64_t rhs) {
    assert(rhs >= 0);
    if (!_v) {
      assert(rhs == 0);
      return *this;
    }
    return unsafe_subtract(mint(uint64_t(rhs)));
  }
  mint pow(const mint& exponent) const { return raw(_v || !exponent._v); }
  friend mint operator+(const mint& lhs, const mint& rhs) { return mint(lhs) += rhs; }
  friend mint operator*(const mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }
  friend bool operator==(const mint&, const mint&) { return true; }
  friend bool operator!=(const mint&, const mint&) { return false; }
  friend ostream& operator<<(ostream& os, const mint&) { return os << 0; }

 private:
  bool _v;
  template <uint32_t>
  friend struct PowerTowerModInt;
  static mint raw(bool positive) {
    mint res;
    res._v = positive;
    return res;
  }
};

/**
 * @brief Power Tower Modint
 * @docs docs/modint/power-tower-modint.md
 */
