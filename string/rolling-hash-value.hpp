#pragma once

#include "string/rolling-hash-base.hpp"

struct RollingHashValue : RollingHashBase {
  u64 hash, power;
  RollingHashValue() : hash(0), power(1) {}
  RollingHashValue(u64 h, u64 p) : hash(h), power(p) {}
  template <class T>
  static RollingHashValue single(T v) {
    return RollingHashValue(normalize(v), base);
  }
  RollingHashValue& operator+=(RollingHashValue rhs) {
    hash = add(mul(hash, rhs.power), rhs.hash);
    power = mul(power, rhs.power);
    return *this;
  }
  friend RollingHashValue operator+(RollingHashValue lhs, RollingHashValue rhs) {
    return lhs += rhs;
  }
  friend bool operator==(RollingHashValue lhs, RollingHashValue rhs) {
    return lhs.hash == rhs.hash && lhs.power == rhs.power;
  }
};

struct RollingHashValueReversible : RollingHashBase {
  u64 hash, reverse_hash, power;
  RollingHashValueReversible() : hash(0), reverse_hash(0), power(1) {}
  RollingHashValueReversible(u64 h, u64 rh, u64 p) : hash(h), reverse_hash(rh), power(p) {}
  template <class T>
  static RollingHashValueReversible single(T v) {
    u64 h = normalize(v);
    return RollingHashValueReversible(h, h, base);
  }
  RollingHashValueReversible& operator+=(RollingHashValueReversible rhs) {
    hash = add(mul(hash, rhs.power), rhs.hash);
    reverse_hash = add(reverse_hash, mul(rhs.reverse_hash, power));
    power = mul(power, rhs.power);
    return *this;
  }
  RollingHashValueReversible reversed() const {
    return RollingHashValueReversible(reverse_hash, hash, power);
  }
  friend RollingHashValueReversible operator+(RollingHashValueReversible lhs,
                                              RollingHashValueReversible rhs) {
    return lhs += rhs;
  }
  friend bool operator==(RollingHashValueReversible lhs, RollingHashValueReversible rhs) {
    return lhs.hash == rhs.hash && lhs.reverse_hash == rhs.reverse_hash &&
           lhs.power == rhs.power;
  }
};
