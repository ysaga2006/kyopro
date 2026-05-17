#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q; cin >> q;
    int vol = 0;
    bool onoff = false;
    for (;q--;) {
        int a; cin >> a;
        if (a == 1) {
            vol++;
        }
        if (a == 2) {
            vol = max(0, vol - 1);
        }
        if (a == 3) {
            if (onoff == false) {
                onoff = true;
            } else {
                onoff = false;
            }
        }
        if (vol >= 3 && onoff == true) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';    
        }
    }
    return 0;
}