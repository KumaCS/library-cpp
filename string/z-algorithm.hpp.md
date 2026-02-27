---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/string/LC_zalgorithm.test.cpp
    title: verify/string/LC_zalgorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/string/z-algorithm.md
    document_title: Z-algorithm
    links: []
  bundledCode: "#line 2 \"string/z-algorithm.hpp\"\n\ntemplate <class T>\nvector<int>\
    \ ZAlgorithm(const T& a) {\n  int n = a.size();\n  vector<int> p(n);\n  p[0] =\
    \ n;\n  for (int i = 1, j = 0; i < n;) {\n    while (i + j < n && a[j] == a[i\
    \ + j]) j++;\n    p[i] = j;\n    if (j == 0) {\n      i++;\n      continue;\n\
    \    }\n    int k = 1;\n    while (i + k < n && k + p[k] < j) {\n      p[i + k]\
    \ = p[k];\n      k++;\n    }\n    i += k;\n    j -= k;\n  }\n  return p;\n}\n\
    /**\n * @brief Z-algorithm\n * @docs docs/string/z-algorithm.md\n */\n"
  code: "#pragma once\n\ntemplate <class T>\nvector<int> ZAlgorithm(const T& a) {\n\
    \  int n = a.size();\n  vector<int> p(n);\n  p[0] = n;\n  for (int i = 1, j =\
    \ 0; i < n;) {\n    while (i + j < n && a[j] == a[i + j]) j++;\n    p[i] = j;\n\
    \    if (j == 0) {\n      i++;\n      continue;\n    }\n    int k = 1;\n    while\
    \ (i + k < n && k + p[k] < j) {\n      p[i + k] = p[k];\n      k++;\n    }\n \
    \   i += k;\n    j -= k;\n  }\n  return p;\n}\n/**\n * @brief Z-algorithm\n *\
    \ @docs docs/string/z-algorithm.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: string/z-algorithm.hpp
  requiredBy: []
  timestamp: '2025-12-29 01:13:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/string/LC_zalgorithm.test.cpp
documentation_of: string/z-algorithm.hpp
layout: document
redirect_from:
- /library/string/z-algorithm.hpp
- /library/string/z-algorithm.hpp.html
title: Z-algorithm
---
文字列が与えられたとき，それ自身とその suffix それぞれとの最長共通接頭辞（LCP）の長さを列挙する．
計算量は入力文字列の長さに対する線形時間．

## 厳密に

以下 0-indexed とする．

二つの文字列の LCP の長さを $\operatorname{lcp}$ で表す．
また $s[l:r]$ で $s$ の $l$ 文字目から $r-1$ 文字目までの部分文字列を表すことにする．
文字列 $s$ が与えられたとき $p_i=\operatorname{lcp}(s,s[i:|s|])$ を $0\leq i\lt |s|$ について $O(|s|)$ 時間で列挙する．

## アルゴリズム

基本的に前から求めていくが，再利用できる情報は再利用する．

何も工夫せず $p_i$ を求めるには以下のようにすればよい：(⭐︎)．
```cpp
j = i;
while (s[j - i] == s[j]) j++;
p[i] = j - i;
```

$p_{i+1}$ の値を考える．

もし $p_1\geq p_i-1$ ならば

$$s[0:p_i-1]=s[1:p_i]=s[i+1:i+p_i]$$

が成り立つため $p_{i+1}\geq p_i-1$ である．特に (⭐︎) における `j = i;` の部分を $p_i$ について計算した後の値から始めてよい．

逆に $p_1\lt p_i-1$ ならば $p_{i+1}=p_1$ と値が定まる．
その後，$p_{i+2}$ について同様の議論を行うことができる．

従って次のようなコードで求められる．
```cpp
vector<int> ZAlgorithm(string s) {
  int n = s.size();
  vector<int> p(n);
  p[0] = n;
  for (int i = 1, j = i; i < n;) {
    if (j < i) j = i;
    while (j < n && s[j - i] == s[j]) j++;
    p[i] = j - i;
    if (p[i] == 0) {
      i++;
      continue;
    }
    int k = 1;
    while (i + k < n && k + p[k] < p[i]) {
      p[i + k] = p[k];
      k++;
    }
    i += k;
  }
  return p;
}
```

一つ目の `while` では `j` が，二つめの `while` では（間接的に）`i` が一回ループするごとに 1 ずつ増加し，どちらも `n` に達すると停止する．従って計算量は $O(|s|)$ と評価できる．