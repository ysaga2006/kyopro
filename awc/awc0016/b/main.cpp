#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t; cin >> n >> t;
    ll sum = 0;
    while (n--) {
        int a, c; cin >> a >> c;
        sum += max(0, (t - a) * c);
    }
    cout << sum << endl;
    return 0;
}