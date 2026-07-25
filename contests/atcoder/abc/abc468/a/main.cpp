#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll cnt = 0;
  rep(i, n - 2) {
    if (a[i] < a[i + 1] && a[i + 1] > a[i + 2]) cnt++;
  }

  cout << cnt << '\n';
  return 0;
}
