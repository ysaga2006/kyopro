#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<bool> v(m, true);
    while (n--) {
        int l; cin >> l;
        vector<int> b(l + 1);
        for (int i = 0; i < l; i++) {       
            cin >> b.at(i); b.at(i)--;
        }
        for (int i = 0; i < l + 1; i++) {
            if (i == l) {
                cout << 0 << '\n';
            } else if (v.at(b.at(i)) == true) {
                v.at(b.at(i)) = false;
                cout << b.at(i) + 1 << '\n';
                break;
            }
        }
    }
    return 0;
}
