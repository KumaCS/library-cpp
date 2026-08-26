隣接リストによるグラフを表す．

各辺は行き先 `to` を持ち，重み付き辺はさらに `weight` を持つ．`GraphBase<E>` は辺型 `E` に対する共通の隣接リストを管理する．

- `EdgeUnweighted`：行き先のみを持つ辺．
- `GraphUnweighted(n)`：$n$ 頂点の重みなしグラフを構築する．
- `GraphUnweighted(g)`：`vector<vector<int>>` から変換する．
- `EdgeUnweightedIndexed`：行き先と辺番号を持つ辺．
- `GraphUnweightedIndexed(n)`：$n$ 頂点の辺番号付き重みなしグラフを構築する．
- `EdgeWeighted<T>`：行き先と型 `T` の重みを持つ辺．
- `GraphWeighted<T>(n)`：$n$ 頂点の重み付きグラフを構築する．
- `GraphWeighted<T>(g)`：`vector<vector<pair<int, T>>>` から変換する．
- `size()`：頂点数を返す．
- `operator[](x)`：頂点 $x$ から出る辺の列を返す．
- `add_edge(x, y, weight)`：無向辺 $xy$ を追加する．重みなしの場合は `weight` を省略する．
- `add_edge_directed(x, y, weight)`：有向辺 $x\to y$ を追加する．重みなしの場合は `weight` を省略する．
- `edge_count()`：`GraphUnweightedIndexed` に追加された辺数を返す．
- `GraphUnweightedToWeighted(g)`：重みなしグラフを，全辺の重みが $1$ の `GraphWeighted<int>` へ変換する．

`GraphUnweightedIndexed` の `add_edge` および `add_edge_directed` は，追加順の辺番号を返す．無向辺では両方向の辺が同じ辺番号を持つ．

辺追加は償却 $O(1)$ 時間，既存の隣接リストおよび重み付きグラフへの変換は $O(N+M)$ 時間．
