#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m; cin >> n >> m;
    vector<ll> v(n, n - 1);
    for (;m--;) {
        ll a, b; cin >> a >> b;
        a--; b--;
        v.at(a)--;
        v.at(b)--;
    }
    for (ll i = 0; i < n; i++) {
        if (v.at(i) >= 3) {
            cout << v.at(i) * (v.at(i) - 1) * (v.at(i) - 2) / 6 << " ";
        } else {
            cout << 0 << " ";
        }
    }
    cout << endl;
    return 0;
}