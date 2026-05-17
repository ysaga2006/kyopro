#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> p(n), q(n), z(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
    }
    for (int i = 0; i < n; i++) {
        int Q; cin >> Q; Q--;
        q[i] = Q;
        z[Q] = i;
    }
    for (int i = 0; i < n; i++) {
        cout << q[p[z[i]]] + 1 << " ";
    }
    cout << endl;
    return 0;
}
    // 人iがつけているゼッケンのインデックスをq[i]でもつ。
    // ゼッケンiをつけている人のインデックスをz[i]でもつ。
    // 人iが見つめている人のインデックスをp[i]でもつ。
    // q[p[z[i]]]
