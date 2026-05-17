#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> cnt(n + 1);
    int upp = 1 + sqrt(n) / 1;
    rep(i, upp) rep(j, i) {
        int val = ((i + 1) * (i + 1)) + ((j + 1) * (j + 1));
        if (val <= n) {
            cnt.at(val)++;
        }
    }
    int ans = 0;
    rep(i, n + 1) {
        if (cnt.at(i) == 1) {
            ans++;
        }
    }
    cout << ans << "\n";
    rep(i, n + 1) {
        if (cnt.at(i) == 1) {
            cout << i << " ";
        }
    }
    cout << "\n";
    return 0;
}