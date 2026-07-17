#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll h, w;
  cin >> h >> w;

  if (w == 1 && h == 1)
    cout << 0 << '\n';

  else if (w == 1) {
    cout << 1 << '\n';
    for (ll i = 0; i < h - 2; ++i)
      cout << 2 << '\n';
    cout << 1 << '\n';
  }

  else if (h == 1) {
    cout << 1 << " ";
    for (ll i = 0; i < w - 2; ++i)
      cout << 2 << " ";
    cout << 1 << '\n';
  }

  else {
    cout << 2 << " ";
    for (ll i = 0; i < w - 2; ++i)
      cout << 3 << " ";
    cout << 2 << '\n';

    for (ll i = 0; i < h - 2; ++i) {
      cout << 3 << " ";
      for (ll j = 0; j < w - 2; ++j)
        cout << 4 << " ";
      cout << 3 << '\n';
    }

    cout << 2 << " ";
    for (ll i = 0; i < w - 2; ++i)
      cout << 3 << " ";
    cout << 2 << '\n';
  }

  return 0;
}
