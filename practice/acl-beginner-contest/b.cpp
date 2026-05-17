#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b, c, d; cin >> a >> b >> c >> d;
    cout << (max(a, c) <= min(b, d) ? "Yes" : "No") << endl;
    return 0;
}