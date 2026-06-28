#define PROBLEM "https://judge.yosupo.jp/problem/static_range_count_distinct"

#include "template/template.hpp"
#include "algorithm/mo.hpp"
#include "data-structure/compress.hpp"

int main() {
  int n, q;
  in(n, q);
  vector<int> a(n);
  in(a);
  Compress<int> comp;
  for (int x : a) comp.push_back(x);
  comp.build();
  for (int& x : a) x = comp.find(x);

  Mo mo(n);
  rep(i, 0, q) {
    int l, r;
    in(l, r);
    mo.add_query(l, r);
  }

  vector<int> cnt(comp.size()), ans(q);
  int cur = 0;
  auto add = [&](int i) {
    if (cnt[a[i]]++ == 0) cur++;
  };
  auto del = [&](int i) {
    if (--cnt[a[i]] == 0) cur--;
  };
  auto query = [&](int i) {
    ans[i] = cur;
  };
  mo.run(add, del, query);
  for (int x : ans) out(x);
}
