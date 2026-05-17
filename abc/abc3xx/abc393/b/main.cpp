#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    int cnt = 0;
    for (int i = 0; i < int(s.size()); i++) {
        if (s[i] == 'A') {
            for (int j = i; j < int(s.size()); j++) {
                if (s[j] == 'B') {
                    if (s[2 * j - i] == 'C') {
                        cnt++;
                    }
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}