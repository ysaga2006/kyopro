#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m; cin >> n >> m;
    const ll UPP = 1001001001001001000;
    vector<ll> v(UPP);
    while (m--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        v.at(l)++;
        v.at(r + 1)--;
    }
    for (int i = 0; i < UPP - 1; i++) {
        v.at(i + 1) += v.at(i);
    }
    
    return 0;
}