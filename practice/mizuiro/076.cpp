#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll i = 0; i < n; ++i)
    cin >> a[i];

  vector<ll> s(n + 1);  // s[i]はa[0]からa[i - 1]までの和
  s[0] = 0;
  for (ll i = 0; i < n; ++i) {
    s[i + 1] = s[i] + a[i];
  }

  for (ll i = 1; i < n + 1; ++i) {
    ll res = -1;
    for (ll left = 0; left < n - i + 1; ++left) {
      res = max(res, s[left + i] - s[left]);
    }
    cout << res << '\n';
  }

  return 0;
}