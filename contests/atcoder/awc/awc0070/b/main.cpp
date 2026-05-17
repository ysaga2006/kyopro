#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;
    ll sum = 0, ans = 0;

    for (ll i = 0; i < n; ++i) {
        ll a; cin >> a;
        sum += a;
        if (a * (i + 1) >= sum) ans++;
    }

    cout << ans << '\n';
    return 0;
}
