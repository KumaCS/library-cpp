#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "binary-search-tree/rbst-reversible-array-large.hpp"

using Tree = RBSTReversibleArrayLarge<long long>;

void destroy(Tree::Ptr t) {
  if (!t) return;
  destroy(t->l);
  destroy(t->r);
  delete t;
}

void check(Tree& tree, Tree::Ptr t, const vector<long long>& a) {
  assert(tree.size(t) == (long long)a.size());
  for (int i = 0; i < (int)a.size(); i++) assert(tree.get(t, i) == a[i]);
  vector<long long> b;
  for (auto [l, r] : tree.enumerate(t)) {
    long long d = l <= r ? 1 : -1;
    for (long long x = l;; x += d) {
      b.push_back(x);
      if (x == r) break;
    }
  }
  assert(a == b);
}

int main() {
  mt19937 rng(1234567);
  for (int n : {0, 1, 2, 15, 16, 17, 31, 32, 33, 80}) {
    Tree tree;
    auto t = tree.build(n);
    vector<long long> a(n);
    iota(a.begin(), a.end(), 0);
    check(tree, t, a);
    for (int tc = 0; tc < 300; tc++) {
      int l = rng() % (n + 1), r = rng() % (n + 1);
      if (l > r) swap(l, r);
      tree.reverse(t, l, r);
      reverse(a.begin() + l, a.begin() + r);
      check(tree, t, a);
      int k = rng() % (n + 1);
      auto [tl, tr] = tree.split(t, k);
      check(tree, tl, vector<long long>(a.begin(), a.begin() + k));
      check(tree, tr, vector<long long>(a.begin() + k, a.end()));
      t = tree.merge(tl, tr);
    }
    destroy(t);
  }
  {
    Tree tree;
    long long n = (1LL << 45) + 17, l = 123, r = n - 456;
    auto t = tree.build(n);
    tree.reverse(t, l, r);
    for (long long k : {0LL, l - 1, l, l + 1, r - 1, r, n - 1})
      assert(tree.get(t, k) == (l <= k && k < r ? l + r - 1 - k : k));
    auto [tl, tr] = tree.split(t, 1LL << 40);
    assert(tree.size(tl) == (1LL << 40));
    assert(tree.size(tr) == n - (1LL << 40));
    t = tree.merge(tl, tr);
    tree.reverse(t, l, r);
    assert((tree.enumerate(t).size() <= 5));
    for (long long k : {0LL, l, 1LL << 40, r, n - 1}) assert(tree.get(t, k) == k);
    destroy(t);
  }
  int a, b;
  in(a, b);
  out(a + b);
}
