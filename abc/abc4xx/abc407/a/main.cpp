#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double a, b; cin >> a >> b;
    double div = a / b;
    int quo = a / b;
    // cout << fixed << setprecision(4) << div << " " << quo << endl;
    if (quo + 1 - div < div - quo) cout << quo + 1 << endl;
    else cout << quo << endl;
    return 0;
}