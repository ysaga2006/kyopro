#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int n, m;
    set<string> pat;
    cin >> n >> m;
    vector<string> vec(n);
    rep(i, n) cin >> vec.at(i);
    rep(i, n - m + 1) {
        rep(j, n - m + 1) {
            string squ;
            rep(k, m) {
                squ += vec.at(i + k).substr(j, m);
            }
            pat.insert(squ);
        }
    }
    cout << pat.size() << endl;
    return 0;
}

