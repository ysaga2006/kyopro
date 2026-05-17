#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m; cin >> n >> m;
    priority_queue<pair<ll, ll>> pq;
    ll sum = 0;
    while (n--) {
        ll f, d; cin >> f >> d;
        pq.push(make_pair(f, d));
    }
    while (m--) {
        ll val = pq.top().first;
        ll vad = pq.top().second;
        sum += val;
        pq.pop();
        pq.push(make_pair(max(val - vad, ll(0)), vad));
    }
    cout << sum << endl;
    return 0;
}