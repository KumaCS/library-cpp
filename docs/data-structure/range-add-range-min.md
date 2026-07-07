列 $A=(A_0,A_1,\dots,A_{N-1})$ を管理し，区間加算と区間最小値取得を行うデータ構造．

- `RangeAddRangeMin<T>(n)`：長さ $n$，全要素 $0$ で初期化する．
- `RangeAddRangeMin<T>(a)`：列 `a` で初期化する．
- `add(l, r, x)`：各 $i\in[l,r)$ について $A_i\leftarrow A_i+x$ とする．
- `min(l, r)` / `prod(l, r)`：$\min_{i\in[l,r)} A_i$ を返す．
- `get(p)`：$A_p$ を返す．
- `all_min()` / `all_prod()`：列全体の最小値を返す．

`min(l, r)` は空でない区間を要求する．

## 計算量

- `add(l, r, x)`：$O(\log N)$
- `min(l, r)`：$O(\log N)$
- `get(p)`：$O(\log N)$
- `all_min()`：$O(1)$

空間計算量は $N\geq 1$ で `T` を $N$ 個分．

## 仕組み

参考：[省メモリな区間 add 区間 min - noshi91のメモ](https://noshi91.hatenablog.com/entry/2023/11/03/183702)

全体の最小値を 1 個持ち，各内部ノードには「左部分木の最小値 $-$ 右部分木の最小値」だけを持つ．

区間加算では，再帰関数が「現在見ているノードの区間最小値の増分」を返す．
左右の増分が分かれば，保持している左右最小値差を更新でき，親の区間最小値の増分も計算できる．

このため通常の lazy segment tree と違い，各ノードに最小値と遅延値を両方持つ必要がない．
