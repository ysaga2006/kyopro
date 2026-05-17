#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll h, w;
  cin >> h >> w;
  for (int i = 0; i < w; ++i) {
    cout << '#';
  }
  cout << '\n';

  for (int i = 0; i < h - 2; ++i) {
    cout << '#';
    for (int i = 0; i < w - 2; ++i) {
      cout << '.';
    }
    cout << '#';
    cout << '\n';
  }

  for (int i = 0; i < w; ++i) {
    cout << '#';
  }
  cout << '\n';

  return 0;
}
