#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    ll res = 1;
    ll upp = 1;
    for (int i = 0; i < k; i++) {
        upp *= 10;
    }
    upp -= 1;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v.at(i);
    }
    for (int i = 0; i < n; i++) {
        if (v.at(i) > upp / res) {
            res = 1;
        } else {
            res *= v.at(i);
        }
    }
    cout << res << endl;
    return 0;
}
