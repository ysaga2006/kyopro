#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ll long long
using namespace std;

int main() {
    int n, l, r; cin >> n >> l >> r;
    string s; cin >> s;
    bool ok = true;
    for (int i = l - 1; i < r; i++) {
        if (s[i] != 'o') ok = false;
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}