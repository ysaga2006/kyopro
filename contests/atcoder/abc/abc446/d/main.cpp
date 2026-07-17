#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int ans = 0;
    unordered_map<int, int> dp;
    while (n--) {
        int a; cin >> a;
        dp[a] = dp[a - 1] + 1;
        ans = max(ans, dp[a]);
    }
    cout << ans << endl;
    return 0;
}
