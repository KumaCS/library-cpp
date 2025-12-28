#pragma once

struct RollingHash {
  using u128 = __uint128_t;
  using u64 = uint64_t;
  static const u64 MOD = (1ll << 61) - 1;
  static u64 base;
  static u64 add(u64 x, u64 y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
  }
  static u64 sub(u64 x, u64 y) {
    if ((x -= y) >= MOD) x += MOD;
    return x;
  }
  static u64 mul(u64 x, u64 y) {
    return (u64)((u128)x * y % MOD);
  }
  vector<u64> hash, pw;
  RollingHash() : hash({0}), pw({1}) {}
  template <class T>
  RollingHash(vector<T>& a) : hash({0}), pw({1}) {
    for (auto v : a) push(v);
  }
  template <class T>
  void push(T v) {
    hash.push_back(add(mul(base, hash.back()), v));
    pw.push_back(mul(base, pw.back()));
  }
  u64 get(int l, int r) {
    assert(l <= r);
    return sub(hash[r], mul(hash[l], pw[r - l]));
  }
};
RollingHash::u64 RollingHash::base = []() {
  random_device seed_gen;
  mt19937 rnd(seed_gen());
  return rnd() % (1ull << 40);
}();