#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> before(m);
    vector<int> after(m);
    while (n--) {
        int a, b; cin >> a >> b; a--; b--;
        before.at(a)++;
        after.at(b)++;
    }
    for (int i = 0; i < m; i++) {
        cout << after.at(i) - before.at(i) << endl;
    }
    return 0;
}
