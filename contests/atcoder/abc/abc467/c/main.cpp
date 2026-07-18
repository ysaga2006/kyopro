#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m; cin >> n >> m;
  vector<ll> a(n), b(n - 1);

  rep(i, n) cin >> a[i];
  rep(i, n - 1) cin >> b[i];

  ll cnt1 = 0;
  vector<ll> c = a;
  for (ll i = 0; i < n - 1; i++) {
    if ((c[i] + c[i + 1]) % 2 != b[i]) {
      c[i + 1]++; cnt1++;
    }
  }

  ll cnt2 = 1;
  vector<ll> d = a; d[0]++;
  for (ll i = 0; i < n - 1; i++) {
    if ((d[i] + d[i + 1]) % 2 != b[i]) {
      d[i + 1]++; cnt2++;
    }
  }

  cout << min(cnt1, cnt2) << '\n';
  
  return 0;
}
