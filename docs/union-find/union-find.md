$n$ 頂点 $0$ 辺のグラフに対する以下のクエリを処理する．$\alpha$ はアッカーマン関数の逆関数．

- `find(v)`：頂点 $v$ を含む連結成分の代表頂点を返す．$O(\alpha(n))$ 時間．
- `size(v)`：頂点 $v$ を含む連結成分の頂点数を返す．$O(\alpha(n))$ 時間．
- `same(u, v)`：頂点 $u,v$ が同じ連結成分に含まれるかを返す．$O(\alpha(n))$ 時間．
- `unite(u, v)`：辺 $uv$ を追加する．$O(\alpha(n))$ 時間．
  - `unite(u, v, f)` で連結成分マージ時に $f$ を呼び出す．
- `groups()`：連結成分を列挙する．$O(n)$ 時間．

## アルゴリズム

`find` および `unite` が実装できれば他も難しくない．

根付き木として考える．
各頂点の親を示す長さ $n$ の列 $(p_0,\dots,p_{n-1})$ を管理する．
$p_i=i$ ならば頂点 $i$ は根であり，はじめ全ての $i$ に対し $p_i=i$ である．

`find`, `unite` は naive には以下のように実装できる．

```
def find(v):
  if p[v] == v: return v
  return find(p[v])
def unite(u, v):
  u = find(u)
  v = find(v)
  p[v] = u
```

## 計算量

https://37zigen.com/union-find-complexity-1/

毎回素直に根まで辿り，unite では一方の根をもう一方の根に繋ぐ．
これでは worst $\Theta(n)$ 時間である．

計算量を改善する手法がある．

## path compression

path compression では `find` を以下のようにする．
```
def find(v):
  if p[v] == v: return v
  return p[v] = find(p[v])
```
一度再帰で通った部分を圧縮している．

このとき各操作がならし $O(\log n)$ 時間になる．

<details>

証明：頂点 $v$ を根とする部分木の大きさを $s_v$ とし，ポテンシャル $\Phi=2\sum_{v}\log_2 s_v$ を考える．
はじめ $\Phi=0$ である．

`unite` については `find` での変化を除くと，ポテンシャルは連結性が変化するときにのみ高々 $2\log_2 n$ だけ増加し，この増加は高々 $n$ 回．

`find` の再帰において頂点 $v_0,v_1,\dots,v_k$ を順に通ったとき（$v_k$ が根である），$1\leq i\leq k-1$ について $s_{v_i} \to s_{v_i}-s_{v_{i-1}}$ となる．
ポテンシャルの差分は
$$\begin{align*}
2\sum_{i=1}^{k-1}\left(\log_2(s_{v_i}-s_{v_{i-1}})-\log_2 s_{v_i}\right)
&=2\sum_{i=1}^{k-1}\log_2\left(1-\dfrac{s_{v_{i-1}}}{s_{v_i}}\right)\\
&\leq-2\sum_{i=1}^{k-1}\dfrac{s_{v_{i-1}}}{s_{v_i}}\\
&\leq \log_2 n+1-k
\end{align*}$$
と評価できる．

- 一つ目の不等式は $\log(1-x)\leq -x$ より．
- 二つ目の不等式は $s_{v_i}/s_{v_{i-1}}\geq 2$ なる $i$ が高々 $\log_2 n$ 個であることより．

従って `find` を $q$ 回行ったとき $\Phi\geq 0$ より $\sum k=O((n+q)\log n)$ と評価できる．

</details>

## union by size (rank)

union by size では `unite` を以下のようにする．
```
def unite(u, v):
  u = find(u)
  v = find(v)
  if size(u) < size(v): swap(u, v)
  p[v] = u
```
部分木のサイズが小さい方を大きい方の子とする（いわゆるマージテク）．

このとき各操作が $O(\log n)$ 時間になる．

<details>

証明：頂点 $p,c$ で $p$ が $c$ の親であるとき $\operatorname{size}(p)\geq 2\operatorname{size}(c)$ が成り立つから，常に各頂点と根の距離は高々 $\log_2 n$ であり，`find` は $O(\log n)$ 時間で行える．

</details>

各頂点の rank を (path compression しない状態での) その頂点を根とする部分木の高さとする．
union by rank は union by size で size を用いている部分を rank に置き換えたもの．

## 組み合わせ

path compression と union by size (rank) を組み合わせるとさらにオーダーが改善し，ならし $O(\alpha(n))$ 時間になることが知られている．

ここで $\alpha$ はアッカーマン関数の逆関数で，現実的な $n$ の範囲で $\alpha(n)\leq 5$．

参考
- [α(m, n) のお勉強 + 定数時間 decremental neighbor query - えびちゃんの日記](https://rsk0315.hatenablog.com/entry/2022/05/04/215704)