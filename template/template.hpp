#pragma once
#include <bits/stdc++.h>
using namespace std;

struct Fast {
  Fast() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
  }
} fast;

#define rep(i, a, b) for (int i = (a); i < (int)(b); i++)
#define rrep(i, a, b) for (int i = (int)(b) - 1; i >= (a); i--)
#define ALL(v) (v).begin(), (v).end()
#define UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)), (v).end())
#define SZ(v) (int)v.size()
#define MIN(v) *min_element(ALL(v))
#define MAX(v) *max_element(ALL(v))
#define LB(v, x) int(lower_bound(ALL(v), (x)) - (v).begin())
#define UB(v, x) int(upper_bound(ALL(v), (x)) - (v).begin())
#define YN(b) cout << ((b) ? "YES" : "NO") << "\n";
#define Yn(b) cout << ((b) ? "Yes" : "No") << "\n";
#define yn(b) cout << ((b) ? "yes" : "no") << "\n";

using uint = unsigned int;
using ll = long long int;
using ull = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;

template <class T, class S = T>
S SUM(const vector<T> &a) {
  return accumulate(ALL(a), S(0));
}
template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
T floor(T a, T b) {
  assert(b != 0);
  if (b < 0) a = -a, b = -b;
  return a >= 0 ? a / b : (a + 1) / b - 1;
}
template <class T>
T ceil(T a, T b) {
  assert(b != 0);
  if (b < 0) a = -a, b = -b;
  return a > 0 ? (a - 1) / b + 1 : a / b;
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

template <class T1, class T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
  return is >> p.first >> p.second;
}
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  return os << p.first << " " << p.second;
}
template <class T>
istream &operator>>(istream &is, vector<T> &a) {
  for (auto &v : a) is >> v;
  return is;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
  for (auto it = a.begin(); it != a.end();) {
    os << *it;
    if (++it != a.end()) os << " ";
  }
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &st) {
  os << "{";
  for (auto it = st.begin(); it != st.end();) {
    os << *it;
    if (++it != st.end()) os << ",";
  }
  os << "}";
  return os;
}
template <class T1, class T2>
ostream &operator<<(ostream &os, const map<T1, T2> &mp) {
  os << "{";
  for (auto it = mp.begin(); it != mp.end();) {
    os << it->first << ":" << it->second;
    if (++it != mp.end()) os << ",";
  }
  os << "}";
  return os;
}
#ifdef LOCAL
#define debug 1
#define show(...) _show(0, #__VA_ARGS__, __VA_ARGS__)
#else
#define debug 0
#define show(...) true
#endif
template <class T>
void _show(int i, T name) {
  cerr << '\n';
}
template <class T1, class T2, class... T3>
void _show(int i, const T1 &a, const T2 &b, const T3 &...c) {
  for (; a[i] != ',' && a[i] != '\0'; i++) cerr << a[i];
  cerr << ":" << b << " ";
  _show(i + 1, a, c...);
}