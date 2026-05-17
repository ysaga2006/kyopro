#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ll long long
using namespace std;

int main() {
    string s; cin >> s;
    vector<double> l;
    double ans = 0;
    rep(i, double(s.size())) {
        if (s[i] == 't') {
            l.push_back(i);
        }
    }
    rep(i, double(l.size())) rep(j, i) {
        if (l.at(i) - l.at(j) >= 2) {// ここを3にしていた
            double count = 0;
            for (double k = l.at(j); k < l.at(i) + 1; k++) {
                if (s[k] == 't') {
                    count++;
                }
            }
            double f = (count - 2) / (l.at(i) - l.at(j) + 1 - 2);
            if (f > ans) {
                ans = f;
            }
        }
    }
        
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}