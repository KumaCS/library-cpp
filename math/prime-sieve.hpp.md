---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u7D20\u6570\u7BE9"
    links: []
  bundledCode: "#line 2 \"math/prime-sieve.hpp\"\n\nvector<int> PrimeSieve(int n)\
    \ {\n  vector<bool> f(n + 1, false);\n  for (int p = 2; p * p <= n; p += (p &\
    \ 1) + 1) {\n    if (f[p]) continue;\n    for (int i = p * p; i <= n; i += p)\
    \ f[i] = true;\n  }\n  vector<int> ps;\n  for (int p = 2; p <= n; p += (p & 1)\
    \ + 1)\n    if (!f[p]) ps.push_back(p);\n  return ps;\n}\n/**\n * @brief \u7D20\
    \u6570\u7BE9\n */\n"
  code: "#pragma once\n\nvector<int> PrimeSieve(int n) {\n  vector<bool> f(n + 1,\
    \ false);\n  for (int p = 2; p * p <= n; p += (p & 1) + 1) {\n    if (f[p]) continue;\n\
    \    for (int i = p * p; i <= n; i += p) f[i] = true;\n  }\n  vector<int> ps;\n\
    \  for (int p = 2; p <= n; p += (p & 1) + 1)\n    if (!f[p]) ps.push_back(p);\n\
    \  return ps;\n}\n/**\n * @brief \u7D20\u6570\u7BE9\n */"
  dependsOn: []
  isVerificationFile: false
  path: math/prime-sieve.hpp
  requiredBy: []
  timestamp: '2025-10-21 21:13:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/prime-sieve.hpp
layout: document
redirect_from:
- /library/math/prime-sieve.hpp
- /library/math/prime-sieve.hpp.html
title: "\u7D20\u6570\u7BE9"
---
