#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k; cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v.at(i);
    }
    sort(v.begin(), v.end());
    ll sum = 0;
    for (int i = 0; i < n - k; i++) {
        sum += v.at(i);
    }
    for (int i = n - k; i < n; i++) {
        sum++;
    }
    cout << sum << endl;
    return 0;
}