#pragma once

template <class F, F (*op)(F, F), F (*e)()>
struct DualSegmentTree {
 private:
  int _n, size, log;
  vector<F> lz;

 public:
  DualSegmentTree() : DualSegmentTree(0) {}
  explicit DualSegmentTree(int n) : DualSegmentTree(vector<F>(n, e())) {}
  explicit DualSegmentTree(const vector<F> &v) : _n(int(v.size())) {
    size = 1, log = 0;
    while (size < _n) size <<= 1, log++;
    lz = vector<F>(2 * size, e());
    for (int i = 0; i < _n; i++) lz[size + i] = v[i];
  }
  void set(int p, F f) {
    assert(0 <= p && p < _n);
    p += size;
    for (int i = log; i > 0; i--) push(p >> i);
    lz[p] = f;
  }
  F get(int p) {
    assert(0 <= p && p < _n);
    p += size;
    for (int i = log; i > 0; i--) push(p >> i);
    return lz[p];
  }
  vector<F> all_get() {
    for (int i = 1; i < size; i++) push(i);
    return vector<F>(lz.begin() + size, lz.begin() + (size + _n));
  }
  void apply(int p, F f) {
    assert(0 <= p && p < _n);
    p += size;
    for (int i = log; i > 0; i--) push(p >> i);
    inner_apply(p, f);
  }
  void apply(int l, int r, F f) {
    if (l >= r) return;
    assert(0 <= l && l <= r && r <= _n);
    l += size, r += size;
    for (int i = log; i > 0; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }
    while (l < r) {
      if ((l & 1) != 0) inner_apply(l++, f);
      if ((r & 1) != 0) inner_apply(--r, f);
      l >>= 1, r >>= 1;
    }
  }

 private:
  void push(int k) {
    inner_apply(2 * k, lz[k]);
    inner_apply(2 * k + 1, lz[k]);
    lz[k] = e();
  }
  void inner_apply(int k, F f) { lz[k] = op(f, lz[k]); }
};

/**
 * @brief Dual Segment Tree
 * @docs docs/segment-tree/dual-segment-tree.md
 */