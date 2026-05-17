#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;

    ll ans = 0;

    while (s != "") {
        ll n = s.size();
        if (s[n - 1] == '0' && s[n - 2] == '0') {
            s.pop_back();
            s.pop_back();
            ans++;
        } else {
            s.pop_back();
            ans++;
        }
    }

    cout << ans << endl;
    
    return 0;
}
