#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> v(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> v.at(i);
    }
    while (m--) {
    int b; cin >> b;
    v.at(b - 1)++; v.at(b)++; v.at(b + 1)++;
    }
    for (int i = 1; i <= n; i++) {
        cout << v.at(i) << " ";
    }
    cout << endl;
    return 0;
}