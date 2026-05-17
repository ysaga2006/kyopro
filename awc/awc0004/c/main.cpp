#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v.at(i);
    }
    sort(v.begin(), v.end());
    cout << (abs(v.back()) + abs(v.front())) + abs(v.back() - v.front()) << '\n';
    return 0;
}