#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k, m;
  cin >> n >> k >> m;

  vector<pair<ll,ll>> a(n);
  rep(i, n) {
    ll c, v; cin >> c >> v;
    a[i] = {v, c};
  }

  sort(a.rbegin(), a.rend());

  map<ll,ll> cnt;
  set<ll> used;
  vector<ll> kesu, add;
  ll ans = 0;
  rep(i, k) {
    auto [v, c] = a[i];
    ans += v;
    cnt[c]++;
    used.insert(c);
  }

  ll need = max(0LL, m - (ll)used.size());

  rep(i, k) {
    auto [v, c] = a[i];
    if (cnt[c] > 1) {
      kesu.push_back(v);
      cnt[c]--;
    }
  }

  for (ll i = k; i < n; i++) {
    auto [v, c] = a[i];
    if (used.count(c) == 0) {
      add.push_back(v);
      used.insert(c);
    }
  }

  sort(kesu.begin(), kesu.end());
  rep(i, need) {
    ans += add[i] - kesu[i];
  }

  cout << ans << '\n';
}