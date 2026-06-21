#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

const ll INF = 1000000000000;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k;
  cin >> n >> k;

  vector<pair<ll, ll>> v(n);
  rep(i, n) cin >> v[i].second >> v[i].first;
  sort(v.begin(), v.end());

  auto f = [&](ll x) -> bool {
    ll utan = -1, cnt = 0;
    bool ok = false;

    for (auto& [r, l] : v) {
      if (cnt == 0 || l >= utan + x) {
        cnt++;
        utan = r;
      }
      if (cnt >= k) ok = true;
    }

    return ok;
  };

  ll ok = INF, ng = - 1;
  while (ok - ng > 1) {
    ll mid = (ok + ng) / 2;

    if (f(mid)) {
      ng = mid;
    } else {
      ok = mid;
    }
  }

  if (ng == 0) ng = -1;
  cout << ng << '\n';

  return 0;
}
