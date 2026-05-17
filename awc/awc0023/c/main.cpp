#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m; cin >> n >> m;
    vector<ll> t(n);
    for (ll i = 0; i < n; i++) {
        cin >> t[i];
    }
    for (ll i = 0; i < n - 1; i++) {
        t[i + 1] += t[i];
    }
    while (m--) {
        ll s, l, r; cin >> s >> l >> r; --l; --r;
        if (l != 0) {
            cout << s + t[r] - t[l - 1] << '\n';
        } else {
            cout << s + t[r] << '\n';
        }
    }
    return 0;
}