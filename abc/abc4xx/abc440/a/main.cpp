#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y; cin >> x >> y;
    for (int i = 0; i < y; i++) {
        x *= 2;
    }
    cout << x << endl;
    return 0;
}