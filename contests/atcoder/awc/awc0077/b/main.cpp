#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m, k; cin >> n >> m >> k;
  
  vector<ll> a(n + 1);
  rep(i, n) cin >> a[i + 1];

  for (ll i = 0; i < n; ++i) {
    a[i + 1] += a[i];
  }

  vector<ll> ans{};

  for (ll i = 0; i < n; ++i) for (ll j = i; j < n; ++j) {
    if (j - i + 1 > k) continue;
    ans.push_back(a[j + 1] - a[i]);
  }

  sort(ans.rbegin(), ans.rend());

  ll val = 0;
  rep(i, m) val += ans[i];

  cout << val << '\n';
  return 0;
}
