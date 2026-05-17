#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k; cin >> n >> k;
    ll sum = 0;
    const ll mod = 1e9;
    vector<ll> v(n + 1);
    for (int i = 0; i <= n; i++) {
        if (i < k) {
            v[i] = 1;
            sum += v[i];
        } else {
            v[i] = sum;
            sum -= v[i - k];
            sum += mod;
            sum += v[i];
            sum %= mod;
        }
    }
    cout << v[n] % mod << endl;
    return 0;
}