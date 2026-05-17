#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a; cin >> a;

    if (400 % a == 0) {
        cout << 400 / a << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}