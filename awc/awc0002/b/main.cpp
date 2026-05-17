#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    ll sum = 0;
    int ans = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a.at(i);
    vector<int> b(m);
    for (int i = 0; i < m; i++) {cin >> b.at(i); b.at(i)--;}
    for (int i = 0; i < m; i++) {
        if (a.at(b.at(i)) < k) {
            ans++; sum += a.at(b.at(i));
        }
    }
    cout << ans << " " << sum << '\n';
    return 0;
}