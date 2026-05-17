#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int ans = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v.at(i);
    }
    for (int i = 0; i < 101; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (v.at(j) >= i) {
                cnt++;
            }
        }
        if (cnt >= i && ans < i) {
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}