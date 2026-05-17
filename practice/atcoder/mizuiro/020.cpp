// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);

//   ll ans = 0;

//   ll n; cin >> n;

//   vector<ll> a(n), b(n), c(n);
//   for (ll i = 0; i < n; ++i) cin >> a[i];
//   for (ll i = 0; i < n; ++i) cin >> b[i];
//   for (ll i = 0; i < n; ++i) cin >> c[i];

//   sort(a.begin(), a.end());
//   sort(b.begin(), b.end());
//   sort(c.begin(), c.end());

//   for (ll i = 0; i < n; ++i) {
//     ll ite1 = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
//     for (ll j = ite1; j < n; ++j) {
//       ll ite2 = upper_bound(c.begin(), c.end(), b[j]) - c.begin();
//       ans += c.size() - ite2;
//     }
//   }

//   cout << ans << '\n';
//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  ll ans = 0;

  ll n; cin >> n;

  vector<ll> a(n), b(n), c(n);
  for (ll i = 0; i < n; ++i) cin >> a[i];
  for (ll i = 0; i < n; ++i) cin >> b[i];
  for (ll i = 0; i < n; ++i) cin >> c[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  for (ll i = 0; i < n; ++i) {
    ll cnta = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
    ll cntc = c.end() - upper_bound(c.begin(), c.end(), b[i]);

    ans += cnta * cntc;
  }

  cout << ans << '\n';
  return 0;
}