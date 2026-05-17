#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;

  vector<ll> h(n);
  vector<ll> s(n);
  for (ll i = 0; i < n; ++i) cin >> h[i] >> s[i];

  auto ok = [&](ll x) -> bool {

    vector<ll> v;
    vector<ll> w(n);
    iota(w.begin(), w.end(), 0);

    for (ll i = 0; i < n; ++i) {
      if (x - h[i] < 0) return false;
      ll val = (x - h[i]) / s[i];
      v.push_back(val);
    }

    sort(v.begin(), v.end());

    for (ll i = 0; i < n; ++i) {
      if (v[i] - w[i] < 0) return false;
    }
    return true;
  };

  ll l = -1, r = INF;
  while (r - l > 1) {
    ll m = l + (r - l) / 2;
    if (ok(m) == true) r = m;
    else l = m;
  }

  cout << r << '\n';

  return 0;
}