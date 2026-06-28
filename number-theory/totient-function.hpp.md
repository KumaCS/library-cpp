---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/lpf-table.hpp
    title: LPF Table
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"number-theory/totient-function.hpp\"\n\n#line 2 \"math/lpf-table.hpp\"\
    \n\nvector<int> LPFTable(int n) {\n  vector<int> lpf(n + 1, 0);\n  iota(lpf.begin(),\
    \ lpf.end(), 0);\n  for (int p = 2; p * p <= n; p += (p & 1) + 1) {\n    if (lpf[p]\
    \ != p) continue;\n    for (int i = p * p; i <= n; i += p)\n      if (lpf[i] ==\
    \ i) lpf[i] = p;\n  }\n  return lpf;\n}\n/**\n * @brief LPF Table\n */\n#line\
    \ 4 \"number-theory/totient-function.hpp\"\n\nnamespace TotientFunction {\nvector<int>\
    \ table(int n) {\n  vector<int> tot(n + 1, 1);\n  tot[0] = 0;\n  auto lpf = LPFTable(n);\n\
    \  for (int x = 2; x <= n; x++) {\n    int p = lpf[x];\n    if (x / p % p == 0)\n\
    \      tot[x] = tot[x / p] * p;\n    else\n      tot[x] = tot[x / p] * (p - 1);\n\
    \  }\n  return tot;\n}\n};  // namespace TotientFunction\n"
  code: "#pragma once\n\n#include \"math/lpf-table.hpp\"\n\nnamespace TotientFunction\
    \ {\nvector<int> table(int n) {\n  vector<int> tot(n + 1, 1);\n  tot[0] = 0;\n\
    \  auto lpf = LPFTable(n);\n  for (int x = 2; x <= n; x++) {\n    int p = lpf[x];\n\
    \    if (x / p % p == 0)\n      tot[x] = tot[x / p] * p;\n    else\n      tot[x]\
    \ = tot[x / p] * (p - 1);\n  }\n  return tot;\n}\n};  // namespace TotientFunction"
  dependsOn:
  - math/lpf-table.hpp
  isVerificationFile: false
  path: number-theory/totient-function.hpp
  requiredBy: []
  timestamp: '2026-06-28 15:22:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: number-theory/totient-function.hpp
layout: document
redirect_from:
- /library/number-theory/totient-function.hpp
- /library/number-theory/totient-function.hpp.html
title: number-theory/totient-function.hpp
---
