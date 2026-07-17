#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<string> s(n);
    vector<string> t(m);
    for (int i = 0; i < n; i++) {
        string w; cin >> w;
        s.at(i) = w;
    }
    for (int i = 0; i < m; i++) {
        string w; cin >> w;
        t.at(i) = w;
    }
    // 左上のグリッドを(i, j)でfor文を回す。
    // Tのk(0 < k < m)行目とSの(i + k)行目のj文字目からm文字が等しいかをチェック
    // cntを持って、mだったらその時点でYesを出力
    for (int i = 0; i < n - m; i++) {
        for (int j = 0; j < n - m; j++) {
            int cnt = 0;
            for (int k = 0; k < m; k++) {
                if (t.at(k) == s.at(i + k).substr(j, m)) cnt++;
            }
            if (cnt == m) {
                cout << i << j << '\n';
            }
        }
    }
    return 0;
}
