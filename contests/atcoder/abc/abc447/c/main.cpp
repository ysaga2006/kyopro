#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t; cin >> s >> t;
    string u = s, v = t;
    erase_if(u, [](char c) {
        return c == 'A';
    });
    erase_if(v, [](char c) {
        return c == 'A';
    });
    if (u != v) {
        cout << -1 << endl;
    } else {
        vector<int> vs;
        vector<int> vt;
        int now = 0;
        for (int i = 0; i < int(s.size()); i++) {
            if (s[i] == 'A') {
                now++;
            } else {
                vs.push_back(now);
                now = 0;
            }
        }
        vs.push_back(now);
        now = 0;
        for (int i = 0; i < int(t.size()); i++) {
            if (t[i] == 'A') {
                now++;
            } else {
                vt.push_back(now);
                now = 0;
            }
        }
        vt.push_back(now);
        // for (auto t : vs) {
        //     cout << t << " " << endl;
        // }
        // for (auto t : vt) {
        //     cout << t << " " << endl;
        // }
        ll sum = 0;
        for (int i = 0; i < int(vs.size()); i++) {
            sum += abs(vs.at(i) - vt.at(i));
        }
        cout << sum << endl;
    }
    return 0;
}
