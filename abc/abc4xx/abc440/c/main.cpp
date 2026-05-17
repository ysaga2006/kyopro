#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    for (ll qi = 0; qi < t; qi++) {
        ll n, w; cin >> n >> w;
        ll ans = 100100100100100;
        vector<ll> c(n);
        vector<ll> s(4 * w + 2);
        for (ll i = 0; i < n; i++) {
            ll a; cin >> a;
            c.at(i) = a;
        }
        for (ll i = 0; i < n; i++) {
            s.at((i + 1) % (2 * w)) += c.at(i);
            s.at((i + 1) % (2 * w) + (2 * w)) += c.at(i);
        }
        for (ll i = 0; i < 4 * w + 1; i++) {
            s.at(i + 1) += s.at(i);
        }
        for (ll i = 0; i < 3 * w; i++) {
            ll val = s.at(i + w) - s.at(i);
            if (val < ans) {
                ans = val;
            }
        }
        cout << ans << endl;
    }
    return 0;
}