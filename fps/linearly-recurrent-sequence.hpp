#pragma
#include "fps/formal-power-series.hpp"
#include "fps/berlekamp-massey.hpp"
#include "fps/bostan-mori.hpp"
#include "fps/inverse-shift.hpp"

// a[i]=sum[j=1~d]c[j]a[i-j], i>=d
// find a[n]
template <class mint>
mint LinearyRecurrentSequence(FormalPowerSeries<mint> a, FormalPowerSeries<mint> c, long long n) {
  assert(a.size() == c.size());
  if (n < a.size()) return a[n];
  while (!c.empty() && c.back() == 0) c.pop_back();
  if (c.size() < a.size()) {
    int z = a.size() - c.size();
    n -= z;
    a.erase(a.begin(), a.begin() + z);
  }
  int d = c.size();
  FormalPowerSeries<mint> q(d + 1);
  q[0] = 1;
  for (int i = 0; i < d; i++) q[i + 1] = -c[i];
  auto p = (a * q).pre(d);
  return BostanMori(p, q, n);
}

// a[i]=sum[j=1~d]c[j]a[i-j], i>=d
// find a[n],a[n+1],...,a[n+k-1]
template <class mint>
FormalPowerSeries<mint> LinearyRecurrentSequence(FormalPowerSeries<mint> a, FormalPowerSeries<mint> c, long long n, int k) {
  assert(a.size() == c.size());
  if (n + k < a.size()) {
    a >>= (int)n;
    return a.pre(k);
  }
  while (!c.empty() && c.back() == 0) c.pop_back();
  int d = c.size();
  FormalPowerSeries<mint> ret{};
  if (c.size() < a.size()) {
    int z = a.size() - c.size();
    if (n < z) {
      ret.reserve(k);
      for (int i = n; i < z; i++) ret.push_back(a[i]);
    }
    n -= z;
    if (n < 0) {
      k += n;
      n = 0;
    }
    a >>= z;
  }
  FormalPowerSeries<mint> q(d + 1);
  q[0] = 1;
  for (int i = 0; i < d; i++) q[i + 1] = -c[i];
  auto p = (a * q).pre(d);
  if (n < a.size()) {
    p *= q.inv(n + k);
    p >>= n;
  } else {
    p *= (InverseShift(q, n) * q).pre(d);
    p %= q;
    p *= q.inv(k);
  }
  p.resize(k);
  if (ret.empty()) {
    return p;
  } else {
    for (auto v : p) ret.push_back(v);
    return ret;
  }
}

template <class mint>
mint LinearyRecurrentSequence(FormalPowerSeries<mint> a, long long n) {
  if (n < a.size()) return a[n];
  auto b = BerlekampMassey(a);
  int d = b.size() - 1;
  a.resize(d);
  int z = 0;
  while (b.back() == 0) b.pop_back(), z++;
  a >>= z;
  n -= z;
  d -= z;
  return BostanMori((a * b).pre(b.size()), b, n);
}

/**
 * @brief 線形漸化式用
 * @docs docs/fps/linearly-recurrent-sequence.md
 */