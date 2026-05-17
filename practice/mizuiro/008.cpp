#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  vector<ll> a(n);
  vector<ll> b(n);
  vector<ll> st;
  for (ll i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    st.push_back(a[i]);
    st.push_back(b[i]);
  }

  ll m = st.size();

  ll ans = INF;

  for (ll i = 0; i < m; ++i)
    for (ll j = 0; j < m; ++j) {
      ll time = 0;
      for (ll k = 0; k < n; ++k) {
        if (a[k] >= b[k])
          swap(a[k], b[k]);

        if (a[k] <= st[i] && b[k] <= st[j])
          time += (st[i] - a[k]) + (st[j] - a[k]);
        else if (st[i] <= a[k] && b[k] <= st[j])
          time += st[j] - st[i];
        else if (st[i] <= a[k] && st[j] <= b[k])
          time += (b[k] - st[i]) + (b[k] - st[j]);
        else if (a[k] <= st[i] && st[j] <= b[k])
          time += 2 * (b[k] - a[k]) - (st[j] - st[i]);
      }

      ans = min(ans, time);
    }

  cout << ans << '\n';

  return 0;
}