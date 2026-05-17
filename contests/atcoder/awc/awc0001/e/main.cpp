#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k; cin >> n >> k;
    deque<ll> max_dq; // 最大値候補の気温を降順に、インデックスを昇順にもつ
    deque<ll> min_dq; // 最小値候補の気温を昇順に、インデックスを昇順にもつ
    vector<ll> h(n);
    for (ll i = 0; i < n; i++) {
        cin >> h.at(i);
    }
    ll max_diff = -1;
    for (ll i = 0; i < n; i++) {
        while (!max_dq.empty() && h.at(max_dq.back()) <= h.at(i)) {
            max_dq.pop_back();
        }
        max_dq.push_back(i);
        if (max_dq.front() <= i - k) {
            max_dq.pop_front();
        }

        while (!min_dq.empty() && h.at(min_dq.back()) >= h.at(i)) {
            min_dq.pop_back();
        }
        min_dq.push_back(i);
        if (min_dq.front() <= i - k) {
            min_dq.pop_front();
        }

        if (i >= k - 1) {
            ll upper = h.at(max_dq.front());
            ll lower = h.at(min_dq.front());
            max_diff = max(max_diff, (upper - lower));
        }
    }
    cout << max_diff << endl;
    return 0;
}