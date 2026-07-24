#pragma once

#include "string/rolling-hash-value.hpp"

struct RollingHashMonoid {
  using value_type = RollingHashValue;
  static value_type op(value_type x, value_type y) { return x + y; }
  static value_type e() { return value_type(); }
  template <class T>
  static value_type single(T v) {
    return value_type::single(v);
  }
  template <class Sequence>
  static vector<value_type> init(const Sequence& a) {
    vector<value_type> v(a.size());
    for (int i = 0; i < (int)a.size(); i++) v[i] = single(a[i]);
    return v;
  }
};

struct RollingHashMonoidReversible {
  using value_type = RollingHashValueReversible;
  static value_type op(value_type x, value_type y) { return x + y; }
  static value_type e() { return value_type(); }
  template <class T>
  static value_type single(T v) {
    return value_type::single(v);
  }
  template <class Sequence>
  static vector<value_type> init(const Sequence& a) {
    vector<value_type> v(a.size());
    for (int i = 0; i < (int)a.size(); i++) v[i] = single(a[i]);
    return v;
  }
};
