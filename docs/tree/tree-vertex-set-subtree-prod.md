根付き木の頂点の値を更新し，部分木上のモノイド積を求める．

`TreeVertexSetSubtreeProd<M>` として使う．`M` はモノイドであり，その演算を $\circ$ とする．部分木の積は Euler Tour の行きがけ順に取る．

- `TreeVertexSetSubtreeProd(g, vertex_value, root)`：木 `g` を `root` を根として，頂点列 `vertex_value` から構築する．
- `set(x, v)`：頂点 $x$ の値を $v$ に変更する．
- `apply(x, v)`：頂点 $x$ の値を $A_x\gets A_x\circ v$ に変更する．
- `prod(x)`：頂点 $x$ の部分木に含まれる頂点の積を返す．

構築は $O(N)$ 時間，$O(N)$ 空間．各操作は $O(\log N)$ 時間．

## 資料

- [Library Checker: Vertex Add Subtree Sum](https://judge.yosupo.jp/problem/vertex_add_subtree_sum)
