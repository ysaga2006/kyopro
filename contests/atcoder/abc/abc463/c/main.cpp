#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

const ll INF = 10000000000000000;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;
  vector<pair<ll, ll>> v(n);

  rep(i, n) cin >> v[i].second >> v[i].first;
  sort(v.begin(), v.end());

  vector<ll> tallest(n);
  tallest[n - 1] = v[n - 1].second;

  for (ll i = n - 1 - 1; i >= 0; i--) {
    tallest[i] = max(tallest[i + 1], v[i].second);
  }

  ll q; cin >> q;
  rep(ti, q) {
    ll t; cin >> t;
    ll it = upper_bound(v.begin(), v.end(), (pair<ll, ll>){t, INF}) - v.begin();
    cout << tallest[it] << '\n';
  }

  return 0;
}
