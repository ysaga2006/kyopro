#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k; cin >> n >> k;
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        if (a * b >= k) {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}