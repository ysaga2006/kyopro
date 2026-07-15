#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll ans = 0;

  ll a, n;
  cin >> a >> n;

  for (ll i = 1; i < 1000000; i++) {
    auto f = [&](ll x) -> string {
      string str = "";
      while (x) {
        str.push_back('0' + x % a);
        x /= a;
      }
      reverse(str.begin(), str.end());
      return str;
    };

    string s = to_string(i);
    string res = s;
    reverse(res.begin(), res.end());

    ll even = stoll(s + res);
    if (even > n) continue;

    bool ispali = true;
    string val = f(even);

    rep(k, (val.size() / 2)) {
      if (val[k] != val[val.size() - k - 1]) ispali = false;
    }

    if (ispali == true) ans += even, cout << even << " " << val << '\n';

    for (ll j = 0; j <= 9; j++) {
      ispali = true;
      ll odd = stoll(s + to_string(j) + res);
      if (odd > n) continue;

      val = f(odd);
      rep(k, (val.size() - 1) / 2) {
        if (val[k] != val[val.size() - k - 1]) ispali = false;
      }

      if (ispali == true) ans += odd, cout << odd << " " << val << '\n';
    }
  }

  cout << ans << '\n';

  return 0;
}
