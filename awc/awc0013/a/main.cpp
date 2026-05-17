#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b, c; cin >> a >> b >> c;
    cout << max(b - a, ll(0)) * c << endl;
    return 0;
}