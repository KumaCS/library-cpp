#pragma once
#include "math/util.hpp"

template <class T>
struct GarnerOnline {
  vector<T> ms, y;
  GarnerOnline() { init(); }
  void init() { ms.clear(), y.clear(); }
  void push(T r, T m) {
    T x = 0, p = 1;
    for (int j = 0; j < ms.size(); j++) {
      x = (x + y[j] * p) % m;
      p = p * ms[j] % m;
    }
    ms.push_back(m);
    y.push_back((r - x + m) * Math::inv_mod(p, m) % m);
  }
  template <class mint>
  void push(mint x) { push(mint::get_mod(), x.val()); }
  void pop() {
    assert(!ms.empty());
    ms.pop_back(), y.pop_back();
  }
  T get() {
    T res = 0;
    for (int i = (int)ms.size() - 1; i >= 0; i--) res = res * ms[i] + y[i];
    return res;
  }
  T get(T mod) {
    T res = 0;
    for (int i = (int)ms.size() - 1; i >= 0; i--) res = (res * ms[i] + y[i]) % mod;
    return res;
  }
};

/**
 * @brief Garner のアルゴリズム (オンライン)
 * @docs docs/math/garner.md
 */