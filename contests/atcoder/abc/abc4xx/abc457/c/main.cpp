#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  ll n, k; cin >> n >> k;

  vector a(n, vector<ll>{});
  vector<ll> len(n);

  for (ll i = 0; i < n; ++i) {
    cin >> len[i];
    for (ll j = 0; j < len[i]; ++j) {
      ll x; cin >> x;
      a[i].push_back(x);
    }
  }

  ll sum = 0, mae = 0;

  vector<ll> c(n);
  for (ll i = 0; i < n; ++i) cin >> c[i];

  for (ll i = 0; i < n; ++i) {
    if (sum + c[i] * len[i] < k) {
      sum += c[i] * len[i];
    } else {
      mae = k - 1 - sum;
      cout << a[i][mae % len[i]] << '\n';
      return 0;
    }
  }
}
