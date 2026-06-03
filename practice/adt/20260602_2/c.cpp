#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll x, n; cin >> x >> n;

  vector<ll> w(n);
  rep(i, n) cin >> w[i];

  vector<bool> used(n, false);

  ll wei = x;
  ll q; cin >> q;
  while (q--) {
    ll p; cin >> p; p--;

    used[p] = 1 - used[p];
    if (used[p] == true) wei += w[p];
    else wei -= w[p];

    cout << wei << '\n';
  }

  return 0;
}