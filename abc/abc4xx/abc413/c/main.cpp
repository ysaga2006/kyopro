#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    queue<pair<ll, ll>> qu; //{個数、数字}
    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++) {
        ll n; // クエリの種類
        cin >> n;
        if (n == 1) {
            ll c, x; // 追加する個数と数字
            cin >> c >> x;
            qu.push({c, x});
        } else {
            ll k; // 削除する個数
            cin >> k;
            if (qu.front().first >= k) {
                cout << k * qu.front().second << "\n";
                qu.front().first -= k;
            } else {
                ll cnt = 0, sum = 0; // 消した数の個数と合計
                while (cnt < k) {
                    cnt += qu.front().first;
                    sum += qu.front().first * qu.front().second;
                    if (cnt > k) {
                        sum -= (cnt - k) * (qu.front().second);
                        qu.front().first -= (cnt - k);
                        cnt = k;
                    } else {
                        qu.pop();
                    }
                }
                cout << sum << endl;
            }
        }
    }
    return 0;
}