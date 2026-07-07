#pragma once

template <class T>
struct RangeAddRangeMin {
  RangeAddRangeMin() : RangeAddRangeMin(0) {}
  explicit RangeAddRangeMin(int n) : RangeAddRangeMin(vector<T>(n, T(0))) {}
  explicit RangeAddRangeMin(const vector<T>& a) : N(a.size()), root_min(T(0)), diff(max(0, N - 1), T(0)) {
    if (N > 0) root_min = build(0, 0, N, a);
  }
  void add(int l, int r, T x) {
    if (l >= r) return;
    assert(0 <= l && l <= r && r <= N);
    root_min += add(0, 0, N, l, r, x);
  }
  T min(int l, int r) const {
    assert(0 <= l && l <= r && r <= N);
    assert(l < r);
    return min(0, 0, N, l, r, root_min);
  }
  T prod(int l, int r) const { return min(l, r); }
  T get(int p) const {
    assert(0 <= p && p < N);
    return min(p, p + 1);
  }
  T all_min() const {
    assert(N > 0);
    return root_min;
  }
  T all_prod() const { return all_min(); }
  int size() const { return N; }

 private:
  int N;
  T root_min;
  vector<T> diff;
  static int internal_count(int len) { return max(0, len - 1); }
  static int right_child(int id, int l, int m) { return id + 1 + internal_count(m - l); }
  T build(int id, int l, int r, const vector<T>& a) {
    if (r - l == 1) return a[l];
    int m = (l + r) / 2;
    T ml = build(id + 1, l, m, a);
    T mr = build(right_child(id, l, m), m, r, a);
    diff[id] = ml - mr;
    return std::min(ml, mr);
  }
  T add(int id, int l, int r, int ql, int qr, T x) {
    if (qr <= l || r <= ql) return T(0);
    if (ql <= l && r <= qr) return x;
    int m = (l + r) / 2;
    int rid = right_child(id, l, m);
    T dl = add(id + 1, l, m, ql, qr, x);
    T dr = add(rid, m, r, ql, qr, x);
    T d = diff[id];
    T ret = d <= T(0) ? std::min(dl, -d + dr) : std::min(d + dl, dr);
    diff[id] = d + dl - dr;
    return ret;
  }
  T min(int id, int l, int r, int ql, int qr, T cur_min) const {
    if (qr <= l || r <= ql) return numeric_limits<T>::max();
    if (ql <= l && r <= qr) return cur_min;
    int m = (l + r) / 2;
    T d = diff[id];
    T left_min = cur_min + max(d, T(0));
    T right_min = cur_min + max(-d, T(0));
    return std::min(min(id + 1, l, m, ql, qr, left_min), min(right_child(id, l, m), m, r, ql, qr, right_min));
  }
};

/**
 * @brief Range Add Range Min
 * @docs docs/data-structure/range-add-range-min.md
 */
