## 使い方

以下の問題を $O(pq(p+q)\log m)$ 時間で解く．

> 整数 $l,r,m,a,b\ (m\neq 0)$ および非負整数 $p,q$ に対し以下の値を求めよ：
> $$f_{p,q}(l,r,m,a,b)=\sum_{i=l}^{r-1}i^p\left\lfloor\frac{ai+b}{m}\right\rfloor^q$$

型 `U` は $an+b$ が正しく計算できる必要がある．
