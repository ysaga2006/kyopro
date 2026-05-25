#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, q; cin >> n >> q;
    vector<ll> X(n);
    vector<ll> Y(n);
    ll upx = 0;
    ll lox = 100100100100;
    ll upy = 0;
    ll loy = 100100100100;
    for (ll i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        X.at(i) = x + y;
        Y.at(i) = x - y;
        upx = max(upx, X.at(i));
        lox = min(lox, X.at(i));
        upy = max(upy, Y.at(i));
        loy = min(loy, Y.at(i));
    }
    while (q--) {
        ll a; cin >> a; a--;
        ll val = max({X.at(a) - lox, upx - X.at(a), Y.at(a) - loy, upy - Y.at(a)});
        cout << val << '\n';
    }
    return 0;
}