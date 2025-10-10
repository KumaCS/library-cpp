#pragma once

unsigned int ModPow(unsigned int a, unsigned long long n, unsigned int m) {
  unsigned long long x = a, y = 1;
  while (n) {
    if (n & 1) y = y * x % m;
    x = x * x % m;
    n >>= 1;
  }
  return y;
}