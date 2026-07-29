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

  // i文字目までの2連続で同じ文字であるペアの個数をもつ
  // lからr文字目までに何個あるか
  // (1からr文字目まで) - (1からl文字目まで)

  vector<ll> a(n);
  a[0] = 0;

  rep(i, n - 1) {
    a[i + 1] = a[i];
    if (s[i + 1] == s[i]) a[i + 1]++;
  }

  rep(qi, q) {
    ll l, r; cin >> l >> r; l--; r--;
    cout << a[r] - a[l] << '\n';
  }
  return 0;
}
