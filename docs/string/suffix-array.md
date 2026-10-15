列の suffix を辞書順に並べ，その開始位置を返す．

返り値 `sa` は長さ $n$ の列であり，`s[sa[i]:]` が辞書順になっている．空列では空の列を返す．

- `SuffixArray(s, upper)`：`vector<int>` に対して SA-IS を用いる．各要素は $0\leq s_i\leq\mathrm{upper}$．
- `SuffixArray(s)`：`vector<T>` を座標圧縮して処理する．`T` は比較可能な型．
- `SuffixArray(s)`：`string` に対して処理する．

計算量は `upper` を指定した `vector<int>` が $O(n+\mathrm{upper})$ 時間，`vector<T>` が $O(n\log n)$ 時間，`string` が $O(n)$ 時間．
