#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;
  ll cnt1 = 0, cnt10 = 0, cnt100 = 0;

  rep(i, n) {
    ll a;
    cin >> a;
    ll x = a / 1000;
    x = (x + 1) * 1000 - a;

    if (x == 1000) {
      continue;
    }

    cnt100 += (x / 100);
    x %= 100;
    cnt10 += (x / 10);
    x %= 10;
    cnt1 += x;
  }

  cout << cnt1 << " " << cnt10 << " " << cnt100 << '\n';
  return 0;
}
