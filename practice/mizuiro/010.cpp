#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  bitset<2001> dp;
  dp[0] = 1;

  ll n;
  cin >> n;
  while (n--) {
    ll a;
    cin >> a;
    dp |= (dp << a);
  }

  ll q;
  cin >> q;
  while (q--) {
    ll m;
    cin >> m;
    cout << (dp[m] == true ? "yes" : "no") << '\n';
  }

  return 0;
}

// int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);

//   ll n; cin >> n;

//   vector<ll> a(n);
//   for (ll i = 0; i < n; ++i) cin >> a[i];

//   vector<ll> res;

//   for (ll bit = 0; bit < (1 << n); ++bit) {
//     ll sum = 0;
//     for (ll i = 0; i < n; ++i) {
//       if (bit & (1 << i)) {
//         sum += a[i];
//       }
//     }
//     res.push_back(sum);
//   }

//   sort(res.begin(), res.end());

//   ll q; cin >> q;
//   while (q--) {
//     ll m; cin >> m;
//     cout << (binary_search(res.begin(), res.end(), m) ? "yes" : "no") << '\n';
//   }

//   return 0;
// }