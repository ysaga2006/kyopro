#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  ll n, m; cin >> n >> m;
  set<ll> st;

  for (ll i = 0; i < n; ++i) {
    ll f; cin >> f;
    st.insert(f);
  }
  if (ll(st.size()) == n) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  if (ll(st.size()) == m) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
