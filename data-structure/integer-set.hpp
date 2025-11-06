#pragma once

template <class T = int, class U = unsigned long long>
class IntegerSet {
 private:
  static constexpr T B = 6, W = 64, MASK = W - 1;
  T size;
  vector<T> start;
  vector<U> data;
  static T high_bit(U x) {
    if (x == 0) return 0;
    return W - 1 - countl_zero(x);
  }
  static T low_bit(U x) {
    if (x == 0) return W;
    return countr_zero(x);
  }

 public:
  IntegerSet(T n) {
    size = n;
    vector<T> len;
    do len.push_back((n >>= B) + 1);
    while (n > 0);
    start = vector<T>(1, 0);
    start.reserve(len.size() + 1);
    for (auto v : len) start.push_back(start.back() + v);
    data = vector<U>(start.back());
  }
  IntegerSet(string s = "") {
    size = s.size();
    T n = size;
    vector<T> len;
    do len.push_back((n >>= B) + 1);
    while (n > 0);
    start = vector<T>(1, 0);
    start.reserve(len.size() + 1);
    for (const auto v : len) start.push_back(start.back() + v);
    data = vector<U>(start.back());

    for (T i = 0; i < s.size(); i++)
      if (s[i] == '1') data[i >> B] |= U(1) << (i & MASK);
    for (T i = 0; i + 1 < len.size(); i++)
      for (T j = 0; j < len[i]; j++)
        if (data[start[i] + j])
          data[start[i + 1] + (j >> B)] |= U(1) << (j & MASK);
  }
  void add(T x) {
    for (T i = 0; i + 1 < start.size(); i++) {
      data[start[i] + (x >> B)] |= U(1) << (x & MASK);
      x >>= B;
    }
  }
  void remove(T x) {
    for (T i = 0; i + 1 < start.size(); i++) {
      data[start[i] + (x >> B)] &= ~(U(1) << (x & MASK));
      if (data[start[i] + (x >> B)] != 0) return;
      x >>= B;
    }
  }
  bool contains(T x) const { return (data[x >> B] >> (x & MASK)) & 1; }
  T min(T x) const {
    T d = 0, i = x;
    while (true) {
      if (d + 1 >= start.size()) return -1;
      if ((i >> B) >= start[d + 1] - start[d]) return -1;
      U m = data[start[d] + (i >> B)] & ((~U(0)) << (i & MASK));
      if (m == 0) {
        d++;
        i >>= B;
        i++;
      } else {
        i = (i & ~MASK) + low_bit(m);
        if (d == 0) break;
        i <<= B;
        d--;
      }
    }
    return i;
  }
  T max(T x) const {
    T d = 0, i = x;
    while (true) {
      if (i < 0) return -1;
      if (d >= data.size()) return -1;
      U m = data[start[d] + (i >> B)] & ~((~U(1)) << (i & MASK));
      if (m == 0) {
        d++;
        i >>= B;
        i--;
      } else {
        i = (i & ~MASK) + high_bit(m);
        if (d == 0) break;
        i <<= B;
        i |= MASK;
        d--;
      }
    }
    return i;
  }
};

/**
 * @brief 整数の集合(64分木)
 */