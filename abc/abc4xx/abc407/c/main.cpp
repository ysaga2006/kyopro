#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ll> v;
    ll ans = 0;
    string s; cin >> s;
    for (ll i = 0; i < ll(s.size()); i++) {
        v.push_back(s[i] - '0');
    }
    for (ll i = 0; i < ll(s.size()); i++) {
        v.at(i) += 100100100;
    }
    reverse(v.begin(), v.end());
    // for (ll i = 0; i < ll(v.size()); i++) {
    //     cout << v.at(i) << " ";
    // }
    // cout << endl;
    for (ll i = 0; i < ll(v.size()); i++) {
        ans += (v.at(i) - ans) % 10;
    }
    ans += v.size();
    cout << ans << endl;
    return 0;
}