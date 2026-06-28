#pragma once

template <class T>
struct Compress : vector<T> {
  void build() {
    sort(this->begin(), this->end());
    this->erase(unique(this->begin(), this->end()), this->end());
  }
  int find(T v) const { return int(lower_bound(this->begin(), this->end(), v) - this->begin()); }
};

/**
 * @brief 座標圧縮
 * @docs docs/data-structure/compress.md
 */
