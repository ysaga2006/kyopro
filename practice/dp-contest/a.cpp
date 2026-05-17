#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;

    vector<ll> v(n + 1);
    for (int i = 1; i <= n; ++i) cin >> v[i];

    vector<ll> w(n + 1, 0);
    w[1] = 0;
    w[2] = abs(v[2] - v[1]);
    for (int i = 1; i <= n - 2; ++i) {
        w[i + 2] = min(w[i + 1] + abs(v[i + 2] - v[i + 1]), 
        w[i] + abs(v[i + 2] - v[i]));
    }

    cout << w[n] << '\n';
    return 0;
}