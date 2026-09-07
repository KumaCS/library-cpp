必要になったノードだけを作る双対セグメント木．

`DynamicDualSegmentTree<M, I>` として使う．`M` はモノイド，`I` は座標の型で，既定は `long long`．

- `DynamicDualSegmentTree<M, I>(l, r)`：座標範囲 $[l,r)$ で初期化する．
- `apply(l, r, f)`：各 $i\in[l,r)$ に対して $A_i\leftarrow f\cdot A_i$ とする．
- `apply(p, f)`：点 $p$ に対して $A_p\leftarrow f\cdot A_p$ とする．
- `set(p, f)`：点 $p$ の値を `f` にする．
- `get(p)`：点 $p$ の値を返す．
- `node_count()`：作られたノード数を返す．

初期値はすべて `M::e()` とみなす．

## 計算量

座標範囲の幅を $N$ とする．

- `apply`, `set`, `get`：$O(\log N)$

空間は，更新によって実際に作られたノード数に比例する．

演算が非可換でも，新しい作用は左から掛かるものとして順序を保つ．
