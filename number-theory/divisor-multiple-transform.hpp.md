---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/gcd.hpp
    title: "gcd \u7573\u307F\u8FBC\u307F"
  - icon: ':heavy_check_mark:'
    path: convolution/lcm.hpp
    title: "lcm \u7573\u307F\u8FBC\u307F"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/convolution/LC_gcd_convolution.test.cpp
    title: verify/convolution/LC_gcd_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/convolution/LC_lcm_convolution.test.cpp
    title: verify/convolution/LC_lcm_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/number-theory/divisor-multiple-transform.md
    document_title: "\u7D04\u6570\u30FB\u500D\u6570\u5909\u63DB"
    links: []
  bundledCode: "#line 2 \"number-theory/divisor-multiple-transform.hpp\"\n\ntemplate\
    \ <class T>\nvoid DivisorZetaTransform(vector<T>& a) {\n  if (a.empty()) return;\n\
    \  int n = a.size();\n  vector<bool> sieve(n, true);\n  for (int p = 2; p < n;\
    \ p++) {\n    if (sieve[p]) {\n      for (int k = 1; k * p < n; k++) {\n     \
    \   sieve[k * p] = false;\n        a[k * p] += a[k];\n      }\n    }\n  }\n}\n\
    \ntemplate <class T>\nvoid DivisorMobiusTransform(vector<T>& a) {\n  if (a.empty())\
    \ return;\n  int n = a.size();\n  vector<bool> sieve(n, true);\n  for (int p =\
    \ 2; p < n; p++) {\n    if (sieve[p]) {\n      for (int k = (n - 1) / p; k > 0;\
    \ k--) {\n        sieve[k * p] = false;\n        a[k * p] -= a[k];\n      }\n\
    \    }\n  }\n}\n\ntemplate <class T>\nvoid MultipleZetaTransform(vector<T>& a)\
    \ {\n  if (a.empty()) return;\n  int n = a.size();\n  vector<bool> sieve(n, true);\n\
    \  for (int p = 2; p < n; p++) {\n    if (sieve[p]) {\n      for (int k = (n -\
    \ 1) / p; k > 0; k--) {\n        sieve[k * p] = false;\n        a[k] += a[k *\
    \ p];\n      }\n    }\n  }\n}\n\ntemplate <class T>\nvoid MultipleMobiusTransform(vector<T>&\
    \ a) {\n  if (a.empty()) return;\n  int n = a.size();\n  vector<bool> sieve(n,\
    \ true);\n  for (int p = 2; p < n; p++) {\n    if (sieve[p]) {\n      for (int\
    \ k = 1; k * p < n; k++) {\n        sieve[k * p] = false;\n        a[k] -= a[k\
    \ * p];\n      }\n    }\n  }\n}\n\n/**\n * @brief \u7D04\u6570\u30FB\u500D\u6570\
    \u5909\u63DB\n * @docs docs/number-theory/divisor-multiple-transform.md\n */\n"
  code: "#pragma once\n\ntemplate <class T>\nvoid DivisorZetaTransform(vector<T>&\
    \ a) {\n  if (a.empty()) return;\n  int n = a.size();\n  vector<bool> sieve(n,\
    \ true);\n  for (int p = 2; p < n; p++) {\n    if (sieve[p]) {\n      for (int\
    \ k = 1; k * p < n; k++) {\n        sieve[k * p] = false;\n        a[k * p] +=\
    \ a[k];\n      }\n    }\n  }\n}\n\ntemplate <class T>\nvoid DivisorMobiusTransform(vector<T>&\
    \ a) {\n  if (a.empty()) return;\n  int n = a.size();\n  vector<bool> sieve(n,\
    \ true);\n  for (int p = 2; p < n; p++) {\n    if (sieve[p]) {\n      for (int\
    \ k = (n - 1) / p; k > 0; k--) {\n        sieve[k * p] = false;\n        a[k *\
    \ p] -= a[k];\n      }\n    }\n  }\n}\n\ntemplate <class T>\nvoid MultipleZetaTransform(vector<T>&\
    \ a) {\n  if (a.empty()) return;\n  int n = a.size();\n  vector<bool> sieve(n,\
    \ true);\n  for (int p = 2; p < n; p++) {\n    if (sieve[p]) {\n      for (int\
    \ k = (n - 1) / p; k > 0; k--) {\n        sieve[k * p] = false;\n        a[k]\
    \ += a[k * p];\n      }\n    }\n  }\n}\n\ntemplate <class T>\nvoid MultipleMobiusTransform(vector<T>&\
    \ a) {\n  if (a.empty()) return;\n  int n = a.size();\n  vector<bool> sieve(n,\
    \ true);\n  for (int p = 2; p < n; p++) {\n    if (sieve[p]) {\n      for (int\
    \ k = 1; k * p < n; k++) {\n        sieve[k * p] = false;\n        a[k] -= a[k\
    \ * p];\n      }\n    }\n  }\n}\n\n/**\n * @brief \u7D04\u6570\u30FB\u500D\u6570\
    \u5909\u63DB\n * @docs docs/number-theory/divisor-multiple-transform.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: number-theory/divisor-multiple-transform.hpp
  requiredBy:
  - convolution/gcd.hpp
  - convolution/lcm.hpp
  timestamp: '2025-10-10 17:35:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/convolution/LC_lcm_convolution.test.cpp
  - verify/convolution/LC_gcd_convolution.test.cpp
documentation_of: number-theory/divisor-multiple-transform.hpp
layout: document
redirect_from:
- /library/number-theory/divisor-multiple-transform.hpp
- /library/number-theory/divisor-multiple-transform.hpp.html
title: "\u7D04\u6570\u30FB\u500D\u6570\u5909\u63DB"
---
## 約数・倍数変換

長さ $\red{N+1}$ の vector $(a_0,a_1,\dots,a_N)$ を受け取る．

(約数/倍数)(ゼータ/メビウス)変換では次を満たす vector $(b_0,b_1,\dots,b_N)$ を返す．

- $b_0=0$．
- ゼータ変換：$b_i\ (1\leq i\leq N)$ は $i$ の(約数/倍数)である $j$ についての $a_j$ の総和．
- メビウス変換：ゼータ変換の逆変換．

いずれも時間計算量は $O(N\log\log N)$．

### GCD/LCM 畳み込み

代表的な使用例．

- gcd 畳み込み：数列 $a,b$ から $c_k=\sum_{\gcd(i,j)=k}a_ib_j$ を満たす数列 $c$ を得る．
- lcm 畳み込み：数列 $a,b$ から $c_k=\sum_{\operatorname{lcm}(i,j)=k}a_ib_j$ を満たす数列 $c$ を得る．

ゼータ変換し，各点積をとってメビウス変換すればよい．
