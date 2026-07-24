#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "string/rolling-hash.hpp"
#include "string/rolling-hash-segment-tree.hpp"
#include "util/xorshift.hpp"

void check_static(const vector<int>& a) {
  RollingHash hash(a);
  RollingHashSegmentTree<int> seg(a);
  assert(hash.size() == (int)a.size());
  for (int l = 0; l <= (int)a.size(); l++) {
    for (int r = l; r <= (int)a.size(); r++) {
      RollingHash direct(vector<int>(a.begin() + l, a.begin() + r));
      assert(hash.slice(l, r) == direct.slice(0, r - l));
      assert(seg.prod(l, r) == hash.slice(l, r));
    }
  }
  for (int l = 0; l <= (int)a.size(); l++) {
    for (int m = l; m <= (int)a.size(); m++) {
      for (int r = m; r <= (int)a.size(); r++) {
        assert(hash.slice(l, m) + hash.slice(m, r) == hash.slice(l, r));
      }
    }
  }
}

void test_value() {
  static_assert(sizeof(RollingHashValue) == 2 * sizeof(uint64_t));
  static_assert(sizeof(RollingHashValueReversible) == 3 * sizeof(uint64_t));
  RollingHashBase::base = 911382323;
  assert(RollingHashValue() == RollingHashValue(0, 1));
  assert(RollingHashValue::single(-1).hash == RollingHashBase::MOD - 1);
  assert(RollingHashValue::single(0).hash == 0);
  assert(RollingHashValue::single(1).hash == 1);

  RollingHash zero(vector<int>{0});
  RollingHash zeros(vector<int>{0, 0});
  assert(zero.slice(0, 1).hash == zeros.slice(0, 2).hash);
  assert(zero.slice(0, 1) != zeros.slice(0, 2));

  for (long long v :
       {numeric_limits<long long>::min(), -(long long)RollingHashBase::MOD - 1, -1ll, 0ll, 1ll,
        (long long)RollingHashBase::MOD, numeric_limits<long long>::max()}) {
    RollingHashBase::i128 expected = RollingHashBase::i128(v) % RollingHashBase::MOD;
    if (expected < 0) expected += RollingHashBase::MOD;
    assert(RollingHashBase::normalize(v) == RollingHashBase::u64(expected));
  }
  assert(RollingHashBase::restore<int>(RollingHashBase::normalize(numeric_limits<int>::min())) ==
         numeric_limits<int>::min());
  assert(RollingHashBase::restore<int>(RollingHashBase::normalize(numeric_limits<int>::max())) ==
         numeric_limits<int>::max());

  auto x = RollingHashValueReversible::single(-1);
  assert(x.hash == RollingHashBase::MOD - 1);
  assert(x.hash == x.reverse_hash);
  assert(x.reversed() == x);
}

void test_static() {
  check_static({});
  check_static({0});
  check_static({-3, 0, 1, -1, 1000000000, -1000000000});
  string s = "abracadabra";
  RollingHash hash(s);
  RollingHashSegmentTree seg(s);
  for (int l = 0; l <= (int)s.size(); l++)
    for (int r = l; r <= (int)s.size(); r++) assert(seg.prod(l, r) == hash.slice(l, r));
}

void test_segment_tree() {
  int n = 30;
  vector<int> a(n);
  for (int i = 0; i < n; i++) a[i] = int(XORShift::xor32() % 2001) - 1000;
  RollingHashSegmentTree<int> seg(a);
  for (int t = 0; t < 1000; t++) {
    if (XORShift::xor32() & 1) {
      int p = XORShift::xor32() % n;
      a[p] = int(XORShift::xor32() % 2000000001) - 1000000000;
      seg.set(p, a[p]);
      assert(seg.get(p) == a[p]);
    } else {
      int l = XORShift::xor32() % (n + 1);
      int r = XORShift::xor32() % (n + 1);
      if (l > r) swap(l, r);
      RollingHash hash(a);
      assert(seg.prod(l, r) == hash.slice(l, r));
    }
  }
}

void test_reversible() {
  vector<int> a = {-3, 0, 1, -1, 4, 0};
  RollingHashSegmentTreeReversible<int> seg(a);
  RollingHash hash(a);
  for (int l = 0; l <= (int)a.size(); l++) {
    for (int r = l; r <= (int)a.size(); r++) {
      auto value = seg.prod(l, r);
      vector<int> b(a.begin() + l, a.begin() + r);
      reverse(b.begin(), b.end());
      RollingHash reversed(b);
      assert(value.hash == hash.slice(l, r).hash);
      assert(value.reverse_hash == reversed.slice(0, b.size()).hash);
      assert(value.power == hash.slice(l, r).power);
      assert(value.reversed().hash == value.reverse_hash);
      assert(value.reversed().reverse_hash == value.hash);
      for (int m = l; m <= r; m++) {
        auto left = seg.prod(l, m), right = seg.prod(m, r);
        assert(left + right == value);
        assert(value.reversed() == right.reversed() + left.reversed());
      }
    }
  }
  seg.set(2, -100);
  a[2] = -100;
  assert(seg.get(2) == a[2]);
  RollingHash updated(a);
  assert(seg.prod(0, a.size()).hash == updated.slice(0, a.size()).hash);
}

int main() {
  test_value();
  test_static();
  test_segment_tree();
  test_reversible();

  int a, b;
  in(a, b);
  out(a + b);
}
