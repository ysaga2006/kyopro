#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    map<char, int> mp;
    int upp = 0;
    for (int i = 0; i < int(s.size()); i++) {
        mp[s[i]]++;
        upp = max(mp[s[i]], upp);
    }
    set<char> st;
    for (int i = 0; i < int(s.size()); i++) {
        if (mp[s[i]] == upp) {
            st.insert(s[i]);
        }
    }
    for (int i = 0; i < int(s.size()); i++) {
        if (1 - st.contains(s[i])) {
            cout << s[i];
        }
    }
    cout << endl;
    return 0;
}
