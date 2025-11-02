#pragma once
using uint = unsigned int;
using ll = long long int;
using ull = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;

template <class T, class S = T>
S SUM(const vector<T>& a) {
  return accumulate(ALL(a), S(0));
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
int popcnt(T x) {
  return __builtin_popcountll(x);
}
template <class T>
int topbit(T x) {
  return (x == 0 ? -1 : 63 - __builtin_clzll(x));
}
template <class T>
int lowbit(T x) {
  return (x == 0 ? -1 : __builtin_ctzll(x));
}