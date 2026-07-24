#pragma once

struct RollingHashBase {
  using u128 = __uint128_t;
  using i128 = __int128_t;
  using u64 = uint64_t;
  static constexpr u64 MOD = (1ull << 61) - 1;
  static u64 base;
  static u64 add(u64 x, u64 y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
  }
  static u64 sub(u64 x, u64 y) {
    if ((x -= y) >= MOD) x += MOD;
    return x;
  }
  static u64 mul(u64 x, u64 y) {
    u128 z = (u128)x * y;
    u64 v = (u64(z) & MOD) + u64(z >> 61);
    return v >= MOD ? v - MOD : v;
  }
  static u64 normalize(u64 v) {
    u64 x = (v & MOD) + (v >> 61);
    return x >= MOD ? x - MOD : x;
  }
  template <class T>
  static u64 normalize(T v) {
    static_assert(is_integral_v<T> && sizeof(T) <= sizeof(u64));
    if constexpr (is_signed_v<T>) {
      if (v < 0) {
        u64 x = normalize(u64(-i128(v)));
        return x == 0 ? 0 : MOD - x;
      }
    }
    return normalize(u64(v));
  }
  template <class T>
  static T restore(u64 v) {
    static_assert(is_integral_v<T> && sizeof(T) <= sizeof(u64));
    assert(v < MOD);
    if constexpr (is_signed_v<T>) {
      if (v <= u64(numeric_limits<T>::max())) return T(v);
      u64 x = MOD - v;
      assert(i128(x) <= -i128(numeric_limits<T>::min()));
      return T(-i128(x));
    } else {
      assert(v <= u64(numeric_limits<T>::max()));
      return T(v);
    }
  }
};
inline RollingHashBase::u64 RollingHashBase::base = []() {
  random_device seed_gen;
  mt19937_64 rnd(seed_gen());
  return uniform_int_distribution<u64>(256, MOD - 2)(rnd);
}();
