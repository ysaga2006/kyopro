#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll h, w;
  cin >> h >> w;
  vector v(h, vector<ll>(w, 0));

  for (ll i = 0; i < h; ++i) {
    for (ll j = 0; j < w; ++j) {
      cin >> v[i][j];
    }
  }

  vector<ll> tate(w); // 縦方向の和をもつ
  vector<ll> yoko(h); // 横方向の和をもつ

  for (ll i = 0; i < h; ++i) {
    ll sum = 0;
    for (ll j = 0; j < w; ++j) {
      sum += v[i][j];
    }
    yoko[i] = sum;
  }

  for (ll i = 0; i < w; ++i) {
    ll sum = 0;
    for (ll j = 0; j < h; ++j) {
      sum += v[j][i];
    }
    tate[i] = sum;
  }

  for (ll i = 0; i < h; ++i) {
    for (ll j = 0; j < w; ++j) {
      cout << yoko[i] + tate[j] - v[i][j] << " ";
    }
    cout << '\n';
  }
  return 0;
}