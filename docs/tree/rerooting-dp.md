全方位木 DP を行う．

各頂点を根としたときの木 DP の値をすべて求める．森にも使える．
DP の型 `T` は可換モノイドであることを仮定する．

- `ReRootingDP<T, V, E, merge, add_edge, add_vertex>(n, id)`：$n$ 頂点で初期化する．
  - `id`：`T` の単位元．
  - `merge(x, y)`：部分木 DP の併合．
  - `add_edge(x, e)`：DP 値 `x` に辺データ `e` を追加する．
  - `add_vertex(x, v)`：DP 値 `x` に頂点データ `v` を追加する．
- `set_vertex(u, data)`：頂点 $u$ のデータを設定する．
- `add_edge(u, v, data)`：無向辺 $uv$ を追加し，辺 ID を返す．
- `add_edge(u, v, data, rdata)`：$u \to v$ 方向の辺データを `data`，$v \to u$ 方向の辺データを `rdata` として無向辺を追加し，辺 ID を返す．
- `calc()`：DP を計算し，各頂点を根とした答えを返す．
- `dp[i]`：`calc()` 後，頂点 $i$ を根とした答えを返す．
- `dp.edge_subtree(eid, side)`：`calc()` 後，辺 `eid` を切った片側の DP 値を返す．`side = 0` なら `add_edge` の第 1 引数側，`side = 1` なら第 2 引数側．

時間計算量は，`merge`，`add_edge`，`add_vertex` が $O(1)$ のとき `calc()` が $O(N)$，`edge_subtree` が $O(1)$．
