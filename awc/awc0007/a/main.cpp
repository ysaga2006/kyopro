#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m; cin >> n >> m;
    ll sum = 0;
    ll lower = 100100;
    while (n--) {
        ll e; cin >> e;
        lower = min(e, lower);
    }
    while (m--) {
        int c; cin >> c;
        sum += c;
    }
    cout << lower * sum << endl;
    return 0;
}