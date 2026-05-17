#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll m, s;
  cin >> m >> s;
  ll bunpai = s / m;
  ll amari = s % m;

  vector<ll> snacks(m + 1);
  for (int i = 1; i <= m; ++i) {
    ll b;
    cin >> b;
    snacks[i] += b + bunpai;
    if (i <= amari) {
      snacks[i]++;
    }
  }

  for (int i = 0; i <= m - 1; ++i) {
    snacks[i + 1] += snacks[i];
  }

  ll n;
  cin >> n;
  while (n--) {
    ll l, r;
    cin >> l >> r;
    cout << snacks[r] - snacks[l - 1] << '\n';
  }
  return 0;
}
