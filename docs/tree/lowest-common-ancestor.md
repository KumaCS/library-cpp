木上の Lowest Common Ancestor (LCA) を求めるデータ構造．

根付き木に対して Euler Tour と Sparse Table を構築し，2 頂点の最小共通祖先を求める．

- `LowestCommonAncestor(g, root)`：木 `g` を根 `root` から前処理する．辺は `to` を持つものとする．
- `build(g, root)`：木 `g` を根 `root` から再構築する．
- `lca(u, v)`：頂点 $u,v$ の LCA を返す．

前処理は $O(N\log N)$ 時間，クエリは $O(1)$ 時間．
