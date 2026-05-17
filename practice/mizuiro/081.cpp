#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll KOSA = 1'000'001;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  vector<ll> anke(KOSA, 0);

  for (ll i = 0; i < n; ++i) {
    ll a, b;
    cin >> a >> b;
    anke[a]++;
    anke[b + 1]--;
  }

  ll ans = 0;
  for (ll i = 1; i < KOSA; ++i) {
    anke[i] += anke[i - 1];
    if (anke[ans] < anke[i])
      ans = i;
  }

  // for (auto x : anke) cout << x << " ";
  // cout << '\n';

  cout << anke[ans] << '\n';
  return 0;
}