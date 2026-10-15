#pragma once

template <class T>
vector<int> LCPArray(const vector<T>& s, const vector<int>& sa) {
  assert(s.size() == sa.size());
  int n = s.size();
  assert(n >= 1);
  vector<int> rank(n);
  for (int i = 0; i < n; i++) {
    assert(0 <= sa[i] && sa[i] < n);
    rank[sa[i]] = i;
  }
  vector<int> lcp(n - 1);
  int h = 0;
  for (int i = 0; i < n; i++) {
    if (h > 0) h--;
    if (rank[i] == 0) continue;
    int j = sa[rank[i] - 1];
    while (i + h < n && j + h < n && s[i + h] == s[j + h]) h++;
    lcp[rank[i] - 1] = h;
  }
  return lcp;
}

vector<int> LCPArray(const string& s, const vector<int>& sa) {
  int n = s.size();
  vector<int> s2(n);
  for (int i = 0; i < n; i++) s2[i] = s[i];
  return LCPArray(s2, sa);
}

/**
 * @brief LCP Array
 * @docs docs/string/lcp-array.md
 */
