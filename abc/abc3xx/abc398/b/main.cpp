#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<ll> v(13);
  for (int i = 0; i < 7; ++i) {
    ll a;
    cin >> a;
    a--;
    v[a]++;
  }
  bool duo = false, trio = false;
  for (int i = 0; i < 13; ++i) {
    if (v[i] >= 3) {
      if (trio == false) {
        trio = true;
      } else {
        duo = true;
      }
    } else if (v[i] >= 2) {
      duo = true;
    }
  }
  cout << (duo && trio ? "Yes" : "No") << '\n';
  return 0;
}
