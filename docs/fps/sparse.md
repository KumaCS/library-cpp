sparse な FPS についての各種 FPS 演算．
与えられた FPS で非ゼロの項が $K$ 項で，$N$ 次まで求めるとき $O(NK)$ 時間．

FPS は `map<int, mint>` で，次数と非ゼロ係数の組として渡す．

- `FPSSparse::inv(f, n)`：$f^{-1}$ を $n$ 項求める．
- `FPSSparse::exp(f, n)`：$\exp(f)$ を $n$ 項求める．
- `FPSSparse::log(f, n)`：$\log(f)$ を $n$ 項求める．
- `FPSSparse::pow(f, m, n)`：$f^m$ を $n$ 項求める．
- `FPSSparse::sqrt(f, n)`：$f$ の平方根を $n$ 項求める．存在しない場合は空列を返す．

以下の等式から係数についての sparse な漸化式が得られる．

- inv : $fg=1$
- exp : $g'=f'g$
- log : $fg'=f'$
- pow : $fg'=Mf'g$
- sqrt : $f=g^2$
