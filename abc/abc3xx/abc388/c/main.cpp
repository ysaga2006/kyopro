#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    ll ok = n - 1, ans = 0;
    vector<ll> v(n); for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = n - 1; i >= 0; --i) {
        while (ok >= 0 && v[ok] * 2 > v[i]) {
            --ok;
        }
        ans += ok + 1;
    }
    cout << ans << '\n';
    return 0;
}
