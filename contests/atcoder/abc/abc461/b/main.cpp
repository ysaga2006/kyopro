#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  bool ok = true;

  ll n; cin >> n;

  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i], a[i]--;
  rep(i, n) cin >> b[i], b[i]--;

  rep(i, n) if (b[a[i]] != i) ok = false;

  cout << (ok == true ? "Yes" : "No") << '\n';
  return 0;
}
