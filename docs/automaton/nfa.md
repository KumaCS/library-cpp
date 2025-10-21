## 概要

NFA $N=(Q,\Sigma,\Delta,s,F)$ は以下を満たすもの．

- 状態集合 $Q$：有限集合
- 文字集合 $\Sigma$：有限集合
- 遷移関数 $\Delta:Q\times\Sigma\to 2^Q$
- 開始状態 $s\in Q$
- 受理状態集合 $F\subseteq Q$

以下のようにして $\Delta:2^Q\times\Sigma\to 2^Q$ とみなす．

- $\forall X\subseteq Q,\forall c\in\Sigma,\Delta(X,c)=\bigcup_{q\in X}\Delta(q,c)$

$\hat{\Delta}:2^Q\times\Sigma^*\to 2^Q$ を以下のように定義する．

- $\forall X\subseteq Q,\hat{\Delta}(X,\epsilon)=X$
- $\forall X\subseteq Q,\forall x\in\Sigma^*,\forall c\in\Sigma,\hat{\Delta}(X,xc)=\Delta(\hat{\Delta}(X,x),c)$

$x\in\Sigma^*$ について，$\hat{\Delta}(s,x)\cap F\neq\emptyset$ ならば $x$ は $N$ によって **受理される**，そうでないならば **拒否される** という．

言語 $L$ について，任意の文字列 $x$ に対し $x\in L$ と $N$ が $x$ を受理することが同値であるとき，$L$ は $N$ によって受理されるという．

## DFA との関係

DFA は自然に NFA とみなせる．

逆に NFA は DFA で再現できる．状態集合を $2^Q$ と思えばよい．

従って DFA と NFA の表現力は等価である．

扱いやすさの面では DFA が，少ない状態数で表すには NFA が便利であるから使い分けが重要．