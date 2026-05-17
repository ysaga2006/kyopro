#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll SIZE = 2000;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  ll n; cin >> n;

  vector cloud(SIZE + 1, vector<ll>(SIZE + 1, 0));
  vector id(SIZE + 1, vector<ll>(SIZE + 1, 0));

  for (ll i = 1; i <= n; ++i) {
    ll u, d, l, r; cin >> u >> d >> l >> r;
    u--; d--; l--; r--;
    cloud[u][l]++;
    cloud[u][r + 1]--;
    cloud[d + 1][l]--;
    cloud[d + 1][r + 1]++;

    id[u][l] += i;
    id[u][r + 1] -= i;
    id[d + 1][l] -= i;
    id[d + 1][r + 1] += i;
  }

  for (ll i = 0; i < SIZE - 1; ++i) for (ll j = 0; j < SIZE; ++j) {
    cloud[i + 1][j] += cloud[i][j];
  }

  for (ll i = 0; i < SIZE; ++i) for (ll j = 0; j < SIZE - 1; ++j) {
    cloud[i][j + 1] += cloud[i][j];
  }

  for (ll i = 0; i < SIZE - 1; ++i) for (ll j = 0; j < SIZE; ++j) {
    id[i + 1][j] += id[i][j];
  }

  for (ll i = 0; i < SIZE; ++i) for (ll j = 0; j < SIZE - 1; ++j) {
    id[i][j + 1] += id[i][j];
  }

  vector<ll> solo(n, 0);
  ll hare = 0;

  for (ll i = 0; i < SIZE; ++i) for (ll j = 0; j < SIZE; ++j) {
    if (cloud[i][j] == 0) hare++;
    else if (cloud[i][j] == 1) solo[id[i][j] - 1]++;
  }

  for (ll i = 0; i < n; ++i) {
    cout << hare + solo[i] << '\n';
  }
  return 0;
}
