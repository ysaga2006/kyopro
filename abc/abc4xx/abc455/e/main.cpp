#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  ll n; string s;
  cin >> n >> s;

  vector<ll> a(n + 1, 0);
  vector<ll> b(n + 1, 0);
  vector<ll> c(n + 1, 0);

  for (ll i = 1; i < n + 1; ++i) {
    if (s[i] == 'A') a[i]++;
    if (s[i] == 'B') b[i]++;
    if (s[i] == 'C') c[i]++;
  }

  for (ll i = 0; i < n; ++i) {
    a[i + 1] += a[i];
    b[i + 1] += b[i];
    c[i + 1] += c[i];
  }

  map<ll, ll> ab, bc, ca;
  map<pair<ll, ll>, ll> abc;

  

  cout << (n * (n + 1) / 2) - ll(ab.size() + bc.size() + ca.size() - abc.size() * 2) << '\n';

  return 0;
}
