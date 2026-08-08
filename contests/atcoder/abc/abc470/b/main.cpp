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
  vector<ll> color(n + 5);
  rep(i, n) {
    ll c;
    cin >> c;
    color[c]++;
  }
  sort(color.rbegin(), color.rend());
  cout << n - color.front() << '\n';

  return 0;
}
