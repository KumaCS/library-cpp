最大流問題を解く．

push-relabel algorithm により $n$ 頂点 $m$ 辺のとき $O(n^2m)$ 時間．

## push-relabel algorithm (概要)

- preflow とは flow において各頂点で (流入量)≥(流出量) であることを許したもの．
  - $\sum_{v\in V}f(v,u)-\sum_{v\in V}f(u,v)\geq 0$
- 頂点 $u$ の excess flow とは $e(u)=\sum_{v\in V}f(v,u)-\sum_{v\in V}f(u,v)$ のこと．
- 頂点 $u$ が overflow しているとは $e(u)\gt 0$ であること．
- height function $h:V\to\mathbb{N}$ は $h(s)=|V|,h(t)=0$ およびすべての残余辺 $(u,v)\in E_f$ に対し $h(u)\leq h(v)+1$ を満たすもの．

preflow を更新する push，height function を更新する relabel を組み合わせたアルゴリズム．

### push

以下の条件を満たす残余辺 $(u,v)$ についての操作．

- $h(u)=h(v)+1$
- $c_f(u,v)\gt 0$
- $e(u)\gt 0$

```
Push(u, v):
  df = min(e[u], c_f[u, v])
  if (u, v) in E:
    f[u, v] += df
  else:
    f[v, u] -= df
  e[u] -= df
  e[v] += df
```

push 後に $c_f(u,v)=0$ となる push を saturating push と呼ぶ．

### relabel

$e(u)\gt 0$ かつ $(u,\forall v)\in E_f,h(u)\leq h(v)$ なる $u$ に対する操作．

```
Relabel(u):
  h[u] = 1 + min(h[v] for (u, v) in E_f)
```

### 基本アルゴリズム

以下のアルゴリズムで最大フローが求められる．

```
GenericPushRelabel(G):
  for v in V:
    h[v] = 0
    e[v] = 0
  for (u, v) in E:
    f[u, v] = 0
  h(s) = |V|
  for v in G[s]:
    f[s, v] = c(s, v)
    e[v] = c(s, v)
    e[s] -= c(s, v)
  while (push または relabel ができる):
    (push または relabel を任意に選んで行う)
```

最大フローを返すこと，また停止して時間計算量が $O(|V|^2|E|)$ であることの証明は省略． 

### push/relabel の操作順

`GenericPushRelabel` では push/relabel を行う順序に自由度がある．

順序を適切に決めることで $O(|V|^3)$ 時間や $O(|V|^2\sqrt{|E|})$ 時間などになる．

## 資料

- Cormen, T.H., Leiserson, C.E., Rivest, R.L. and Stein, C. (2009) Introduction to Algorithms. The MIT Press. https://mitpress.mit.edu/9780262046305/introduction-to-algorithms/
- [Push-Relabel による最大フローアルゴリズム - 宇宙ツイッタラーXの憂鬱](https://kenkoooo.hatenablog.com/entry/2016/12/22/143638)