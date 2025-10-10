

template <class F>
vector<int> SMAWK(int h, int w, const F select) {
  const auto solve = [&](auto self, const vi &row, const vi &col) -> vector<int> {
    if (row.empty()) return {};
    int n = row.size();
    vector<int> c2;
    for (const auto i : col) {
      while (!c2.empty() && select(row[c2.size() - 1], c2.back(), i) == i)
        c2.pop_back();
      if (c2.size() < n) c2.push_back(i);
    }
    vector<int> r2(n / 2);
    for (int i = 1; i < n; i += 2) r2[i >> 1] = row[i];
    auto a2 = self(self, r2, c2);
    vector<int> ans(n);
    for (int i = 0; i < a2.size(); i++) ans[(i << 1) | 1] = a2[i];
    int j = 0;
    for (int i = 0; i < n; i += 2) {
      ans[i] = c2[j];
      int end = i + 1 == n ? c2.back() : ans[i + 1];
      while (c2[j] != end) ans[i] = select(row[i], ans[i], c2[++j]);
    }
    return ans;
  };
  vector<int> rows(h), cols(w);
  iota(rows.begin(), rows.end(), 0);
  iota(cols.begin(), cols.end(), 0);
  return solve(solve, rows, cols);
}