#pragma once

// 区間に値を対応づける
// range set point get + enumerate
template <class T>
struct RangeArray {
 private:
  int n;
  set<int> s;
  vector<T> data;
  T e;

 public:
  RangeArray(int size, T e) : n(size), e(e) {
    s.insert(0);
    s.insert(n);
    data = vector<T>(n, e);
  }
  T get(int x) {
    auto it = s.lower_bound(x + 1);
    it--;
    return data[*it];
  }
  vector<pair<int, int>> enumerate_intersect(int l, int r) {
    vector<pair<int, int>> ret;
    auto it = s.lower_bound(l + 1);
    it--;
    while (it != s.end()) {
      int l1 = *it;
      if (r <= l1) break;
      it++;
      int r1 = *it;
      ret.push_back({l1, r1});
    }
    return ret;
  }
  void set(int l, int r, T v) {
    for (auto it = s.lower_bound(l); it != s.end();) {
      int l1 = *it;
      if (r <= l1) break;
      it++;
      int r1 = *it;
      it--;
      it = s.erase(it);
      if (r < r1) {
        s.insert(r);
        data[r] = data[l1];
        break;
      }
    }
    s.insert(l);
    data[l] = v;
  }
};
