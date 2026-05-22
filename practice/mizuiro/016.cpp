#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;
  
  vector<ll> p(n);
  for (ll i = 0; i < n; ++i) cin >> p[i];

  vector<ll> q(n);
  for (ll i = 0; i < n; ++i) cin >> q[i];

  vector<ll> v(n);
  iota(v.begin(), v.end(), 1);

  ll cnt = 0, a, b;


  do {
    if (p == v) a = cnt;
    if (q == v) b = cnt;
    cnt++;
  } while (next_permutation(v.begin(), v.end()));

  cout << abs(a - b) << '\n';
  return 0;
}