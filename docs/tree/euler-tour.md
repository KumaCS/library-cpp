根付き木を Euler Tour の行きがけ順に並べる．

非空の連結な木を受け取り，各辺は行き先 `to` を持つものとする．

- `EulerTour(g, root)`：木 `g` を根 `root` から走査し，`{in_time, out_time}` を返す．
- `in_time[x]`：頂点 $x$ を訪れる時刻．
- `out_time[x]`：頂点 $x$ の部分木を抜ける時刻．

頂点 $x$ の部分木は，行きがけ順の半開区間 $[in\_time[x],out\_time[x])$ に対応する．

時間計算量と空間計算量は $O(N)$．
