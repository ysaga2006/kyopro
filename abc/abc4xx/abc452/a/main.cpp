#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ll> a = {1, 3, 5, 7 ,9};
    vector<ll> b = {7, 3, 5, 7, 9};
    ll m, d; cin >> m >> d;

    for (int i = 0; i < 5; ++i) {
        if (a[i] == m && b[i] == d) {
            cout << "Yes" << '\n';
            return 0;
        }
    }
    cout << "No" << '\n';
    return 0;
}
