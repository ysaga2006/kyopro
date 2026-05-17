#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, q; cin >> n >> k >> q;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v.at(i);
    }
    vector<ll> w(n);
    w.at(0) = 0;
    ll team = 0;
    for (int i = 0; i < n - 1; i++) {
        if (abs(v.at(i + 1) - v.at(i)) <= k) {
            w.at(i + 1) = team;
        } else {
            team++;
            w.at(i + 1) = team;
        }
    }
    while (q--) {
        ll l, r; cin >> l >> r; l--; r--;
        if (w.at(l) == w.at(r)) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
    return 0;
}