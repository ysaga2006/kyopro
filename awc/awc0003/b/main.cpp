#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<string> l(n);
    vector<string> r(n);
    for (int i = 0; i < n; i++) {
        cin >> l.at(i) >> r.at(i);
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (r.at(i) == l.at(i + 1)) {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}