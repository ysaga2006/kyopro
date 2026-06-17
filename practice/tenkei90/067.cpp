#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k; cin >> n >> k;
  
  auto f = [&](string x) { // 8進数を10進数にしてから9進数にする
    ll res = 0, a = 1;

    rep(i, x.size()) {
      res += a * ll(x[i] - '0');
      a *= 8;
    }

    string ans;
    while (res > 0) {
      ans.push_back(res / 9);
      res /= 9;
    }
  };

  return 0;
}