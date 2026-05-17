#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ll long long
using namespace std;

int main() {
    string s; cin >> s;
    if (s[0] != '#') {
        s[0] = 'o';
    }
    rep(i, int(s.size())) {
        if (s[i] == '#') {
            if (s[i + 1] != '#') {
                s[i + 1] = 'o';
            }
        } 
    }
    rep(i, int(s.size())) cout << s[i];
    cout << endl;
    return 0;
}