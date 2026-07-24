#pragma once

#include "string/rolling-hash-value.hpp"

struct RollingHash : RollingHashBase {
  vector<RollingHashValue> prefix;
  RollingHash() : prefix(1) {}
  template <class T>
  RollingHash(const vector<T>& a) : RollingHash() {
    for (auto v : a) push(v);
  }
  RollingHash(const string& s) : RollingHash() {
    for (auto c : s) push(c);
  }
  template <class T>
  void push(T v) { prefix.push_back(prefix.back() + RollingHashValue::single(v)); }
  int size() const { return prefix.size() - 1; }
  RollingHashValue slice(int l, int r) const {
    assert(0 <= l && l <= r && r <= size());
    u64 power = prefix[r - l].power;
    return RollingHashValue(sub(prefix[r].hash, mul(prefix[l].hash, power)), power);
  }
};
