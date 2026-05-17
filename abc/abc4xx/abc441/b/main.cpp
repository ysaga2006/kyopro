#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    int q; cin >> q;
    for (;q--;) {
        string w; cin >> w;
        int cnttak = 0;
        int cntaok = 0;
        for (int i = 0; i < int(w.size()); i++) {
            for (int j = 0; j < n; j++) {
                if (w[i] == s[j]) {
                    cnttak++;
                }
            }
            for (int j = 0; j < m; j++) {
                if (w[i] == t[j]) {
                    cntaok++;
                }
            }
        }
        if (cntaok == int(w.size()) && cnttak == int(w.size())) {
            cout << "Unknown" << endl;
        }
        else if (cntaok == int(w.size())) {
            cout << "Aoki" << endl;
        }
        else if (cnttak == int(w.size())) {
            cout << "Takahashi" << endl;
        }
    }
    return 0;
}