#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> v(n + 1);
    for (int i = 0; i < m; i++) {
        int a; cin >> a;
        v.at(a)++;
    }
    int cnt = 0;
    for (int i = 1; i < n + 1; i++) {
        if (v.at(i) == 0) {
            cnt++; 
        }
    }
    cout << cnt << endl;
    for (int i = 1; i < n + 1; i++) {
        if (v.at(i) == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}