---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/smawk.hpp\"\n\n\ntemplate <class F>\nvector<int>\
    \ SMAWK(int h, int w, const F select) {\n  const auto solve = [&](auto self, const\
    \ vi &row, const vi &col) -> vector<int> {\n    if (row.empty()) return {};\n\
    \    int n = row.size();\n    vector<int> c2;\n    for (const auto i : col) {\n\
    \      while (!c2.empty() && select(row[c2.size() - 1], c2.back(), i) == i)\n\
    \        c2.pop_back();\n      if (c2.size() < n) c2.push_back(i);\n    }\n  \
    \  vector<int> r2(n / 2);\n    for (int i = 1; i < n; i += 2) r2[i >> 1] = row[i];\n\
    \    auto a2 = self(self, r2, c2);\n    vector<int> ans(n);\n    for (int i =\
    \ 0; i < a2.size(); i++) ans[(i << 1) | 1] = a2[i];\n    int j = 0;\n    for (int\
    \ i = 0; i < n; i += 2) {\n      ans[i] = c2[j];\n      int end = i + 1 == n ?\
    \ c2.back() : ans[i + 1];\n      while (c2[j] != end) ans[i] = select(row[i],\
    \ ans[i], c2[++j]);\n    }\n    return ans;\n  };\n  vector<int> rows(h), cols(w);\n\
    \  iota(rows.begin(), rows.end(), 0);\n  iota(cols.begin(), cols.end(), 0);\n\
    \  return solve(solve, rows, cols);\n}\n"
  code: "\n\ntemplate <class F>\nvector<int> SMAWK(int h, int w, const F select) {\n\
    \  const auto solve = [&](auto self, const vi &row, const vi &col) -> vector<int>\
    \ {\n    if (row.empty()) return {};\n    int n = row.size();\n    vector<int>\
    \ c2;\n    for (const auto i : col) {\n      while (!c2.empty() && select(row[c2.size()\
    \ - 1], c2.back(), i) == i)\n        c2.pop_back();\n      if (c2.size() < n)\
    \ c2.push_back(i);\n    }\n    vector<int> r2(n / 2);\n    for (int i = 1; i <\
    \ n; i += 2) r2[i >> 1] = row[i];\n    auto a2 = self(self, r2, c2);\n    vector<int>\
    \ ans(n);\n    for (int i = 0; i < a2.size(); i++) ans[(i << 1) | 1] = a2[i];\n\
    \    int j = 0;\n    for (int i = 0; i < n; i += 2) {\n      ans[i] = c2[j];\n\
    \      int end = i + 1 == n ? c2.back() : ans[i + 1];\n      while (c2[j] != end)\
    \ ans[i] = select(row[i], ans[i], c2[++j]);\n    }\n    return ans;\n  };\n  vector<int>\
    \ rows(h), cols(w);\n  iota(rows.begin(), rows.end(), 0);\n  iota(cols.begin(),\
    \ cols.end(), 0);\n  return solve(solve, rows, cols);\n}"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/smawk.hpp
  requiredBy: []
  timestamp: '2025-10-10 17:35:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/smawk.hpp
layout: document
redirect_from:
- /library/algorithm/smawk.hpp
- /library/algorithm/smawk.hpp.html
title: algorithm/smawk.hpp
---
