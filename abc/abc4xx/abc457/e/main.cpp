#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m; cin >> n >> m;

  vector left(n, vector<ll>{}), right(n, vector<ll>{});

  for (ll i = 0; i < m; ++i) {
    ll l, r; cin >> l >> r; l--; r--;
    left[l].push_back(r);
    right[r].push_back(l);
  }

  for (ll i = 0; i < n; ++i) {
    sort(left[i].begin(), left[i].end());
    sort(right[i].begin(), right[i].end());
  }

  ll q; cin >> q;
  for (ll i = 0; i < q; ++i) {
    ll s, t; cin >> s >> t;
    s--; t--;

    auto it1 = upper_bound(left[s].begin(), left[s].end(), t); it1--;
    auto it2 = lower_bound(right[t].begin(), right[t].end(), s);

    if (it1 == left[s].begin() || it2 == right[t].end()) {
      cout << "No" << '\n'; continue;
    }

    if (*it2 <= *it1 + 1) cout << "Yes" << '\n';
    else cout << "No" << '\n';

  }
  
  return 0;
}
