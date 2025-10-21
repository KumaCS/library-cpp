---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/monotone-minima.hpp
    title: monotone minima
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/convolution/LC_min_plus_convolution_convex_arbitrary.test.cpp
    title: verify/convolution/LC_min_plus_convolution_convex_arbitrary.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/convolution/LC_min_plus_convolution_convex_convex.test.cpp
    title: verify/convolution/LC_min_plus_convolution_convex_convex.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/convolution/min-plus-convex.md
    document_title: "min-plus \u7573\u307F\u8FBC\u307F (convex)"
    links: []
  bundledCode: "#line 2 \"convolution/min-plus-convex.hpp\"\n\n#line 2 \"algorithm/monotone-minima.hpp\"\
    \n\nvector<int> MonotoneMinima(int n, int m, const function<bool(int, int, int)>\
    \ &f) {\n  vector<int> res(n);\n  auto dfs = [&](auto rc, int il, int ir, int\
    \ l, int r) -> void {\n    if (il == ir) return;\n    int i = (il + ir) / 2;\n\
    \    int m = l;\n    for (int k = l + 1; k < r; k++)\n      if (!f(i, m, k)) m\
    \ = k;\n    res[i] = m;\n    rc(rc, il, i, l, m + 1);\n    rc(rc, i + 1, ir, m,\
    \ r);\n  };\n  dfs(dfs, 0, n, 0, m);\n  return res;\n}\n\n// m_i := argmin_j (A_{i,j})\
    \ \u304C\u5358\u8ABF\u5897\u52A0\u3067\u3042\u308B\u3068\u304D\u306B m_i \u3092\
    \u5217\u6319\u3059\u308B\ntemplate <class T>\nvector<int> MonotoneMinima(int N,\
    \ int M, const function<T(int, int)> &A) {\n  const auto f = [&](int i, int j,\
    \ int k) -> bool {\n    return A(i, j) <= A(i, k);\n  };\n  return MonotoneMinima(N,\
    \ M, f);\n}\n\n/**\n * @brief monotone minima\n * @docs docs/algorithm/monotone-minima.md\n\
    \ */\n#line 4 \"convolution/min-plus-convex.hpp\"\n\n// a : \u4E0B\u306B\u51F8\
    , b : \u81EA\u7531\ntemplate <class T>\nvector<T> MinPlusConvolutionConvexArbitrary(const\
    \ vector<T> &a, const vector<T> &b) {\n  if (a.empty() || b.empty()) return {};\n\
    \  int n = a.size(), m = b.size();\n  auto argmin = MonotoneMinima(n + m - 1,\
    \ m, [&](int i, int j, int k) {\n    if (i < k) return true;\n    if (i - j >=\
    \ n) return false;\n    return a[i - j] + b[j] <= a[i - k] + b[k];\n  });\n  vector<T>\
    \ c(n + m - 1);\n  for (int i = 0; i < n + m - 1; i++) {\n    int j = argmin[i];\n\
    \    c[i] = a[i - j] + b[j];\n  }\n  return c;\n}\n\n// a,b : \u4E0B\u306B\u51F8\
    \ntemplate <class T>\nvector<T> MinPlusConvolutionConvexConvex(const vector<T>\
    \ &a, const vector<T> &b) {\n  if (a.empty() || b.empty()) return {};\n  int n\
    \ = a.size(), m = b.size();\n  vector<T> c(n + m - 1);\n  c[0] = a[0] + b[0];\n\
    \  for (int k = 0, i = 0; k < n + m - 2; k++) {\n    int j = k - i;\n    if (j\
    \ == m - 1 || (i < n - 1 && a[i + 1] + b[j] < a[i] + b[j + 1])) {\n      c[k +\
    \ 1] = a[++i] + b[j];\n    } else {\n      c[k + 1] = a[i] + b[++j];\n    }\n\
    \  }\n  return c;\n}\n\n/**\n * @brief min-plus \u7573\u307F\u8FBC\u307F (convex)\n\
    \ * @docs docs/convolution/min-plus-convex.md\n */\n"
  code: "#pragma once\n\n#include \"../algorithm/monotone-minima.hpp\"\n\n// a : \u4E0B\
    \u306B\u51F8, b : \u81EA\u7531\ntemplate <class T>\nvector<T> MinPlusConvolutionConvexArbitrary(const\
    \ vector<T> &a, const vector<T> &b) {\n  if (a.empty() || b.empty()) return {};\n\
    \  int n = a.size(), m = b.size();\n  auto argmin = MonotoneMinima(n + m - 1,\
    \ m, [&](int i, int j, int k) {\n    if (i < k) return true;\n    if (i - j >=\
    \ n) return false;\n    return a[i - j] + b[j] <= a[i - k] + b[k];\n  });\n  vector<T>\
    \ c(n + m - 1);\n  for (int i = 0; i < n + m - 1; i++) {\n    int j = argmin[i];\n\
    \    c[i] = a[i - j] + b[j];\n  }\n  return c;\n}\n\n// a,b : \u4E0B\u306B\u51F8\
    \ntemplate <class T>\nvector<T> MinPlusConvolutionConvexConvex(const vector<T>\
    \ &a, const vector<T> &b) {\n  if (a.empty() || b.empty()) return {};\n  int n\
    \ = a.size(), m = b.size();\n  vector<T> c(n + m - 1);\n  c[0] = a[0] + b[0];\n\
    \  for (int k = 0, i = 0; k < n + m - 2; k++) {\n    int j = k - i;\n    if (j\
    \ == m - 1 || (i < n - 1 && a[i + 1] + b[j] < a[i] + b[j + 1])) {\n      c[k +\
    \ 1] = a[++i] + b[j];\n    } else {\n      c[k + 1] = a[i] + b[++j];\n    }\n\
    \  }\n  return c;\n}\n\n/**\n * @brief min-plus \u7573\u307F\u8FBC\u307F (convex)\n\
    \ * @docs docs/convolution/min-plus-convex.md\n */"
  dependsOn:
  - algorithm/monotone-minima.hpp
  isVerificationFile: false
  path: convolution/min-plus-convex.hpp
  requiredBy: []
  timestamp: '2025-10-10 17:35:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/convolution/LC_min_plus_convolution_convex_convex.test.cpp
  - verify/convolution/LC_min_plus_convolution_convex_arbitrary.test.cpp
