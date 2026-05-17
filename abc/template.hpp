#pragma once
// clang-format off
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
const ll MOD = 998244353;

template<class T> inline bool chmax(T& a, T b){if(a<b){a=b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b; return true;} return false;}

struct UnionFind {
  vector<ll> par;
  UnionFind(ll n): par(n){iota(par.begin(), par.end(), 0);}
  ll root(ll x){return par[x]==x ? x : par[x]=root(par[x]);}
  void unite(ll x, ll y){x=root(x), y=root(y); if(x!=y) par[x]=y;}
  bool same(ll x, ll y){return root(x)==root(y);}
};

ll powmod(ll a, ll n, ll mod){ll res=1; a%=mod; while(n){if(n&1) res=res*a%mod; a=a*a%mod; n>>=1;} return res;}
ll gyakugen(ll a, ll mod){return powmod(a, mod-2, mod);}
ll kaizyo(ll n, ll mod){ll res=1; for(ll i=1;i<=n;i++) res=res*i%mod; return res;}
ll conbi(ll n, ll m){return (kaizyo(n, MOD) * gyakugen((kaizyo(m, MOD) * kaizyo((n - m), MOD)), MOD));}
template<class Tx,class Ty>Tx dup(Tx x, Ty y){return (x+y-1)/y;}
// clang-format on

// 最大値の最小値系
int main() {
  auto ok = [&](ll x) -> bool {
  };

  ll l = -1, r = INF;
  while (r - l > 1) {
    ll m = l + (r - l) / 2;
    if (ok(m) == true)
      r = m;
    else
      l = m;
  }

  cout << r << '\n';
}