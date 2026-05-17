#pragma once

#include <bits/stdc++.h>
using namespace std;

struct Sieve {
  int n;
  vector<int> min_factor;
  vector<int> primes;

  explicit Sieve(int n_) : n(n_), min_factor(n + 1) {
    for (int i = 2; i <= n; i++) {
      if (min_factor[i] == 0) {
        min_factor[i] = i;
        primes.push_back(i);
      }
      for (int p : primes) {
        if (p > min_factor[i] || 1LL * i * p > n) break;
        min_factor[i * p] = p;
      }
    }
  }

  bool is_prime(int x) const {
    assert(0 <= x && x <= n);
    return x >= 2 && min_factor[x] == x;
  }

  vector<pair<int, int>> factorize(int x) const {
    assert(1 <= x && x <= n);
    vector<pair<int, int>> res;
    while (x > 1) {
      int p = min_factor[x];
      int e = 0;
      while (x % p == 0) x /= p, e++;
      res.push_back({p, e});
    }
    return res;
  }

  vector<int> divisors(int x) const {
    assert(1 <= x && x <= n);
    vector<int> ds = {1};
    for (auto [p, e] : factorize(x)) {
      int sz = (int)ds.size();
      int cur = 1;
      for (int k = 1; k <= e; k++) {
        cur *= p;
        for (int i = 0; i < sz; i++) ds.push_back(ds[i] * cur);
      }
    }
    sort(ds.begin(), ds.end());
    return ds;
  }
};

