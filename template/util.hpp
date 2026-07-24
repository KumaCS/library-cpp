#pragma once
using uint = unsigned int;
using ll = long long int;
using ull = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;
template <class T>
using priority_queue_asc = priority_queue<T, vector<T>, greater<T>>;

template <class T, class S = T>
S SUM(const vector<T>& a) {
  return accumulate(ALL(a), S(0));
}
template <class T1, class T2>
inline bool chmin(T1& a, T2 b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T1, class T2>
inline bool chmax(T1& a, T2 b) {
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