#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;

  vector<pair<ll, ll>> v(n);
  rep(i, n) cin >> v[i].second >> v[i].first;

  sort(v.begin(), v.end());

  vector<ll> ssum(n + 1);
  rep(i, n - 1) ssum[i + 1] += ssum[i];

  return 0;
}
