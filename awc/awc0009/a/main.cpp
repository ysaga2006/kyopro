#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k, m; cin >> k >> m;
    ll sum = 0;
    while (k--) {
        int l; cin >> l;
        sum += l;
    }
    cout << sum % m << endl;
    return 0;
}