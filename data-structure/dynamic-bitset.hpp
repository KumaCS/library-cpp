#pragma once

struct DynamicBitset {
  using u64 = uint64_t;
  struct reference {
    DynamicBitset* b;
    int pos;
    reference& operator=(bool v) {
      b->set(pos, v);
      return *this;
    }
    reference& operator=(const reference& r) { return *this = bool(r); }
    reference& flip() {
      b->flip(pos);
      return *this;
    }
    operator bool() const { return b->test(pos); }
  };

  DynamicBitset() : _n(0) {}
  explicit DynamicBitset(int n, bool value = false) : _n(n), a(blocks(n), value ? ~0ull : 0ull) {
    trim();
  }

  int size() const { return _n; }
  bool empty() const { return _n == 0; }
  bool test(int pos) const {
    assert(0 <= pos && pos < _n);
    return (a[pos / W] >> (pos % W)) & 1ull;
  }
  bool operator[](int pos) const { return test(pos); }
  reference operator[](int pos) {
    assert(0 <= pos && pos < _n);
    return reference{this, pos};
  }
  DynamicBitset& set() {
    fill(a.begin(), a.end(), ~0ull);
    trim();
    return *this;
  }
  DynamicBitset& set(int pos, bool value = true) {
    assert(0 <= pos && pos < _n);
    if (value)
      a[pos / W] |= 1ull << (pos % W);
    else
      a[pos / W] &= ~(1ull << (pos % W));
    return *this;
  }
  DynamicBitset& reset() {
    fill(a.begin(), a.end(), 0);
    return *this;
  }
  DynamicBitset& reset(int pos) { return set(pos, false); }
  DynamicBitset& flip() {
    for (auto& x : a) x = ~x;
    trim();
    return *this;
  }
  DynamicBitset& flip(int pos) {
    assert(0 <= pos && pos < _n);
    a[pos / W] ^= 1ull << (pos % W);
    return *this;
  }
  int count() const {
    int ret = 0;
    for (u64 x : a) ret += __builtin_popcountll(x);
    return ret;
  }
  bool any() const {
    for (u64 x : a)
      if (x) return true;
    return false;
  }
  bool none() const { return !any(); }
  bool all() const { return count() == _n; }

  DynamicBitset& operator&=(const DynamicBitset& r) {
    assert(_n == r._n);
    for (int i = 0; i < (int)a.size(); i++) a[i] &= r.a[i];
    return *this;
  }
  DynamicBitset& operator|=(const DynamicBitset& r) {
    assert(_n == r._n);
    for (int i = 0; i < (int)a.size(); i++) a[i] |= r.a[i];
    return *this;
  }
  DynamicBitset& operator^=(const DynamicBitset& r) {
    assert(_n == r._n);
    for (int i = 0; i < (int)a.size(); i++) a[i] ^= r.a[i];
    return *this;
  }
  DynamicBitset operator~() const {
    DynamicBitset ret(*this);
    ret.flip();
    return ret;
  }
  DynamicBitset operator&(const DynamicBitset& r) const { return DynamicBitset(*this) &= r; }
  DynamicBitset operator|(const DynamicBitset& r) const { return DynamicBitset(*this) |= r; }
  DynamicBitset operator^(const DynamicBitset& r) const { return DynamicBitset(*this) ^= r; }
  DynamicBitset& operator<<=(int k) {
    assert(k >= 0);
    if (k >= _n) return reset();
    int q = k / W, r = k % W;
    if (q) {
      for (int i = (int)a.size() - 1; i >= 0; i--) a[i] = i >= q ? a[i - q] : 0;
    }
    if (r) {
      for (int i = (int)a.size() - 1; i > 0; i--) a[i] = (a[i] << r) | (a[i - 1] >> (W - r));
      a[0] <<= r;
    }
    trim();
    return *this;
  }
  DynamicBitset& operator>>=(int k) {
    assert(k >= 0);
    if (k >= _n) return reset();
    int q = k / W, r = k % W;
    if (q) {
      for (int i = 0; i < (int)a.size(); i++) a[i] = i + q < (int)a.size() ? a[i + q] : 0;
    }
    if (r) {
      for (int i = 0; i + 1 < (int)a.size(); i++) a[i] = (a[i] >> r) | (a[i + 1] << (W - r));
      a.back() >>= r;
    }
    return *this;
  }
  DynamicBitset operator<<(int k) const { return DynamicBitset(*this) <<= k; }
  DynamicBitset operator>>(int k) const { return DynamicBitset(*this) >>= k; }
  bool operator==(const DynamicBitset& r) const { return _n == r._n && a == r.a; }
  bool operator!=(const DynamicBitset& r) const { return !(*this == r); }
  int find_first() const { return find_next(-1); }
  int find_next(int pos) const {
    assert(-1 <= pos && pos < _n);
    int i = pos + 1;
    if (i >= _n) return _n;
    int b = i / W;
    u64 x = a[b] & (~0ull << (i % W));
    while (true) {
      if (x) {
        int ret = b * W + __builtin_ctzll(x);
        return ret < _n ? ret : _n;
      }
      if (++b == (int)a.size()) return _n;
      x = a[b];
    }
  }
  string to_string() const {
    string s(_n, '0');
    for (int i = 0; i < _n; i++)
      if (test(i)) s[_n - 1 - i] = '1';
    return s;
  }

 private:
  static constexpr int W = 64;
  int _n;
  vector<u64> a;
  static int blocks(int n) { return (n + W - 1) / W; }
  void trim() {
    if (_n == 0) return;
    int r = _n % W;
    if (r) a.back() &= (1ull << r) - 1;
  }
};

/**
 * @brief Dynamic Bitset
 * @docs docs/data-structure/dynamic-bitset.md
 */
