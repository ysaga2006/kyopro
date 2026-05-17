#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    int upp = 0;
    for (;n--;) {
        int a, b; cin >> a >> b;
        int val = (m - a + b - 1) / b;
        upp = max(upp, val);
    }
    cout << upp << '\n';
    return 0;
}