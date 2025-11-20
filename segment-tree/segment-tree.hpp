#pragma once

template <class T, T (*op)(T, T), T (*e)()>
struct SegmentTree {
 private:
  int _n, size, log;
  vector<T> d;
  void update(int p) { d[p] = op(d[2 * p], d[2 * p + 1]); }

 public:
  SegmentTree() : SegmentTree(0) {}
  explicit SegmentTree(int sz) : SegmentTree(vector<T>(sz, e())) {}
  explicit SegmentTree(const vector<T>& v) : _n(v.size()) {
    size = 1, log = 0;
    while (size < _n) size <<= 1, log++;
    d.assign(2 * size, e());
    for (int i = 0; i < v.size(); i++) d[size + i] = v[i];
    for (int i = size - 1; i > 0; i--) update(i);
  }
  void clear() { fill(d.begin(), d.end(), e()); }

  void set_without_update(int p, T v) { d[p + size] = v; }
  void all_update() {
    for (int i = size - 1; i > 0; i--) update(i);
  }
  T get(int p) {
    assert(0 <= p && p <= _n);
    return d[p + size];
  }
  void set(int p, T v) {
    assert(0 <= p && p <= _n);
    p += size;
    d[p] = v;
    for (int i = 1; i <= log; i++) update(p >> i);
  }
  void apply(int p, T v) {
    assert(0 <= p && p <= _n);
    p += size;
    d[p] = op(d[p], v);
    for (int i = 1; i <= log; i++) update(p >> i);
  }
  T all_prod() { return d[1]; }
  T prod(int l, int r) {
    if (l >= r) return e();
    assert(0 <= l && l <= r && r <= _n);
    T sl = e(), sr = e();
    l += size, r += size;
    while (l < r) {
      if ((l & 1) != 0) sl = op(sl, d[l++]);
      if ((r & 1) != 0) sr = op(d[--r], sr);
      l >>= 1, r >>= 1;
    }
    return op(sl, sr);
  }

  template <bool (*f)(T)>
  int max_right(int l) const {
    return max_right(l, [](T x) { return f(x); });
  }
  template <class F>
  int max_right(int l, F f) const {
    assert(0 <= l && l <= size);
    assert(f(e()));
    if (l == _n) return _n;
    l += size;
    T s = e();
    do {
      while (l % 2 == 0) l >>= 1;
      if (!f(op(s, d[l]))) {
        while (l < size) {
          l <<= 1;
          if (f(op(s, d[l]))) s = op(s, d[l++]);
        }
        return l - size;
      }
      s = op(s, d[l++]);
    } while ((l & -l) != l);
    return _n;
  }

  template <bool (*f)(T)>
  int min_left(int r) const {
    return min_left(r, [](T x) { return f(x); });
  }
  template <class F>
  int min_left(int r, F f) const {
    assert(0 <= r && r <= _n);
    assert(f(e()));
    if (r == 0) return 0;
    r += size;
    T s = e();
    do {
      r--;
      while (r > 1 && (r % 2)) r >>= 1;
      if (!f(op(d[r], s))) {
        while (r < size) {
          r <<= 1, r++;
          if (f(op(d[r], s))) s = op(d[r--], s);
        }
        return r + 1 - size;
      }
      s = op(d[r], s);
    } while ((r & -r) != r);
    return 0;
  }
};

/**
 * @brief Segment Tree
 * @docs docs/segment-tree/segment-tree.md
 */