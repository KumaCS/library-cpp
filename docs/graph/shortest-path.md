グラフ上の単一始点最短路を求める．

辺は行き先 `to` を持ち，重み付きアルゴリズムではさらに `weight` を持つものとする．到達不能な頂点の距離は `nullopt` で表す．

- `ShortestPath::BFS(g, root)`：重みなしグラフ上の距離を求める．$O(N+M)$ 時間．
- `ShortestPath::BFSWithPrev(g, root)`：距離と各頂点の直前の頂点を求める．$O(N+M)$ 時間．
- `ShortestPath::ZeroOneBFS<T>(g, root)`：辺重みが $0$ または $1$ のグラフ上の距離を求める．$O(N+M)$ 時間．
- `ShortestPath::ZeroOneBFSWithPrev<T>(g, root)`：01-BFS により距離と各頂点の直前の頂点を求める．$O(N+M)$ 時間．
- `ShortestPath::Dijkstra(g, zero, root)`：非負辺重みグラフ上の距離を求める．`zero` は距離型の加法単位元．$O((N+M)\log N)$ 時間．
- `ShortestPath::DijkstraWithPrev(g, zero, root)`：Dijkstra 法により距離と各頂点の直前の頂点を求める．$O((N+M)\log N)$ 時間．
- `ShortestPath::EnumeratePath(prev, goal)`：`prev` をたどり，始点から `goal` までの頂点列を返す．

`WithPrev` の返り値は `(dist, prev)` であり，始点および到達不能な頂点の `prev` は `nullopt` となる．`EnumeratePath` は `goal` が到達可能であることを確認してから使う．
