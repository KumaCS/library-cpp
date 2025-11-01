---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/lpf-table.hpp
    title: LPF Table
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_sum_of_exponential_times_polynomial.test.cpp
    title: verify/fps/LC_sum_of_exponential_times_polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_sum_of_exponential_times_polynomial_limit.test.cpp
    title: verify/fps/LC_sum_of_exponential_times_polynomial_limit.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Power Table
    links: []
  bundledCode: "#line 2 \"math/lpf-table.hpp\"\n\nvector<int> LPFTable(int n) {\n\
    \  vector<int> lpf(n + 1, 0);\n  iota(lpf.begin(), lpf.end(), 0);\n  for (int\
    \ p = 2; p * p <= n; p += (p & 1) + 1) {\n    if (lpf[p] != p) continue;\n   \
    \ for (int i = p * p; i <= n; i += p)\n      if (lpf[i] == i) lpf[i] = p;\n  }\n\
    \  return lpf;\n}\n/**\n * @brief LPF Table\n */\n#line 3 \"modint/power-table.hpp\"\
    \n\n// 0^k,1^k,2^k,...,n^k\ntemplate <class T>\nvector<T> PowerTable(int n, int\
    \ k) {\n  assert(k >= 0);\n  vector<T> f;\n  if (k == 0) {\n    f = vector<T>(n\
    \ + 1, 0);\n    f[0] = 1;\n  } else {\n    f = vector<T>(n + 1, 1);\n    f[0]\
    \ = 0;\n    auto lpf = LPFTable(n);\n    for (int i = 2; i <= n; i++)\n      f[i]\
    \ = lpf[i] == i ? T(i).pow(k) : f[i / lpf[i]] * f[lpf[i]];\n  }\n  return f;\n\
    }\n/**\n * @brief Power Table\n */\n"
  code: "#pragma once\n#include \"math/lpf-table.hpp\"\n\n// 0^k,1^k,2^k,...,n^k\n\
    template <class T>\nvector<T> PowerTable(int n, int k) {\n  assert(k >= 0);\n\
    \  vector<T> f;\n  if (k == 0) {\n    f = vector<T>(n + 1, 0);\n    f[0] = 1;\n\
    \  } else {\n    f = vector<T>(n + 1, 1);\n    f[0] = 0;\n    auto lpf = LPFTable(n);\n\
    \    for (int i = 2; i <= n; i++)\n      f[i] = lpf[i] == i ? T(i).pow(k) : f[i\
    \ / lpf[i]] * f[lpf[i]];\n  }\n  return f;\n}\n/**\n * @brief Power Table\n */"
  dependsOn:
  - math/lpf-table.hpp
  isVerificationFile: false
  path: modint/power-table.hpp
  requiredBy: []
  timestamp: '2025-10-21 21:13:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/fps/LC_sum_of_exponential_times_polynomial.test.cpp
  - verify/fps/LC_sum_of_exponential_times_polynomial_limit.test.cpp
documentation_of: modint/power-table.hpp
layout: document
redirect_from:
- /library/modint/power-table.hpp
- /library/modint/power-table.hpp.html
title: Power Table
---
