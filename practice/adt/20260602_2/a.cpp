#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<ll> v(5);
  rep(i, 5) cin >> v[i];
  
  set<ll> st;
  rep(i, 5) st.insert(v[i]);

  vector<ll> ans{};

  for (auto& e : st) {
    ll cnt = 0;
    rep(i, 5) if (v[i] == e) cnt++;
    ans.push_back(cnt);
  }

  sort(ans.begin(), ans.end());

  if (ans[0] == 2 && ans[1] == 3) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}