動的な Li Chao Tree．
問い合わせ座標を先読みせず，コンストラクタで指定した整数区間 $[xl,xr)$ 上で動く．

- `DynamicLiChaoTree<T>(xl, xr, inf)`：扱う座標範囲 $[xl,xr)$ および直線・線分が存在しない場合の値 `inf` を渡して初期化する．
- `add_line(a, b)`：直線 $y=ax+b$ を追加する．
- `add_segment(l, r, a, b)`：線分 $y=ax+b\ (x\in[l,r))$ を追加する．
- `get(x)` / `query(x)`：座標 `x` での最小値を返す．`x` は $[xl,xr)$ に含まれている必要がある．
- `node_count()`：内部で確保したノード数を返す．

最大値を求める場合は，係数と定数項を $-1$ 倍して追加し，答えも $-1$ 倍する．

## 計算量

$V=xr-xl$ とする．

- `add_line(a, b)`：$O(\log V)$
- `add_segment(l, r, a, b)`：$O(\log^2 V)$
- `get(x)` / `query(x)`：$O(\log V)$

空間計算量は確保したノード数に比例する．

## 資料

- [Dynamic-Li-Chao-Tree - Luzhiled's Library](https://ei1333.github.io/library/structure/convex-hull-trick/dynamic-li-chao-tree.hpp.html)
