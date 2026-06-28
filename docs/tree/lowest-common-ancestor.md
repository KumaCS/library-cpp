木上の Lowest Common Ancestor (LCA) を求めるデータ構造．

根付き木に対して Euler Tour と Sparse Table を構築し，2 頂点の最小共通祖先を求める．

- `LowestCommonAncestor(n, root)`：$n$ 頂点，根 `root` の木として初期化する．
- `add_edge(u, v)`：無向辺 $uv$ を追加する．
- `build()`：前処理を行う．
- `lca(u, v)`：頂点 $u,v$ の LCA を返す．

コンストラクタに隣接リストを渡した場合は自動で `build()` される．
前処理は $O(N\log N)$ 時間，クエリは $O(1)$ 時間．
