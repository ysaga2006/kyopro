#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, q;
  cin >> n >> q;

  vector<ll> cnt(n + 1, 0);

  vector<ll> num(q + 2, 0);
  num[0] = n;

  vector<ll> sumh(q + 2, 0);
  sumh[0] = n;

  ll drop = 0;
  ll minblo = 0;
  ll mincnt = n;

  for (ll qi = 0; qi < q; qi++) {
    ll op;
    cin >> op;

    if (op == 1) {
      ll x;
      cin >> x;

      ll nowh = cnt[x];

      num[nowh]--;
      num[nowh + 1]++;
      sumh[nowh + 1]++;

      cnt[x]++;

      if (nowh == minblo) {
        mincnt--;

        if (mincnt == 0) {
          minblo++;
          mincnt = num[minblo];
        }
      }

      if (minblo > drop) {
        drop++;
      }

    } else {
      ll y;
      cin >> y;

      if (y + drop > q) {
        cout << 0 << "\n";
      } else {
        cout << sumh[y + drop] << "\n";
      }
    }
  }

  return 0;
}