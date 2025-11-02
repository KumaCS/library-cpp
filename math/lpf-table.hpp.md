---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/famous-sequences.hpp
    title: "\u6709\u540D\u6570\u5217"
  - icon: ':heavy_check_mark:'
    path: modint/power-table.hpp
    title: Power Table
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_partition_function.test.cpp
    title: verify/fps/LC_partition_function.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_stirling_number_of_the_first_kind.test.cpp
    title: verify/fps/LC_stirling_number_of_the_first_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_stirling_number_of_the_first_kind_fixed_k.test.cpp
    title: verify/fps/LC_stirling_number_of_the_first_kind_fixed_k.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_stirling_number_of_the_second_kind.test.cpp
    title: verify/fps/LC_stirling_number_of_the_second_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_stirling_number_of_the_second_kind_fixed_k.test.cpp
    title: verify/fps/LC_stirling_number_of_the_second_kind_fixed_k.test.cpp
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
    document_title: LPF Table
    links: []
  bundledCode: "#line 2 \"math/lpf-table.hpp\"\n\nvector<int> LPFTable(int n) {\n\
    \  vector<int> lpf(n + 1, 0);\n  iota(lpf.begin(), lpf.end(), 0);\n  for (int\
    \ p = 2; p * p <= n; p += (p & 1) + 1) {\n    if (lpf[p] != p) continue;\n   \
    \ for (int i = p * p; i <= n; i += p)\n      if (lpf[i] == i) lpf[i] = p;\n  }\n\
    \  return lpf;\n}\n/**\n * @brief LPF Table\n */\n"
  code: "#pragma once\n\nvector<int> LPFTable(int n) {\n  vector<int> lpf(n + 1, 0);\n\
    \  iota(lpf.begin(), lpf.end(), 0);\n  for (int p = 2; p * p <= n; p += (p & 1)\
    \ + 1) {\n    if (lpf[p] != p) continue;\n    for (int i = p * p; i <= n; i +=\
    \ p)\n      if (lpf[i] == i) lpf[i] = p;\n  }\n  return lpf;\n}\n/**\n * @brief\
    \ LPF Table\n */"
  dependsOn: []
  isVerificationFile: false
  path: math/lpf-table.hpp
  requiredBy:
  - modint/power-table.hpp
  - fps/famous-sequences.hpp
  timestamp: '2025-10-21 21:13:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/fps/LC_stirling_number_of_the_second_kind_fixed_k.test.cpp
  - verify/fps/LC_stirling_number_of_the_first_kind_fixed_k.test.cpp
  - verify/fps/LC_partition_function.test.cpp
  - verify/fps/LC_stirling_number_of_the_first_kind.test.cpp
  - verify/fps/LC_sum_of_exponential_times_polynomial.test.cpp
  - verify/fps/LC_sum_of_exponential_times_polynomial_limit.test.cpp
  - verify/fps/LC_stirling_number_of_the_second_kind.test.cpp
documentation_of: math/lpf-table.hpp
layout: document
redirect_from:
- /library/math/lpf-table.hpp
- /library/math/lpf-table.hpp.html
title: LPF Table
---
