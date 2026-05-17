#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    ll sum = 0;
    vector<int> v(m);
    for (int i = 0; i < m; i++) {
        cin >> v.at(i);
    }
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        a--;
        sum += min(b, v.at(a));
        v.at(a) -= min(b, v.at(a));
    }
    cout << sum << endl;
    return 0;
}
