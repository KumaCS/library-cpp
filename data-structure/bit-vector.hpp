#pragma once

struct BitVector {
  using i32 = int32_t;
  using u32 = uint32_t;
  using u64 = uint64_t;

  static constexpr u32 W = 64;
  inline u32 get(u32 i) const { return u32(block[i / W] >> (i % W)) & 1u; }
  inline void set(u32 i) { block[i / W] |= 1ull << (i % W); }

  vector<u64> block;
  vector<i32> count;
  u32 n, zeros;
  BitVector() {}
  BitVector(int _n) : n(_n) {
    block.resize(n / W + 1, 0);
    count.resize(block.size(), 0);
  }
  void build() {
    for (u32 i = 1; i < block.size(); i++)
      count[i] = count[i - 1] + __builtin_popcountll(block[i - 1]);
    zeros = rank0(n);
  }
  inline u32 rank0(u32 i) const { return i - rank1(i); }
  inline u32 rank1(u32 i) const { return count[i / W] + __builtin_popcountll(block[i / W] & ((1ull << i % W) - 1)); }
};
