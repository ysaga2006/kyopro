#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ll long long
using namespace std;

int main() {
    int q; cin >> q;
    const int INF = 1001001001;
    vector<int> v = {0};
    rep(i, q) {
        int n; cin >> n;
        if (n == 1) {
            char c; cin >> c;
            int nc = v.back() + (c == '(' ? +1 : -1);
            if (nc < 0) {
                nc = -INF;
            }
            v.push_back(nc);
        }
        else {
            v.pop_back();
        }
        if (v.back() == 0) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}