#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ll long long
using namespace std;

int main() {
    int h, w, n; cin >> h >> w >> n;
    vector<vector<int>> v(h, vector<int>(w)); rep(i, h) rep(j, w) cin >> v.at(i).at(j);
    vector<int> b(n); rep(i, n) cin >> b.at(i);
    vector<int> count(h);
    rep(i, h) {
        rep(j, n) {
            rep(k, w) {
                if (v.at(i).at(k) == b.at(j)) {
                    count.at(i) ++;
                }
            }
        }
    }
    cout << *max_element(count.begin(), count.end()) << endl;
    return 0;
}