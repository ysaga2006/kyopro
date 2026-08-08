#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;
  rep(i, n) {
    if ((i + 1) % 3 == 0) cout << "Fizz" << '\n';
    else cout << i + 1 << '\n';
  }
  return 0;
}
