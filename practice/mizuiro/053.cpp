#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;

  vector<ll> a(n);
  for (ll i = 0; i < n; ++i) cin >> a[i];

  vector<ll> dp;

  for (ll i = 0; i < n; ++i) {
    auto ite = lower_bound(dp.begin(), dp.end(), a[i]);

  }
  return 0;
}