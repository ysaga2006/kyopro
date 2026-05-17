#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ans = 100100;
    int n; cin >> n;
    vector<string> s(n);
    vector<string> t(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] != t[i][j]) cnt++;
        }
    }
    ans = min(ans, cnt);
    cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[n - 1 - j][i] != t[i][j]) cnt++;
        }
    }
    ans = min(ans, cnt + 1);
    cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[(n - 1 - i)][(n - 1 - j)] != t[i][j]) cnt++;
        }
    }
    ans = min(ans, cnt + 2);
    cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[j][(n - 1 - i)] != t[i][j]) cnt++;
        }
    }
    ans = min(ans, cnt + 3);
    cout << ans << endl;
    return 0;
}
