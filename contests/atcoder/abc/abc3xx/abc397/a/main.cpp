#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double x; cin >> x;
    if (x >= 38.0) {
        cout << 1 << endl;
    }
    else if (37.5 <= x && x < 38.0) {
        cout << 2 << endl;
    }
    else if (x < 37.5) {
        cout << 3 << endl;
    }
    return 0;
}