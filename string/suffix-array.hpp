#pragma once

namespace SuffixArrayInternal {
vector<int> sa_naive(const vector<int>& s) {
  int n = s.size();
  vector<int> sa(n);
  iota(sa.begin(), sa.end(), 0);
  sort(sa.begin(), sa.end(), [&](int l, int r) {
    if (l == r) return false;
    while (l < n && r < n) {
      if (s[l] != s[r]) return s[l] < s[r];
      l++, r++;
    }
    return l == n;
  });
  return sa;
}
vector<int> sa_doubling(const vector<int>& s) {
  int n = s.size();
  vector<int> sa(n), tmp(n);
  auto rank = s;
  iota(sa.begin(), sa.end(), 0);
  for (int k = 1; k < n; k *= 2) {
    auto cmp = [&](int x, int y) {
      if (rank[x] != rank[y]) return rank[x] < rank[y];
      int rx = x + k < n ? rank[x + k] : -1;
      int ry = y + k < n ? rank[y + k] : -1;
      return rx < ry;
    };
    sort(sa.begin(), sa.end(), cmp);
    tmp[sa[0]] = 0;
    for (int i = 1; i < n; i++)
      tmp[sa[i]] = tmp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
    swap(tmp, rank);
  }
  return sa;
}
template <int THRESHOLD_NAIVE = 10, int THRESHOLD_DOUBLING = 40>
vector<int> sa_is(const vector<int>& s, int upper) {
  int n = s.size();
  if (n == 0) return {};
  if (n == 1) return {0};
  if (n == 2) {
    if (s[0] < s[1])
      return {0, 1};
    else
      return {1, 0};
  }
  if (n < THRESHOLD_NAIVE) return sa_naive(s);
  if (n < THRESHOLD_DOUBLING) return sa_doubling(s);

  vector<int> sa(n);
  vector<bool> ls(n);
  for (int i = n - 2; i >= 0; i--) ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] : (s[i] < s[i + 1]);
  vector<int> sum_l(upper + 1), sum_s(upper + 1);
  for (int i = 0; i < n; i++) {
    if (!ls[i])
      sum_s[s[i]]++;
    else
      sum_l[s[i] + 1]++;
  }
  for (int i = 0; i <= upper; i++) {
    sum_s[i] += sum_l[i];
    if (i < upper) sum_l[i + 1] += sum_s[i];
  }
  auto induce = [&](const vector<int>& lms) {
    fill(sa.begin(), sa.end(), -1);
    vector<int> buf(upper + 1);
    copy(sum_s.begin(), sum_s.end(), buf.begin());
    for (auto d : lms) {
      if (d == n) continue;
      sa[buf[s[d]]++] = d;
    }
    copy(sum_l.begin(), sum_l.end(), buf.begin());
    sa[buf[s[n - 1]]++] = n - 1;
    for (int i = 0; i < n; i++) {
      int v = sa[i];
      if (v >= 1 && !ls[v - 1]) sa[buf[s[v - 1]]++] = v - 1;
    }
    copy(sum_l.begin(), sum_l.end(), buf.begin());
    for (int i = n - 1; i >= 0; i--) {
      int v = sa[i];
      if (v >= 1 && ls[v - 1]) sa[--buf[s[v - 1] + 1]] = v - 1;
    }
  };
  vector<int> lms_map(n + 1, -1);
  int m = 0;
  for (int i = 1; i < n; i++)
    if (!ls[i - 1] && ls[i]) lms_map[i] = m++;
  vector<int> lms;
  lms.reserve(m);
  for (int i = 1; i < n; i++)
    if (!ls[i - 1] && ls[i]) lms.push_back(i);
  induce(lms);
  if (m) {
    vector<int> sorted_lms;
    sorted_lms.reserve(m);
    for (int v : sa)
      if (lms_map[v] != -1) sorted_lms.push_back(v);
    vector<int> rec_s(m);
    int rec_upper = 0;
    rec_s[lms_map[sorted_lms[0]]] = 0;
    for (int i = 1; i < m; i++) {
      int l = sorted_lms[i - 1], r = sorted_lms[i];
      int end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;
      int end_r = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;
      bool same = true;
      if (end_l - l != end_r - r) {
        same = false;
      } else {
        while (l < end_l && s[l] == s[r]) l++, r++;
        if (l == n || s[l] != s[r]) same = false;
      }
      if (!same) rec_upper++;
      rec_s[lms_map[sorted_lms[i]]] = rec_upper;
    }
    auto rec_sa = sa_is<THRESHOLD_NAIVE, THRESHOLD_DOUBLING>(rec_s, rec_upper);
    for (int i = 0; i < m; i++) sorted_lms[i] = lms[rec_sa[i]];
    induce(sorted_lms);
  }
  return sa;
}
}  // namespace SuffixArrayInternal

vector<int> SuffixArray(const vector<int>& s, int upper) {
  assert(0 <= upper);
  for (int d : s) assert(0 <= d && d <= upper);
  auto sa = SuffixArrayInternal::sa_is(s, upper);
  return sa;
}

template <class T>
vector<int> SuffixArray(const vector<T>& s) {
  int n = s.size();
  vector<int> idx(n);
  iota(idx.begin(), idx.end(), 0);
  sort(idx.begin(), idx.end(), [&](int l, int r) { return s[l] < s[r]; });
  vector<int> s2(n);
  int now = 0;
  for (int i = 0; i < n; i++) {
    if (i > 0 && s[idx[i - 1]] != s[idx[i]]) now++;
    s2[idx[i]] = now;
  }
  return SuffixArrayInternal::sa_is(s2, now);
}

vector<int> SuffixArray(const string& s) {
  int n = s.size();
  vector<int> s2(n);
  for (int i = 0; i < n; i++) s2[i] = s[i];
  return SuffixArrayInternal::sa_is(s2, 255);
}

/**
 * @brief Suffix Array
 * @docs docs/string/suffix-array.md
 */
