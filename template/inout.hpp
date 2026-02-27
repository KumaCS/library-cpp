#pragma once
struct Fast {
  Fast() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
  }
} fast;

ostream& operator<<(ostream& os, __uint128_t x) {
  char buf[40];
  size_t k = 0;
  while (x > 0) buf[k++] = (char)(x % 10 + '0'), x /= 10;
  if (k == 0) buf[k++] = '0';
  while (k) os << buf[--k];
  return os;
}
ostream& operator<<(ostream& os, __int128_t x) {
  return x < 0 ? (os << '-' << (__uint128_t)(-x)) : (os << (__uint128_t)x);
}
template <class T1, class T2>
istream& operator>>(istream& is, pair<T1, T2>& p) {
  return is >> p.first >> p.second;
}
template <class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
  return os << p.first << " " << p.second;
}
template <class T>
istream& operator>>(istream& is, vector<T>& a) {
  for (auto& v : a) is >> v;
  return is;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& a) {
  for (auto it = a.begin(); it != a.end();) {
    os << *it;
    if (++it != a.end()) os << " ";
  }
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const set<T>& st) {
  os << "{";
  for (auto it = st.begin(); it != st.end();) {
    os << *it;
    if (++it != st.end()) os << ",";
  }
  os << "}";
  return os;
}
template <class T1, class T2>
ostream& operator<<(ostream& os, const map<T1, T2>& mp) {
  os << "{";
  for (auto it = mp.begin(); it != mp.end();) {
    os << it->first << ":" << it->second;
    if (++it != mp.end()) os << ",";
  }
  os << "}";
  return os;
}

void in() {}
template <typename T, class... U>
void in(T& t, U&... u) {
  cin >> t;
  in(u...);
}
void out() { cout << "\n"; }
template <typename T, class... U, char sep = ' '>
void out(const T& t, const U&... u) {
  cout << t;
  if (sizeof...(u)) cout << sep;
  out(u...);
}

namespace IO {
namespace Graph {
vector<vector<int>> unweighted(int n, int m, bool directed = false, int offset = 1) {
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u -= offset, v -= offset;
    g[u].push_back(v);
    if (!directed) g[v].push_back(u);
  }
  return g;
}
template <class T>
vector<vector<pair<int, T>>> weighted(int n, int m, bool directed = false, int offset = 1) {
  vector<vector<pair<int, T>>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    T w;
    cin >> u >> v >> w;
    u -= offset, v -= offset;
    g[u].push_back({v, w});
    if (!directed) g[v].push_back({u, w});
  }
  return g;
}
}  // namespace Graph
namespace Tree {
vector<vector<int>> unweighted(int n, bool directed = false, int offset = 1) {
  return Graph::unweighted(n, n - 1, directed, offset);
}
template <class T>
vector<vector<pair<int, T>>> weighted(int n, bool directed = false, int offset = 1) {
  return Graph::weighted<T>(n, n - 1, directed, offset);
}
vector<vector<int>> rooted(int n, bool to_root = true, bool to_leaf = true, int offset = 1) {
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    p -= offset;
    if (to_root) g[i].push_back(p);
    if (to_leaf) g[p].push_back(i);
  }
  return g;
}
}  // namespace Tree
}  // namespace IO