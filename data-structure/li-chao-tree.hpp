#pragma once

template <class T>
struct LiChaoTree {
  struct Line {
    T a, b;
    Line() : a(0), b(0) {}
    Line(T a_, T b_) : a(a_), b(b_) {}
    T get(T x) const { return a * x + b; }
  };

  LiChaoTree() : n(0), inf(numeric_limits<T>::max() / 4) {}
  LiChaoTree(vector<T> xs_, T inf_ = numeric_limits<T>::max() / 4) : inf(inf_) {
    sort(xs_.begin(), xs_.end());
    xs_.erase(unique(xs_.begin(), xs_.end()), xs_.end());
    xs = xs_;
    n = xs.size();
    seg.assign(n * 4 + 1, Line());
    used.assign(n * 4 + 1, false);
  }

  void add_line(T a, T b) { add_line(Line(a, b)); }
  void add_line(Line line) {
    if (n == 0) return;
    add_line(line, 1, 0, n);
  }
  void add_segment(T l, T r, T a, T b) { add_segment(l, r, Line(a, b)); }
  void add_segment(T l, T r, Line line) {
    if (n == 0) return;
    int il = lower_bound(xs.begin(), xs.end(), l) - xs.begin();
    int ir = lower_bound(xs.begin(), xs.end(), r) - xs.begin();
    add_segment(line, il, ir, 1, 0, n);
  }
  T get(T x) const {
    int k = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    assert(k < n && xs[k] == x);
    return get(x, k, 1, 0, n);
  }

 private:
  int n;
  T inf;
  vector<T> xs;
  vector<Line> seg;
  vector<bool> used;

  void add_line(Line line, int k, int l, int r) {
    if (!used[k]) {
      used[k] = true;
      seg[k] = line;
      return;
    }
    int m = (l + r) >> 1;
    T xl = xs[l], xm = xs[m], xr = xs[r - 1];
    Line low = seg[k], high = line;
    if (low.get(xm) > high.get(xm)) swap(low, high);
    seg[k] = low;
    if (r - l == 1) return;
    if (low.get(xl) > high.get(xl)) {
      add_line(high, k << 1, l, m);
    } else if (low.get(xr) > high.get(xr)) {
      add_line(high, k << 1 | 1, m, r);
    }
  }
  void add_segment(Line line, int ql, int qr, int k, int l, int r) {
    if (qr <= l || r <= ql) return;
    if (ql <= l && r <= qr) {
      add_line(line, k, l, r);
      return;
    }
    int m = (l + r) >> 1;
    add_segment(line, ql, qr, k << 1, l, m);
    add_segment(line, ql, qr, k << 1 | 1, m, r);
  }
  T get(T x, int p, int k, int l, int r) const {
    T ret = used[k] ? seg[k].get(x) : inf;
    if (r - l == 1) return ret;
    int m = (l + r) >> 1;
    if (p < m) return min(ret, get(x, p, k << 1, l, m));
    return min(ret, get(x, p, k << 1 | 1, m, r));
  }
};

/**
 * @brief Li Chao Tree
 * @docs docs/data-structure/li-chao-tree.md
 */
