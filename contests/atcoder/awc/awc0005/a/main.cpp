#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        if (p % k == 0) {
            sum += p;
        }
    }
    cout << sum << '\n';
    return 0;
}