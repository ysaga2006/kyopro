#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, l; cin >> n >> l;
    if (l % 3 != 0) {
        cout << 0 << endl;
    } else {
        vector<ll> v(l);
        v.at(0)++;
        ll pre = 0;
        for (ll i = 0; i < n - 1; i++) {
            ll d; cin >> d;
            v.at((pre + d) % l)++;
            pre += d;
        }
        ll cnt = 0;
        for (ll i = 0; i < l / 3; i++) {
            if (v.at(i) > 0 && v.at(i + (l / 3)) > 0 && v.at(i + (2 * l / 3)) > 0) {
                cnt += v.at(i) * v.at(i + (l / 3)) * v.at(i + (2 * l / 3));
            }
        }
        cout << cnt << endl;
    }
    return 0;
}