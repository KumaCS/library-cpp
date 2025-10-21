## 概要

DFA $M=(Q,\Sigma,\delta,s,F)$ は以下を満たすもの．

- 状態集合 $Q$：有限集合
- 文字集合 $\Sigma$：有限集合
- 遷移関数 $\delta:Q\times\Sigma\to Q$
- 開始状態 $s\in Q$
- 受理状態集合 $F\subseteq Q$

$\hat{\delta}:Q\times\Sigma^*\to Q$ を以下のように定義する．

- $\forall q\in Q,\hat{\delta}(q,\epsilon)=q$
- $\forall q\in Q,\forall x\in\Sigma^*,\forall c\in \Sigma,\hat{\delta}(q,xc)=\delta(\hat{\delta}(q,x),c)$

$x\in\Sigma^*$ について，$\hat{\delta}(s,x)\in F$ ならば $x$ は $M$ によって **受理される**，そうでないならば **拒否される** という．

言語 $L$ について，任意の文字列 $x$ に対し $x\in L$ と $M$ が $x$ を受理することが同値であるとき，$L$ は $M$ によって受理されるという．

自身を受理する DFA が存在する言語を正規言語と呼ぶ．

## 利用

状態集合 $Q$，文字集合 $\Sigma$ の DFA $M$ が与えられたとする．

このとき例えば $M$ によって受理される長さ $N$ 以下の文字列の総数を $O(2^{\lvert Q \rvert}\lvert \Sigma \rvert N)$ 時間で計算できる．

単純に bit dp すればよい．

遷移に重みがついているような場合でも問題ない．

## Myhill-Nerode の定理

言語 $L$ に対し，$\Sigma^*$ 上の同値関係 $\sim_L$ を以下で定める．

$$x \sim_L y \iff \forall z\in\Sigma^*(xz\in L\iff yz\in L)$$

Myhill-Nerode の定理の主張は以下の通り．

- $L$ が正規言語であることと $\sim_L$ の同値類が有限個であることは同値．
- $L$ が正規言語のとき，$L$ を受理する DFA の状態数の最小値は $\sim_L$ の同値類の個数に一致する．
- $L$ が正規言語のとき，$L$ を受理する状態数最小の DFA は一意．

## DFA の推定

規則的に定義された言語の場合，深い考察をせずに DFA が構築できる場合がある．

例題：ABC418-G

- 短い文字数では正しく判定できるような DFA を作る．
- DFA $M$ が$L$ を受理するならば $f(M)$ と $M$ が同型になるような変換 $f$ を用意し，実際に同型になったら終了．