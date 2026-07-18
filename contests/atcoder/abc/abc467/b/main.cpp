#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;
  ll x = 10000, y = 10000;

  rep(i, n) {
    ll a, b; string s; cin >> a >> b >> s;
    y -= a;
    if (s == "take") {
      x -= a;
    } else {
      x -= b;
    }
  }

  cout << y - x << '\n';
  return 0;
}
