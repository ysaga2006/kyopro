#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll ok = false;

  ll n;
  cin >> n;

  vector<ll> a(n * 2 + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i + n] = a[i];
  }

  rep(i, 2 * n - 1) a[i + 1] += a[i];

  ll val = a[n] / 10;

  ll r = 0;
  for (int l = 0; l <= r; l++) {
    if (a[r + 1] - a[l] == val) ok = true;
    else if (a[r + 1] - a[l] > val) continue;
    else {
      if (r > min(2 * n, l + n)) continue;
      else r++;
    }
  }

  cout << (ok ? "Yes" : "No") << '\n';
  return 0;
}