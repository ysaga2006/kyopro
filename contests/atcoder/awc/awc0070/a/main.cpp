#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll now = 0, next = 0;

    ll n, y, m; cin >> n >> y >> m;
    while (n--) {
        ll a, b, p, q, c; cin >> a >> b >> p >> q >> c;
        if (p == y && q == m) now += c;
        else if (p * 12 + q == y * 12 + m + 1) next += c;
    }

    cout << now << " " << next << '\n';

    return 0;
    
}
