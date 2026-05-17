#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ll long long
using namespace std;

int main() {
    int n; cin >> n;
    string s;
    rep(i, n) {
        char c; int l; cin >> c >> l;
        if (l > 100) {
            cout << "Too Long" << endl;
            break;
        }
        rep(j, l) {
            s += c;
        }
        if (int(s.size()) > 100) {
            cout << "Too Long" << endl;
            break;
        }
    }
    if (int(s.size() <= 100)) cout << s << endl;
    return 0;
}