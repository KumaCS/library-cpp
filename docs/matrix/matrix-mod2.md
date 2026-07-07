$\mathbb{F}_2$ 上の行列．

各行を `DynamicBitset` で保持する．和と差は xor，行基本変形も xor で行う．

- `get(i, j)`: 成分を取得する．
- `set(i, j, v = true)`: 成分を設定する．
- `add(i, j, v = true)`: `v` が真なら成分を反転する．
- `id(n)`: 単位行列を返す．
- `operator+`, `operator-`: 成分ごとの xor を返す．
- `operator*`: Four Russians による行列積を返す．
- `multiply_sparse(r)`: 立っている bit に対応する行だけを xor する単純な行列積を返す．
- `multiply_four_russians(r, block = 0)`: ブロックごとの部分和表を使う行列積を返す．`block = 0` のときはサイズに応じて選ぶ．
- `pow(n)`: 正方行列の $n$ 乗を返す．
- `rank()`: 階数を返す．
- `det()`: 行列式を `0` または `1` で返す．
- `inv()`: 逆行列を `optional<MatrixMod2>` で返す．

`set_row(i, s)` と `row_string(i)` は，0/1 文字列形式の入力出力に使う．
