座標圧縮をする．

- 圧縮したい値を `push_back` などで追加する．
- `build()`：追加した値を sort し，重複を除く．
- `operator[]`：圧縮後の番号から元の値を取得する．
- `find(v)`：値 `v` の圧縮後の index を返す．存在しない場合も lower bound の位置を返す．

`Compress<T>` は `vector<T>` を継承しているため，圧縮後の値集合そのものとして扱える．
