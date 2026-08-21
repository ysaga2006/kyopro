#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll a, b; cin >> a >> b;
  if (a + b == 9 || a - b == 9 || a * b == 9 || a == 9 * b) cout << "Nine" << '\n';
  else cout << "Nein" << '\n';
  return 0;
}
