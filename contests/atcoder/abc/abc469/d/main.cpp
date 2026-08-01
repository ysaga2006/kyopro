#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m; cin >> n >> m;

  set<pair<ll, ll>> ans;

  vector<ll> a(m), b(m);
  rep(i, m) cin >> a[i] >> b[i];

  ll oth = -INF;
  rep(i, m) {
    if (a[i] != a[0] && b[i] != a[0]) {
      oth = i; break;
    }
  }

  if (oth != -INF) {
    bool ok = true;
    rep(i, m) {
      if (a[i] != a[0] && b[i] != a[0] && a[i] != a[oth] && b[i] != a[oth]) ok = false;
    }
    if (ok == true) ans.insert({min(a[0], a[oth]), max(a[0], a[oth])});

    ok = true;
    rep(i, m) {
      if (a[i] != a[0] && b[i] != a[0] && a[i] != b[oth] && b[i] != b[oth]) ok = false;
    }
    if (ok == true) ans.insert({min(a[0], b[oth]), max(a[0], b[oth])});
  } else {
    for (ll i = 1; i <= n; i++) {
      if (a[0] != i) {
        ans.insert({min(a[0], i), max(a[0], i)});
      }
    }
  }

  oth = -INF;
  rep(i, m) {
    if (a[i] != b[0] && b[i] != b[0]) {
      oth = i; break;
    }
  }

  if (oth != -INF) {
    bool ok = true;
    rep(i, m) {
      if (a[i] != b[0] && b[i] != b[0] && a[i] != a[oth] && b[i] != a[oth]) ok = false;
    }
    if (ok == true) ans.insert({min(b[0], a[oth]), max(b[0], a[oth])});

    ok = true;
    rep(i, m) {
      if (a[i] != b[0] && b[i] != b[0] && a[i] != b[oth] && b[i] != b[oth]) ok = false;
    }
    if (ok == true) ans.insert({min(b[0], b[oth]), max(b[0], b[oth])});
  } else {
    for (ll i = 1; i <= n; i++) {
      if (b[0] != i) {
        ans.insert({min(b[0], i), max(b[0], i)});
      }
    }
  }

  cout << ans.size() << '\n';
  return 0;
}
