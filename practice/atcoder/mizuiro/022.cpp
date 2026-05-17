#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  double p;
  cin >> p;

  double x = 1.5 * log2(p * log(2.0) / 1.5);
  if (x < 0) x = 0;
  double ans = x + p / pow(2.0, x / 1.5);

  cout << fixed << setprecision(10) << ans << '\n';

  return 0;
}