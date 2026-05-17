#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    int count = 0;
    for (int i = 0; i < int(s.size()); i++) {
        if (s[i] == 'i' || s[i] == 'j') {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}