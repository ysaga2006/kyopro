#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, q; cin >> n >> q;
  string s; cin >> s;

  vector<ll> a(n);
  rep(i, n - 1) {
    a[i + 1] = a[i];
    if (s[i] == 'A' && s[i + 1] == 'C') a[i + 1]++;
  }

  rep(qi, q) {
    ll l, r; cin >> l >> r;
    l--; r--;
    cout << a[r] - a[l] << '\n';
  }
  return 0;
}