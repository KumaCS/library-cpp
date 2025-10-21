---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: number-theory/divisor-multiple-transform.hpp
    title: "\u7D04\u6570\u30FB\u500D\u6570\u5909\u63DB"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/convolution/LC_lcm_convolution.test.cpp
    title: verify/convolution/LC_lcm_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/convolution/gcd-lcm.md
    document_title: "lcm \u7573\u307F\u8FBC\u307F"
    links: []
  bundledCode: "#line 2 \"convolution/lcm.hpp\"\n\n#line 2 \"number-theory/divisor-multiple-transform.hpp\"\
    \n\ntemplate <class T>\nvoid DivisorZetaTransform(vector<T>& a) {\n  if (a.empty())\
    \ return;\n  int n = a.size();\n  vector<bool> sieve(n, true);\n  for (int p =\
    \ 2; p < n; p++) {\n    if (sieve[p]) {\n      for (int k = 1; k * p < n; k++)\
    \ {\n        sieve[k * p] = false;\n        a[k * p] += a[k];\n      }\n    }\n\
    \  }\n}\n\ntemplate <class T>\nvoid DivisorMobiusTransform(vector<T>& a) {\n \
    \ if (a.empty()) return;\n  int n = a.size();\n  vector<bool> sieve(n, true);\n\
    \  for (int p = 2; p < n; p++) {\n    if (sieve[p]) {\n      for (int k = (n -\
    \ 1) / p; k > 0; k--) {\n        sieve[k * p] = false;\n        a[k * p] -= a[k];\n\
    \      }\n    }\n  }\n}\n\ntemplate <class T>\nvoid MultipleZetaTransform(vector<T>&\
    \ a) {\n  if (a.empty()) return;\n  int n = a.size();\n  vector<bool> sieve(n,\
    \ true);\n  for (int p = 2; p < n; p++) {\n    if (sieve[p]) {\n      for (int\
    \ k = (n - 1) / p; k > 0; k--) {\n        sieve[k * p] = false;\n        a[k]\
    \ += a[k * p];\n      }\n    }\n  }\n}\n\ntemplate <class T>\nvoid MultipleMobiusTransform(vector<T>&\
    \ a) {\n  if (a.empty()) return;\n  int n = a.size();\n  vector<bool> sieve(n,\
    \ true);\n  for (int p = 2; p < n; p++) {\n    if (sieve[p]) {\n      for (int\
    \ k = 1; k * p < n; k++) {\n        sieve[k * p] = false;\n        a[k] -= a[k\
    \ * p];\n      }\n    }\n  }\n}\n\n/**\n * @brief \u7D04\u6570\u30FB\u500D\u6570\
    \u5909\u63DB\n * @docs docs/number-theory/divisor-multiple-transform.md\n */\n\
    #line 4 \"convolution/lcm.hpp\"\n\ntemplate <class T>\nvector<T> LcmConvolution(vector<T>\
    \ a, vector<T> b) {\n  assert(a.size() == b.size());\n  if (a.empty()) return\
    \ {};\n  DivisorZetaTransform(a);\n  DivisorZetaTransform(b);\n  for (int i =\
    \ 0; i < a.size(); i++) a[i] *= b[i];\n  DivisorMobiusTransform(a);\n  return\
    \ a;\n}\n\n/**\n * @brief lcm \u7573\u307F\u8FBC\u307F\n * @docs docs/convolution/gcd-lcm.md\n\
    \ */\n"
  code: "#pragma once\n\n#include \"../number-theory/divisor-multiple-transform.hpp\"\
    \n\ntemplate <class T>\nvector<T> LcmConvolution(vector<T> a, vector<T> b) {\n\
    \  assert(a.size() == b.size());\n  if (a.empty()) return {};\n  DivisorZetaTransform(a);\n\
    \  DivisorZetaTransform(b);\n  for (int i = 0; i < a.size(); i++) a[i] *= b[i];\n\
    \  DivisorMobiusTransform(a);\n  return a;\n}\n\n/**\n * @brief lcm \u7573\u307F\
    \u8FBC\u307F\n * @docs docs/convolution/gcd-lcm.md\n */"
  dependsOn:
  - number-theory/divisor-multiple-transform.hpp
  isVerificationFile: false
  path: convolution/lcm.hpp
  requiredBy: []
  timestamp: '2025-10-10 17:35:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/convolution/LC_lcm_convolution.test.cpp
documentation_of: convolution/lcm.hpp
layout: document
redirect_from:
- /library/convolution/lcm.hpp
- /library/convolution/lcm.hpp.html
title: "lcm \u7573\u307F\u8FBC\u307F"
---
## GCD 畳み込み

長さ $\red{N+1}$ の vector $(a_0,a_1,\dots,a_N),(b_0,b_1,\dots,b_N)$ を受け取り，以下を満たす長さ $N+1$ の vector $(c_0,c_1,\dots,c_N)$ を返す．

- $c_0$ は未定義．
- $1\leq k\leq N$ に対し $c_k=\sum_{\gcd(i,j)=k}$．

$a$ を倍数ゼータ変換した列を $A$ とする．つまり $A_i=\sum_{i\mid j}a_j$ とする．$B,C$ も同様とする．

このとき $k\mid\gcd(i,j)\iff k\mid i\land k\mid j$ を用いると

$$\begin{align*}
C_k
&=\sum_{k\mid l}c_l\\
&=\sum_{k\mid\gcd(i,j)}a_ib_j\\
&=\sum_{k\mid i}\sum_{k\mid j}a_ib_j\\
&=A_kB_k
\end{align*}$$

となる．従って $c$ は $a,b$ を倍数ゼータ変換し，各点積をとって倍数メビウス変換すれば得られる．

## LCM 畳み込み

倍数ゼータ変換の代わりに約数ゼータ変換を用いれば LCM について畳み込みできる．

lcm の場合，$\operatorname{lcm}(i,j)\leq N$ とは限らない．