#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, t; cin >> n >> t;
    if (n == 0) {
        cout << t << endl;
    } else {
        ll ans = 0;
        vector<ll> v(n);
        for (int i = 0; i < n; i++) {
            ll a; cin >> a;
            v.at(i) = a;
        }
        ll start = 0;
        for (int i = 0; i < n; i++) {
            if (v.at(i) - start >= 0) {
                ans += v.at(i) - start;
                start = v.at(i) + 100;
            }
        }
        ans += max(t - start, ll(0));
        cout << ans << endl;
        }
    
    return 0;
}