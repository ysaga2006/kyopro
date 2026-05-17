#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vector<ll> v(n);
    bool ok = true;
    for (ll i = 0; i < n; i++) {
        ll a; cin >> a;
        v.at(i) = a;
    }
    for (ll i = 0; i < n - 2; i++) {
        if (v.at(i + 1) * v.at(i + 1) != v.at(i) * v.at(i + 2)) ok = false;
    }
    cout << (ok ? "Yes" : "No") << '\n';
    return 0;
}
