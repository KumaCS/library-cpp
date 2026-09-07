静的な木のパス上のモノイド積を求める．

`StaticTreePathProd<M, vertex, edge>` として使う．`M` はモノイド，`vertex` と `edge` はそれぞれ頂点と辺の値を積へ含めるかを表し，少なくとも一方を `true` とする．辺の値を使う場合，辺は `weight` を持つものとする．積の順序はパスを始点から終点へ進む順である．

可換モノイドでは `StaticTreePathProdCommutative<M, vertex, edge>` を使うことで，使用するメモリと定数倍を減らせる．

- `StaticTreePathProd(g, vertex_value, root)`：頂点の値を使う場合に，木 `g` と頂点列 `vertex_value` から構築する．
- `StaticTreePathProd(g, root)`：辺の値だけを使う場合に，木 `g` から構築する．
- `lca(x, y)`：根を `root` とした頂点 $x,y$ の最小共通祖先を返す．
- `prod(x, y)`：頂点 $x$ から $y$ までのパス上の積を返す．

構築は $O(N\log N)$ 時間，$O(N\log N)$ 空間．`lca` と `prod` は $O(\log N)$ 時間．
