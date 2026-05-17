#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k; cin >> n >> k;
    ll m; cin >> m;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v.at(i);
    }
    ll ans = 0;
    ll sum = 0;
    ll r = 0;
    // leftを0からn-1まで動かす
    for (ll l = 0; l < n; l++) {
        while (r < n and (sum < m or (r - l) < k)) {
            sum += v.at(r);
            r++;
        }
        if (sum >= m and (r - l) >= k) {
            ans += n - r + 1;
        }
        sum -= v.at(l);
    }
    cout << ans << '\n';
    return 0;
}