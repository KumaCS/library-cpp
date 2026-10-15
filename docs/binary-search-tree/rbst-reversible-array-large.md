初期列 $0,1,\dots,n-1$ を，連続する整数の区間に分割して管理する．

`RBSTReversibleArrayLarge<I>` は各区間を RBST の一つの node として保持する．
`I` は符号付き整数型とし，列の長さと添字が収まるものとする．

- `build(n)`：初期列を作り，root を返す．$n\geq 0$．空列の root は `nullptr`．
- `size(t)`：列の長さを返す．
- `get(t, k)`：$k$ 番目の値を返す．$0\leq k<\operatorname{size}(t)$．
- `reverse(t, l, r)`：半開区間 $[l,r)$ を反転する．空区間は何もしない．
- `split(t, k)`：先頭 $k$ 要素と残りに分割し，二つの root を返す．元の木は変更される．
- `merge(l, r)`：二つの列を連結し，root を返す．
- `enumerate(t)`：列を構成する区間の端点 `(lx, rx)` を順に返す．端点を含み，`lx > rx` は降順の区間を表す．

node 数を $B$ とする．計算量は `build`, `size` が $O(1)$ 時間，`enumerate` が $O(B)$ 時間，その他の操作が期待 $O(\log B)$ 時間．
`split` 一回で増える node 数は高々二つである．
node の確保は `new` で行い，木の解放は呼び出し側で行う．
