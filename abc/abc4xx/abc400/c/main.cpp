#include <bits/stdc++.h>sw
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    ll div2 = sqrt(n / 2) / 1;
    ll div4 = sqrt(n / 4) / 1;
    if ((div2 + 1) * (div2 + 1) <= n / 2) {
        div2 += 1;
    }
    if ((div4 + 1) * (div4 + 1) <= n / 4) {
        div4 += 1;
    }
    if (div2 * div2 > n / 2) {
        div2 -= 1;
    }
    if (div4 * div4 > n / 4) {
        div4 -= 1;
    }
    cout << div2 + div4 << endl; 
    return 0;
}