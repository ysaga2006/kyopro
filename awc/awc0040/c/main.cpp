#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k;
  cin >> n >> k;

  vector<ll> apple(n);
  for (auto& x : apple) cin >> x;

  sort(apple.begin(), apple.end());

  ll ans = 0;
  for (ll i = 0; i < n; ++i) {
    auto ite = upper_bound(apple.begin(), apple.end(), apple[i] + k);
    ans = max(ans, ll(ite - apple.begin()) - i);
  }

  cout << ans << '\n';
  return 0;
}