#pragma once

namespace XORShift {
unsigned int xor32() {
  static unsigned int x = 123456789u;
  x ^= x << 13, x ^= x >> 17, x ^= x << 5;
  return x;
}
unsigned long long xor64() {
  static unsigned long long x = 123456789ull;
  x ^= x << 13, x ^= x >> 7, x ^= x << 17;
  return x;
}
};  // namespace XORShift

/**
 * @brief XOR shift
 */