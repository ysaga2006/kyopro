#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    string t, a; cin >> t >> a;
    bool ok = false;
    for (int i = 0; i < n; i++) {
        if (t[i] == 'o' && a[i] == 'o') {
            ok = true;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}