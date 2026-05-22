#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll a, b, k; cin >> a >> b >> k;
  if (a < k) cout << 0 << " " << max(0ll, (b - (k - a))) << '\n';
  else cout << (a - k) << " " << b << '\n'; 
  return 0;
}