#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll x; cin >> x;
  if (x == 1) cout << 2 << '\n';
  if (x == 2) cout << 3 << '\n';
  if (x == 3) cout << 1 << '\n';
  return 0;
}
