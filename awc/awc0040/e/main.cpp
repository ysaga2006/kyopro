#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  const ll SIZE = 1000000001;
  ll n, q;
  cin >> n >> q;

  vector<ll> data(SIZE);
  for (ll i = 0; i < n; ++i) {
    ll x, v;
    cin >> x >> v;
    data[x] = v;
  }

  vector<ll> kind(SIZE); // kind[i]はi以前の評価値の種類数
  kind[0] = 1;

  for (ll i = 0; i < SIZE - 1; ++i) {
    if (data[i + 1] != data[i]) {
      kind[i + 1] = kind[i] + 1;
    } else {
      kind[i + 1] = kind[i];
    }
  }

  while (q--) {
    ll l, r;
    cin >> l >> r;
    ll chohuku = (r - l + 1) - (kind[r] - kind[l] + 1);
    cout << ((r - l) * (r - l + 1) - (chohuku) * (chohuku + 1)) / 2 << '\n';
  }

  return 0;
}
