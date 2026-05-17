#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s, t; cin >> n >> s >> t;
    int sum = 0;
    for (;n--;) {
        int a; cin >> a;
        sum += a;
    }
    if (sum <= (t - s) * 60) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
    return 0;
}