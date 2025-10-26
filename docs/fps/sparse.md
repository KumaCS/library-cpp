sparse な FPS についての各種 FPS 演算．
与えられた FPS で非ゼロの項が $K$ 項で，$N$ 次まで求めるとき $O(NK)$ 時間．

以下の等式から係数についての sparse な漸化式が得られる．

- inv : $fg=1$
- exp : $g'=f'g$
- log : $fg'=f'$
- pow : $fg'=Mf'g$
- sqrt : $f=g^2$