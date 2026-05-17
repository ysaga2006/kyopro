#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set<ll> st;

    for (ll i = 0; i < 4; ++i) {
        ll a; cin >> a;
        st.insert(a);
    }
    
    if (st.size() == 2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
