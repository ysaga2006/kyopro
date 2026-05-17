#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll n, q;
vector<ll> b(200005); // bit
vector<ll> s(200005); // 各店舗の売上をもつ

// インデックスiに値vを加算する関数
void add(ll i, ll v) {
    for (;i <= n; i += i & -i) {
        b.at(i) += v;
    }
}
// 1からiまでの和を計算する関数
ll sum(ll i) {
    ll res = 0;
    for (; i > 0; i -= i & -i) {
        res += b.at(i);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    // 初期状態の読み込み
    for (ll i = 1; i <= n; i++) {
        cin >> s.at(i);
        add(i, s.at(i));
    }
    // クエリの処理
    while (q--) {
        ll qn; cin >> qn;
        if (qn == 1) {
            ll l, r; cin >> l >> r;
            cout << sum(r) - sum(l - 1) << '\n';
        }
        if (qn == 2) {
            ll x, v; cin >> x >> v;
            add(x, v - s.at(x));
            s.at(x) = v;
        }
    }
    return 0;
}