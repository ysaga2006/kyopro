#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m; cin >> n >> m;
    vector<ll> b;
    vector<ll> w;
    ll cnt = 0; // 正の価値をもつblackの数。
    for (int i = 0; i < n; i++) {
        ll val; cin >> val;
        b.emplace_back(val);
        if (val > 0) cnt++;
    }
    sort(b.rbegin(), b.rend());
    for (int i = 0; i < m; i++) {
        ll val; cin >> val;
        if (val > 0) { // whiteについては少なくて良いので、マイナスの価値は消す。
            w.emplace_back(val);
        }
    }
    sort(w.rbegin(), w.rend());
    for (int i = 0; i < ll(b.size() - 1); i++) {
        b[i + 1] += b[i];
    }
    for (int i = 0; i < ll(w.size() - 1); i++) {
        w[i + 1] += w[i];
    }
    ll ans = 0;
    // まず絶対にとるとこまでとる。
    ll l = min(cnt, ll(w.size()));
    if (cnt > ll(w.size())) { // 白を使い果たした
        if (l == 0) {
            ans = b[cnt - 1];
        } else {
            ans = w[l - 1] + b[cnt - 1];
        }
    } else { // 正の黒を使い果たした、残っているのは正の白と負の黒
        for (int i = 0; i < ll(min(w.size(), b.size())); i++) {
            ans = max(ans, w[i] + b[i]);
        }
    }
    cout << ans << endl;
    return 0;
}
