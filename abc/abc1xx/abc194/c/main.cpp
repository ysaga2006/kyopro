#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vector<ll> v(n + 1);
    for (ll i = 0; i < n; i++) {
        ll a; cin >> a;
        v.at(i + 1) = a;
    }
    ll f = 0, s = 0, t = 0;
    for (ll i = 1; i <= n - 1; i++) {
        f += n * v.at(i) * v.at(i);
    }
    s += v.at(n) * v.at(n) * n;
    for (ll i = 1; i <= n; i++) {
        t += v.at(i);
    }
    t *= t;
    cout << f + s - t << endl;
    return 0;
}