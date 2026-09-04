木の頂点の値を更新し，パス上のモノイド積を求める．

`TreeVertexSetPathProd<M>` として使う．`M` はモノイドであり，その演算を $\circ$ とする．積の順序はパスを始点から終点へ進む順である．可換モノイドでは `TreeVertexSetPathProdCommutative<M>` を使うことで，使用するメモリと定数倍を減らせる．

- `TreeVertexSetPathProd(g, vertex_value, root)`：木 `g` と頂点列 `vertex_value` から構築する．
- `set(x, v)`：頂点 $x$ の値を $v$ に変更する．
- `apply(x, v)`：頂点 $x$ の値を $A_x\gets A_x\circ v$ に変更する．
- `prod(x, y)`：頂点 $x$ から $y$ までのパス上の積を返す．両端点を含む．

構築は $O(N)$ 時間，$O(N)$ 空間．`set` と `apply` は $O(\log N)$ 時間，`prod` は $O(\log^2 N)$ 時間．

## 資料

- [Library Checker: Vertex Set Path Composite](https://judge.yosupo.jp/problem/vertex_set_path_composite)
- [Library Checker: Vertex Add Path Sum](https://judge.yosupo.jp/problem/vertex_add_path_sum)
