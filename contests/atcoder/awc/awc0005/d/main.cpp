#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k; cin >> n >> k;
    vector<ll> v(n);
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        cin >> v.at(i);
        sum += v.at(i);
    }
    auto ok = [&](ll x) {
        ll cnt = 0;
        ll w = 0;
        for (auto a : v) {
            w += a;
            if (w >= x) {
                cnt++;
                w = 0;
            }
        }
        return cnt >= k;
    };
    ll l = 0, r = sum / k + 1;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        if (ok(m)) l = m;
        else r = m;
    }
    cout << l << '\n';
    return 0;
}