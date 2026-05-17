#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m; cin >> n >> m;
    set<pair<ll, ll>> st;
    vector<pair<ll, ll>> v;
    while (m--) {
        ll a, b; cin >> a >> b;
        st.insert(make_pair(min(a, b), max(a, b)));
        v.emplace_back((make_pair(min(a, b), max(a, b))));
    }
    cout << v.size() - st.size() << endl;
    return 0;
}