#pragma once
struct Fast {
  Fast() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
  }
} fast;

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