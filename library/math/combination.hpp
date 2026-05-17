#pragma once

#include <bits/stdc++.h>
using namespace std;

template <class Mint>
struct Combination {
    vector<Mint> fact, ifact;

    Combination() : fact(1, 1), ifact(1, 1) {}
    explicit Combination(int n) : Combination() { init(n); }

    void init(int n) {
        int old = (int)fact.size();
        if (old > n) return;
        fact.resize(n + 1);
        ifact.resize(n + 1);
        for (int i = old; i <= n; i++) fact[i] = fact[i - 1] * i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= old; i--) ifact[i - 1] = ifact[i] * i;
    }

    Mint fac(int n) {
        init(n);
        return fact[n];
    }

    Mint invfac(int n) {
        init(n);
        return ifact[n];
    }

    Mint perm(int n, int r) {
        if (r < 0 || r > n) return 0;
        init(n);
        return fact[n] * ifact[n - r];
    }

    Mint comb(int n, int r) {
        if (r < 0 || r > n) return 0;
        init(n);
        return fact[n] * ifact[r] * ifact[n - r];
    }
};

