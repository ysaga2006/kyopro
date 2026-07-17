#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> hidari(n);
    vector<int> migi(n);
    set<int> left;
    set<int> right;
    for (int i = 0; i < n; i++) {
        left.insert(v[i]);
        hidari[i] = left.size();
    }
    for (int i = 0; i < n; i++) {
        right.insert(v[n - i - 1]);
        migi[i] = right.size();
    }
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        cout << hidari[i] << " " << migi[n - i] << endl;
        ans = max(ans, hidari[i] + migi[n - i]);
        cout << ans << " ";
    }
    cout << endl;
    cout << ans << endl;
    return 0;
}
