木を Heavy Light Decomposition によりパスへ分解する．

非空の連結な木を受け取り，各頂点を `vertices` 上の位置へ写す．辺は行き先 `to` を持つものとする．

- `HeavyLightDecomposition(g, root)`：木 `g` を根 `root` から構築する．
- `build(g, root)`：木 `g` から再構築する．
- `vertices[i]`：位置 $i$ に対応する頂点．
- `pos[x]`：頂点 $x$ の位置．
- `parent[x]`：頂点 $x$ の親．根では $-1$．
- `depth[x]`：根から頂点 $x$ までの辺数．
- `heavy_root[x]`：頂点 $x$ を含む heavy path の根．
- `path(x, y, f)`：頂点 $x$ から $y$ までのパスを heavy path ごとの区間へ分解する．

`path` はパス上の頂点を $x$ から $y$ へ進む順に，`f(l, r, rev)` を呼ぶ．`[l,r)` は `vertices` 上の半開区間であり，`rev = false` なら $l,l+1,\dots,r-1$，`rev = true` なら $r-1,r-2,\dots,l$ の順にたどる．端点 $x,y$ はともに含む．

構築は $O(N)$ 時間，空間計算量は $O(N)$．`path` が生成する区間数は $O(\log N)$．
