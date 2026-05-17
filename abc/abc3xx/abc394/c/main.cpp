#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    stack<int> st;
    bool w = false;
    int cnt = 0;
    for (int i = 0; i < int(s.size()); i++) {
        if (s[i] == 'W') {
            if (w == true) {
                cnt++;
            } else {
                w = true;
            }
        } else if (s[i] == 'A') {
            if (w == true) {
                w = false;
                
            } else {

            }
        }
    }
    return 0;
}
