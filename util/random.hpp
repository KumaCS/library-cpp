#pragma once

namespace Random {
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uint64_t get() { return gen(); }
// [0,n)
template <class T>
T get(T n) {
  assert(n > 0);
  return get() % n;
}
// [l,r)
template <class T>
T get(T l, T r) {
  assert(l < r);
  return get() % (r - l) + l;
}
double uniform() { return double(get(1 << 30)) / (1 << 30); }

template <class T>
vector<T> get_vector(size_t n, T l, T r) {
  vector<T> a(n);
  for (auto& v : a) v = get(l, r);
  return a;
}

template <class Iter>
void shuffle(Iter begin, Iter end) {
  if (begin == end) return;
  int n = end - begin;
  for (int i = n - 1; i > 0; i--) {
    int j = get(i + 1);
    if (j < i) swap(*(begin + i), *(begin + j));
  }
}
};  // namespace Random

/**
 * @brief Random
 * @docs docs/util/random.md
 */
