#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t; cin >> t;
  rep(ti, t) {
    ll n, k, m; cin >> n >> k >> m;
    vector<ll> a(n);
    
  }
  return 0;
}

// とある長さkの部分の和がmで割り切れて、しかし長さk未満の部分の和は全てmで割り切れないようにする。
// mがkよりも大きい場合は、最初のk項を1をk-1個とm-(k-1)にして、