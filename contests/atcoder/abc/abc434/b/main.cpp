#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<double> type(m);
    vector<double> weisum(m);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        type.at(a - 1) ++;
        weisum.at(a - 1) += b;
    }
    rep(i, m) cout << fixed << setprecision(6) << weisum.at(i) / type.at(i) << endl;
    return 0;
}