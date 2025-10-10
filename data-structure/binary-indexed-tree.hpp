#pragma once

template <class T>
struct BinaryIndexedTree {
  int size;
  vector<T> data;
  BinaryIndexedTree(int n) : size(n), data(n) {}
  T add(int p, T x) {
    for (p++; p <= size; p += p & -p) data[p - 1] += x;
  }
  T sum(int p) {
    T s = 0;
    for (; p; p -= p & -p) s += data[p - 1];
    return s;
  }
  T sum(int l, int r) { return sum(r) - sum(l); }

  template <bool (*f)(S)>
  int lower_bound() const {
    return lower_bound([](S x) { return f(x); });
  }
  template <class F>
  int lower_bound(F f) const {
    if (f(T(0))) return 0;
    int x = 0, r = 1;
    while (r < size) r = r << 1;
    T s = 0;
    for (int len = r; len > 0; len >>= 1) {
      if (x + len < size && !f(s + data[x + len])) {
        s += data[x + len];
        x += len;
      }
    }
    return x + 1;
  }
};

/**
 * @brief Binary Indexed Tree
 * @docs docs/data-structure/binary-indexed-tree.md
 */