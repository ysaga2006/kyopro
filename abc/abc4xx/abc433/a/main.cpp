#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int x, y, z;
    int count = 0;
    cin >> x >> y >> z;
    rep(i, 10000) if ((x + i) == (y + i ) * z) count ++;
    if (count > 0) {
        cout << "Yes" << endl;
    }
    else {cout << "No" << endl;}
    return 0;
}