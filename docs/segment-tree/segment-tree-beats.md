Segment Tree Beats! のライブラリ．

簡単に言えば，現在見ているノードの情報だけでは作用が計算できない場合に子へ降りて再構築する lazy segment tree．

`SegmentTreeBeats<A>` として使う．`A` の形式と公開 API は `LazySegmentTree<A>` と同じだが，値モノイドの `value_type` は `bool fail` を持つ必要がある．

`A::mapping(f, x)` は，作用後の情報を `x` だけから計算できない場合に `fail = true` として返す．葉に対する作用は必ず成功しなければならない．

## 仕組み

通常の lazy segment tree では，作用 $f$ と値モノイドの演算 $\cdot$ に

$$
f(x\cdot y)=f(x)\cdot f(y)
$$

が成り立ち，集約した値へ直接作用できることを要求する．Segment Tree Beats ではこの計算が失敗することを許し，`fail` が立った節点の遅延値を子へ伝播して，左右の子から節点を再構築する．これにより基底の `LazySegmentTree` と問題固有の集約情報・作用を分離できる．

計算量は作用の失敗回数と，`op`，`mapping`，作用素の合成にかかる時間に依存する．これら 1 回の時間計算量の上界をそれぞれ $C_{\mathrm{op}}$，$C_{\mathrm{map}}$，$C_{\mathrm{comp}}$ とし，操作列全体で `mapping` が $K$ 回失敗するなら，通常の lazy segment tree の計算量に

$$
O\left(K(C_{\mathrm{op}}+C_{\mathrm{map}}+C_{\mathrm{comp}})\right)
$$

が加わる．利用時には，失敗のたびに値の種類数などが減少し，$K$ に十分小さい上界があることを確認する必要がある．

実装は以下の記事を参考にしている．

- [atcoder::lazy_segtree に1行書き足すだけの抽象化 Segment Tree Beats](https://rsm9.hatenablog.com/entry/2021/02/01/220408)
