#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, q; cin >> n >> q;
    vector<ll> s(n + 1);
    vector<ll> v(n + 1);
    for (ll i = 1; i < n + 1; i++) {
        ll a; cin >> a;
        v.at(i) = a;
        s.at(i) = a;
    }
    for (ll i = 1; i < n; i++) {
        s.at(i + 1) += s.at(i);
    }
    for (;q--;) {
        ll num; cin >> num;
        if (num == 1) {
            ll x; cin >> x;
            s.at(x) -= v.at(x) - v.at(x + 1);
            swap(v.at(x), v.at(x + 1));
        } else {
            ll l, r; cin >> l >> r;
            cout << s.at(r) - s.at(l - 1) << '\n';
        }
    }
    return 0;
}