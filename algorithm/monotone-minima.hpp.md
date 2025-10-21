---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/min-plus-convex.hpp
    title: "min-plus \u7573\u307F\u8FBC\u307F (convex)"
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
    _deprecated_at_docs: docs/algorithm/monotone-minima.md
    document_title: monotone minima
    links: []
  bundledCode: "#line 2 \"algorithm/monotone-minima.hpp\"\n\nvector<int> MonotoneMinima(int\
    \ n, int m, const function<bool(int, int, int)> &f) {\n  vector<int> res(n);\n\
    \  auto dfs = [&](auto rc, int il, int ir, int l, int r) -> void {\n    if (il\
    \ == ir) return;\n    int i = (il + ir) / 2;\n    int m = l;\n    for (int k =\
    \ l + 1; k < r; k++)\n      if (!f(i, m, k)) m = k;\n    res[i] = m;\n    rc(rc,\
    \ il, i, l, m + 1);\n    rc(rc, i + 1, ir, m, r);\n  };\n  dfs(dfs, 0, n, 0, m);\n\
    \  return res;\n}\n\n// m_i := argmin_j (A_{i,j}) \u304C\u5358\u8ABF\u5897\u52A0\
    \u3067\u3042\u308B\u3068\u304D\u306B m_i \u3092\u5217\u6319\u3059\u308B\ntemplate\
    \ <class T>\nvector<int> MonotoneMinima(int N, int M, const function<T(int, int)>\
    \ &A) {\n  const auto f = [&](int i, int j, int k) -> bool {\n    return A(i,\
    \ j) <= A(i, k);\n  };\n  return MonotoneMinima(N, M, f);\n}\n\n/**\n * @brief\
    \ monotone minima\n * @docs docs/algorithm/monotone-minima.md\n */\n"
  code: "#pragma once\n\nvector<int> MonotoneMinima(int n, int m, const function<bool(int,\
    \ int, int)> &f) {\n  vector<int> res(n);\n  auto dfs = [&](auto rc, int il, int\
    \ ir, int l, int r) -> void {\n    if (il == ir) return;\n    int i = (il + ir)\
    \ / 2;\n    int m = l;\n    for (int k = l + 1; k < r; k++)\n      if (!f(i, m,\
    \ k)) m = k;\n    res[i] = m;\n    rc(rc, il, i, l, m + 1);\n    rc(rc, i + 1,\
    \ ir, m, r);\n  };\n  dfs(dfs, 0, n, 0, m);\n  return res;\n}\n\n// m_i := argmin_j\
    \ (A_{i,j}) \u304C\u5358\u8ABF\u5897\u52A0\u3067\u3042\u308B\u3068\u304D\u306B\
    \ m_i \u3092\u5217\u6319\u3059\u308B\ntemplate <class T>\nvector<int> MonotoneMinima(int\
    \ N, int M, const function<T(int, int)> &A) {\n  const auto f = [&](int i, int\
    \ j, int k) -> bool {\n    return A(i, j) <= A(i, k);\n  };\n  return MonotoneMinima(N,\
    \ M, f);\n}\n\n/**\n * @brief monotone minima\n * @docs docs/algorithm/monotone-minima.md\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/monotone-minima.hpp
  requiredBy:
  - convolution/min-plus-convex.hpp
  timestamp: '2025-10-10 17:35:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/convolution/LC_min_plus_convolution_convex_convex.test.cpp
  - verify/convolution/LC_min_plus_convolution_convex_arbitrary.test.cpp
documentation_of: algorithm/monotone-minima.hpp
layout: document
redirect_from:
- /library/algorithm/monotone-minima.hpp
- /library/algorithm/monotone-minima.hpp.html
title: monotone minima
---
注意：以下では適当にタイブレークすることで $\operatorname{arg\,min}$ を集合ではなく添字を返す関数とみなす．

タイブレークは行によらないものならなんでもよい．

## (totally) monotone

$N\times M$ 行列 $A=(A_{i,j})$ について，

$$i \leq i' \implies \operatorname{arg\,min}_{j}A_{i,j} \leq \operatorname{arg\,min}_{j}A_{i',j}$$

が成り立つとき $A$ は **monotone** であるという．

また $A$ の任意の部分行列が monotone であるとき，$A$ は **totally monotone** であるという．

## monotone minima

$A$ は monotone とする．
$i=1,2,\dots,N$ に対して $\operatorname{arg\,min}_{j}A_{i,j}$ を $O(M\log N)$ 時間で列挙できる．

まず $i_m\coloneqq\lfloor N/2\rfloor$ 行目の argmin $j_m$ を線形探索により $O(M)$ 時間で発見できる．
その後，$[1,i,m-1]\times[1,j_m]$ と $[i_m+1,N]\times[j_m,M]$ の範囲それぞれについて再帰的に計算する．

$N\times M$ 行列を陽に持つとそれだけで $O(NM)$ 時間かかるので，実際には以下のようなものから計算することが多い．

- $(i,j)$ 成分と $(i,k)$ 成分を比較した結果を返す関数．
- $(i,j)$ 成分を返す関数．

## 応用: min-plus convolution

monotone minima を用いることで min-plus convolution が計算できる．

詳細は該当ライブラリのページを参照．

## 関連

(totally) monotone 性と関係している性質として Monge 性がある．

参照：[[Monge まとめ①] Monge 性とは？](https://hackmd.io/@tatyam-prime/monge1)