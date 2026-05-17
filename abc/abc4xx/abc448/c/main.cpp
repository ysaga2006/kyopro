#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, q; cin >> n >> q;
    vector<ll> w(n);
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v.at(i);
    }
    w = v;
    sort(w.begin(), w.end());
    while (q--) {
        vector<ll> z(6);
        for (int i = 0; i < 6; i++) {
            z.at(i) = w.at(i);
        }
        ll k; cin >> k;
        while (k--) {
            ll b; cin >> b; b--;
            for (int i = 0; i < 5; i++) {
                if (v.at(b) == z.at(i)) {
                    z.at(i) = 100100100100;
                }
            }
        }
        sort(z.begin(), z.end());
        cout << z.at(0) << endl;
    }
    return 0;
}
