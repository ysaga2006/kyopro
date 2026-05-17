#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  ll n, q; cin >> n >> q;

  vector<ll> ue(n + 1, 0);
  vector<ll> sita(n + 1, 0);

  while (q--) {
    ll c, p; cin >> c >> p;
    if (sita[c] != 0) ue[sita[c]] = 0;
    ue[p] = c;
    sita[c] = p;
  }

  for (ll i = 1; i < n + 1; ++i) {
    if (sita[i] == 0) {
      ll cnt = 1, now = i;
      while (ue[now] != 0) {
        now = ue[now];
        cnt++;
      }
      cout << cnt << " ";
    } else {
      cout << 0 << " ";
    }
  }
  cout << '\n';
  return 0;
}
