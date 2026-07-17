#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m; cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    vector<ll> deg(n + 1, 0);
    for (int i = 0; i < m; i++) {
        ll a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }

    bool ok = true;
    for (ll i = 1; i <= n; i++) {
        if (deg[i] != 2) {
            ok = false;
        }
    }

    if (ok) {
        vector<bool> visited(n + 1, false);
        queue<ll> q;
        q.push(1);
        visited[1] = true;
        ll count = 0;
        while(!q.empty()) {
            ll u = q.front(); q.pop();
            count++;
            for(auto &nx : adj[u]) {
                if(!visited[nx]) {
                    visited[nx] = true;
                    q.push(nx);
                }
            }
        }
        if (count != n) ok = false;
    }

    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}