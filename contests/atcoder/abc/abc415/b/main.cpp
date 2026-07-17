#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ll long long
using namespace std;

int main() {
    string s; cin >> s;
    vector<int> v;
    rep(i, int(s.size())) {
        if (s[i] == '#') v.push_back(i + 1);
    }
    rep(i, int(v.size() / 2)) {
        cout << v.at(2 * i) << "," << v.at(2 * i + 1) << endl;
    }
    return 0;
}