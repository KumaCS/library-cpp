#pragma once

template <class T>
struct Compress : vector<T> {
  void build() {
    sort(begin(), end());
    erase(unique(begin(), end()), end());
  }
  int find(T v) const { return int(lower_bound(begin(), end(), v) - begin()); }
};

/**
 * @brief 座標圧縮
 * @docs docs/data-structure/compress.md
 */