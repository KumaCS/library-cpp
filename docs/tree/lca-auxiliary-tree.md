LCA による Auxiliary Tree (Virtual Tree)．

木上の頂点集合 $S$ が与えられたとき，$S$ とそれらの LCA だけからなる圧縮された木を構築する．
木 DP などで，指定された頂点集合に関係する部分だけを扱いたいときに使う．

`LowestCommonAncestor` を継承しているため，辺を追加して `build()` したあとに使う．

- `calc(vs, g)`：頂点集合 `vs` から Auxiliary Tree を作る．
  - 返り値の `first` は Auxiliary Tree の根．
  - 返り値の `second` は Auxiliary Tree に現れる頂点集合．
  - `g[v]` には Auxiliary Tree 上での子が入る．

`vs` は内部で Euler Tour 順に並び替えられ，必要な LCA が追加される．