documentation_of: convolution/min-plus-convex.hpp
layout: document
redirect_from:
- /library/convolution/min-plus-convex.hpp
- /library/convolution/min-plus-convex.hpp.html
title: "min-plus \u7573\u307F\u8FBC\u307F (convex)"
---
二つの数列 $(a_0,\dots,a_{n-1}),(b_0,\dots,b_{m-1})$ から以下を満たす数列 $(c_0,\dots,c_{n+m-2})$ を計算する．

$$c_k=\min_{i+j=k}(a_i+b_j)$$

ただし $a$ は下に凸，すなわち $a_i-a_{i-1}\leq a_{i+1}-a_i$ を満たす必要がある．

- monotone minima を用いる場合 $O((n+m)\log(n+m))$ 時間．
- SMAWK を用いるか $b$ も凸な場合 $O(n+m)$ 時間．

monotone minima と SMAWK は実用上だと定数倍の問題で大差ないという話もある．

## convex-arbitrary

$A_{i,j}=a_{i-j}+b_j$ として $(n+m-1)\times m$ 行列 $A$ を考える．
ただし値が存在しない場所は $\infty$ で埋める．

ある $i$ および $k\lt l$ に対し $A_{i,k}\gt A_{i,l}$ であると仮定する．
このとき任意の $j\gt i$ について

$$A_{j,k}-A_{j,l}=a_{j-k}-a_{j-l}+b_k-b_l\geq a_{i-k}-a_{i-l}+b_k-b_l=A_{i,k}-A_{i,l}\gt 0$$

より $A_{j,k}\gt A_{j,l}$ である．

従って $A$ は monotone であり，monotone minima や SMAWK によって列毎の argmin が列挙できる．
argmin が求まれば $c$ も容易に計算できる．

## convex-convex

上の議論をまとめれば $f(k)=\min\operatorname{arg\,min}_{i}(a_{k-i}+b_i)$ は $k$ について単調増加である．

$a,b$ を入れ替えても同じことがいえることから，$f(k+1)-f(k)\in\{0,1\}$ が得られる．

従って以下の流れで $c$ が求められる．

- $(i,j)=(0,0)$ から始めて，$i+j\leq n+m-2$ の間以下を繰り返す．
  - $c_{i+j}=a_i+b_j$ とする．
  - $a_{i+1}+b_{j} \lt a_{i}+b_{j+1}$ ならば $(i,j)\to(i+1,j)$，そうでないならば $(i,j)\to(i,j+1)$ へ遷移する．
