直線集合を管理し，指定した座標での最小値を求めるデータ構造．
あらかじめ最小値を求める $x$ 座標をすべて渡す．

- `LiChaoTree<T>(xs, inf)`：問い合わせる座標列 `xs` および直線・線分が存在しない場合の値 `inf` を渡して初期化する．
- `add_line(a, b)`：直線 $y=ax+b$ を追加する．
- `add_segment(l, r, a, b)`：線分 $y=ax+b\ (x\in[l,r))$ を追加する．
- `get(x)`：座標 `x` での最小値を返す．`x` は初期化時の `xs` に含まれている必要がある．

最大値を求める場合は，係数と定数項を $-1$ 倍して追加し，答えも $-1$ 倍する．

## 計算量

初期化時の `xs` の長さを $N$ とする．

- `add_line(a, b)`：$O(\log N)$
- `add_segment(l, r, a, b)`：$O(\log^2 N)$
- `get(x)`：$O(\log N)$

## 資料

- [Li Chao Treeのメモ - smijake3](https://smijake3.hatenablog.com/entry/2018/06/16/144548)
