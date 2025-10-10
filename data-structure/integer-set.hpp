#pragma once

// 64 分木
// I:index, U:data
template <class T = unsigned int, class U = unsigned long long>
class IntegerSet {
 private:
  const static T B = 6, W = 64, MASK = W - 1;
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
    for (const auto v : len) start.push_back(start.back() + v);
    data = vector<U>(start.back());
  }
  IntegerSet(string s = "") {
    T n = size = s.size();
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
  optional<T> min(T x) const {
    T d = 0, i = x;
    while (true) {
      if (d + 1 >= start.size()) return nullopt;
      if ((i >> B) >= start[d + 1] - start[d]) return nullopt;
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
  optional<T> max(T x) const {
    T d = 0, i = x;
    while (true) {
      if (i >= size) return nullopt;
      if (d >= data.size()) return nullopt;
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