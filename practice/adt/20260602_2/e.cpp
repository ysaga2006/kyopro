#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k; cin >> n >> k;

  vector<ll> score(n), bunpu;
  rep(i, n) rep(j, 3) {
    ll x; cin >> x;
    score[i] += x;
  }

  bunpu = score;
  sort(bunpu.begin(), bunpu.end());

  rep(i, n) {
    ll kari = score[i] + 300;
    ll rank = bunpu.end() - upper_bound(bunpu.begin(), bunpu.end(), kari) + 1;
    cout << rank << " " << (rank <= k ? "Yes" : "No") << '\n'; 
  }

  return 0;
}