#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vector<ll> v(n);
    ll sum = 0, ans = 0;
    for (ll i = 0; i < n; i++) {
        ll a; cin >> a;
        v.at(i) = a;
        sum += a;
    }
    ans += sum * sum;
    for (ll i = 0; i < n; i++) {
        ans -= v.at(i) * v.at(i);
    }
    ans /= 2;
    cout << ans << endl;
    return 0;
}