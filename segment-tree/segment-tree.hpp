#pragma once

template <class T, T (*op)(T, T), T (*e)()>
struct SegmentTree {
 private:
  int n;
  vector<T> d;
  void update(int p) { d[p] = op(d[2 * p], d[2 * p + 1]); }

 public:
  SegmentTree() : SegmentTree(0) {}
  explicit SegmentTree(int sz) : SegmentTree(vector<T>(sz, e())) {}
  explicit SegmentTree(const vector<T>& v) : n(v.size()) {
    d.assign(2 * n, e());
    for (int i = 0; i < v.size(); i++) d[n + i] = v[i];
    for (int i = n - 1; i > 0; i--) update(i);
  }
  void clear() { fill(d.begin(), d.end(), e()); }

  void set_without_update(int p, T v) { d[n + p] = v; }
  void all_update() {
    for (int i = n - 1; i > 0; i--) update(i);
  }
  T get(int p) {
    assert(0 <= p && p <= n);
    return d[p + n];
  }
  void set(int p, T v) {
    assert(0 <= p && p <= n);
    d[p += n] = v;
    for (p >>= 1; p > 0; p >>= 1) update(p);
  }
  void apply(int p, T v) {
    assert(0 <= p && p <= n);
    p += n;
    d[p] = op(d[p], v);
    for (p >>= 1; p > 0; p >>= 1) update(p);
  }
  T prod(int l, int r) {
    if (l >= r) return e();
    assert(0 <= l && l <= r && r <= n);
    T sl = e(), sr = e();
    l += n, r += n;
    while (l < r) {
      if ((l & 1) != 0) sl = op(sl, d[l++]);
      if ((r & 1) != 0) sr = op(d[--r], sr);
      l >>= 1, r >>= 1;
    }
    return op(sl, sr);
  }
  T all_prod() { return prod(0, n); }

  template <bool (*f)(T)>
  int max_right(int l) const {
    return max_right(l, [](T x) { return f(x); });
  }
  template <class F>
  int max_right(int l, F f) const {
    assert(0 <= l && l <= n);
    assert(f(e()));
    if (l == n) return n;
    int x = n + l, w = 1;
    T s = e();
    for (; l + w <= n; x >>= 1, w <<= 1)
      if (x & 1) {
        if (!f(op(s, d[x]))) break;
        s = op(s, d[x++]);
        l += w;
      }
    while (x <<= 1, w >>= 1) {
      if (l + w <= n && f(op(s, d[x]))) {
        s = op(s, d[l++]);
        l += w;
      }
    }
    return l;
  }

  template <bool (*f)(T)>
  int min_left(int r) const {
    return min_left(r, [](T x) { return f(x); });
  }
  template <class F>
  int min_left(int r, F f) const {
    assert(0 <= r && r <= n);
    assert(f(e()));
    if (r == 0) return 0;
    int x = n + r, w = 1;
    T s = e();
    for (; r - w >= 0; x >>= 1, w <<= 1)
      if (x & 1) {
        if (!f(op(d[x - 1], s))) break;
        s = op(d[--x], s);
        r -= w;
      }
    while (x <<= 1, w >>= 1) {
      if (r - w >= 0 && f(op(d[x - 1], s))) {
        s = op(d[--x], s);
        r -= w;
      }
    }
    return r;
  }
};

/**
 * @brief Segment Tree
 * @docs docs/segment-tree/segment-tree.md
 */