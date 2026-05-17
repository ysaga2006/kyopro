#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, t; cin >> n >> t;
    vector<ll> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h.at(i);
    }
    vector<ll> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c.at(i);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (h.at(i) <= t) {
            ans += c.at(i);
        }
    }
    cout << ans << endl;
    return 0;
}