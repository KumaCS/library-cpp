#pragma once
#include "algebraic-structure/monoid.hpp"

template <class M>
REQUIRES(Monoid<M>)
struct RangeSetRangeProd {
  using T = typename M::value_type;

 private:
  int _n, size, log, history_limit;
  vector<T> d;
  vector<int> lz, height;
  vector<vector<T>> history;

  void update(int k) { d[k] = M::op(d[2 * k], d[2 * k + 1]); }
  void all_apply(int k, int id) {
    d[k] = history[id][height[k]];
    if (k < size) lz[k] = id;
  }
  void push(int k) {
    if (lz[k] == -1) return;
    all_apply(2 * k, lz[k]);
    all_apply(2 * k + 1, lz[k]);
    lz[k] = -1;
  }
  void flush() {
    for (int k = 1; k < size; k++) push(k);
    history.clear();
  }
  int add_history(T x) {
    if ((int)history.size() == history_limit) flush();
    vector<T> power;
    power.reserve(log + 1);
    power.push_back(x);
    for (int i = 0; i < log; i++) power.push_back(M::op(power.back(), power.back()));
    history.push_back(move(power));
    return (int)history.size() - 1;
  }

 public:
  RangeSetRangeProd() : RangeSetRangeProd(0) {}
  explicit RangeSetRangeProd(int n) : RangeSetRangeProd(vector<T>(n, M::e())) {}
  explicit RangeSetRangeProd(const vector<T>& v) : _n(int(v.size())) {
    size = 1, log = 0;
    while (size < _n) size <<= 1, log++;
    d = vector<T>(2 * size, M::e());
    lz = vector<int>(size, -1);
    height = vector<int>(2 * size);
    for (int k = size - 1; k > 0; k--) height[k] = height[2 * k] + 1;
    for (int i = 0; i < _n; i++) d[size + i] = v[i];
    for (int k = size - 1; k > 0; k--) update(k);
    history_limit = max(1, size / (log + 1));
  }

  void set(int p, T x) {
    assert(0 <= p && p < _n);
    p += size;
    for (int i = log; i >= 1; i--) push(p >> i);
    d[p] = x;
    for (int i = 1; i <= log; i++) update(p >> i);
  }
  T get(int p) {
    assert(0 <= p && p < _n);
    p += size;
    for (int i = log; i >= 1; i--) push(p >> i);
    return d[p];
  }
  T prod(int l, int r) {
    assert(0 <= l && l <= r && r <= _n);
    if (l == r) return M::e();
    l += size, r += size;
    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }
    T sml = M::e(), smr = M::e();
    while (l < r) {
      if (l & 1) sml = M::op(sml, d[l++]);
      if (r & 1) smr = M::op(d[--r], smr);
      l >>= 1, r >>= 1;
    }
    return M::op(sml, smr);
  }
  T all_prod() { return d[1]; }
  void apply(int p, T x) { set(p, x); }
  void apply(int l, int r, T x) {
    assert(0 <= l && l <= r && r <= _n);
    if (l == r) return;
    int id = add_history(x);
    l += size, r += size;
    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }
    {
      int l2 = l, r2 = r;
      while (l < r) {
        if (l & 1) all_apply(l++, id);
        if (r & 1) all_apply(--r, id);
        l >>= 1, r >>= 1;
      }
      l = l2, r = r2;
    }
    for (int i = 1; i <= log; i++) {
      if (((l >> i) << i) != l) update(l >> i);
      if (((r >> i) << i) != r) update((r - 1) >> i);
    }
  }
  template <bool (*g)(T)>
  int max_right(int l) {
    return max_right(l, [](T x) { return g(x); });
  }
  template <class G>
  int max_right(int l, G g) {
    assert(0 <= l && l <= _n);
    assert(g(M::e()));
    if (l == _n) return _n;
    l += size;
    for (int i = log; i >= 1; i--) push(l >> i);
    T sm = M::e();
    do {
      while (l % 2 == 0) l >>= 1;
      if (!g(M::op(sm, d[l]))) {
        while (l < size) {
          push(l);
          l = 2 * l;
          if (g(M::op(sm, d[l]))) sm = M::op(sm, d[l++]);
        }
        return l - size;
      }
      sm = M::op(sm, d[l++]);
    } while ((l & -l) != l);
    return _n;
  }

  template <bool (*g)(T)>
  int min_left(int r) {
    return min_left(r, [](T x) { return g(x); });
  }
  template <class G>
  int min_left(int r, G g) {
    assert(0 <= r && r <= _n);
    assert(g(M::e()));
    if (r == 0) return 0;
    r += size;
    for (int i = log; i >= 1; i--) push((r - 1) >> i);
    T sm = M::e();
    do {
      r--;
      while (r > 1 && (r % 2)) r >>= 1;
      if (!g(M::op(d[r], sm))) {
        while (r < size) {
          push(r);
          r = 2 * r + 1;
          if (g(M::op(d[r], sm))) sm = M::op(d[r--], sm);
        }
        return r + 1 - size;
      }
      sm = M::op(d[r], sm);
    } while ((r & -r) != r);
    return 0;
  }
};

/**
 * @brief Range Set Range Prod
 * @docs docs/segment-tree/range-set-range-prod.md
 */
