#pragma once

template <class mint>
struct Factorial
{
    vector<mint> f, g, h;
    Factorial(int MAX = 0)
    {
        f.resize(1, mint{1});
        g.resize(1, mint{1});
        h.resize(1, mint{1});
        if (MAX > 0)
            extend(MAX + 1);
    }
    void extend(int m = -1)
    {
        int n = f.size();
        if (m == -1)
            m = n * 2;
        {
            int k = 1;
            while (k < m)
                k <<= 1;
            m = k;
        }
        if (n >= m)
            return;
        f.resize(m);
        g.resize(m);
        h.resize(m);
        for (int i = n; i < m; i++)
            f[i] = f[i - 1] * mint(i);
        g[m - 1] = f[m - 1].inv();
        h[m - 1] = g[m - 1] * f[m - 2];
        for (int i = m - 2; i >= n; i--)
        {
            g[i] = g[i + 1] * mint(i + 1);
            h[i] = g[i] * f[i - 1];
        }
    }
    mint fact(int i)
    {
        if (i < 0)
            return mint(0);
        while (i >= (int)f.size())
            extend();
        return f[i];
    }
    mint fact_inv(int i)
    {
        if (i < 0)
            return mint(0);
        while (i >= (int)g.size())
            extend();
        return g[i];
    }
    mint inv(int i)
    {
        if (i < 0)
            return -inv(-i);
        while (i >= (int)h.size())
            extend();
        return h[i];
    }
    mint binom(int n, int r)
    {
        if (n < 0 || n < r || r < 0)
            return mint(0);
        return fact(n) * fact_inv(n - r) * fact_inv(r);
    }
    mint multinom(const vector<int> &r)
    {
        int n = 0;
        for (auto &x : r)
        {
            if (x < 0)
                return mint(0);
            n += x;
        }
        mint res = fact(n);
        for (auto &x : r)
            res *= fact_inv(x);
        return res;
    }
    mint binom_naive(int n, int r)
    {
        if (n < 0 || n < r || r < 0)
            return mint(0);
        mint ret = mint(1);
        r = min(r, n - r);
        for (int i = 1; i <= r; ++i)
            ret *= inv(i) * (n--);
        return ret;
    }
    mint P(int n, int r)
    {
        if (n < 0 || n < r || r < 0)
            return mint(0);
        return fact(n) * fact_inv(n - r);
    }
    mint H(int n, int r)
    {
        if (n < 0 || r < 0)
            return mint(0);
        return r == 0 ? 1 : binom(n + r - 1, r);
    }
};
