#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> v(3);
    string s; cin >> s;
    for (int i = 0; i < int(s.size()); i++) {
        if (s[i] == 'A') {
            v.at(0)++;
        } else if (s[i] == 'B') {
            if (v.at(0) != 0) {
                v.at(0)--;
                v.at(1)++;
            }
        } else if (s[i] == 'C') {
            if (v.at(1) != 0) {
                v.at(1)--;
                v.at(2)++;
            }
        }
    }
    cout << v.at(2) << endl;
    return 0;
}
