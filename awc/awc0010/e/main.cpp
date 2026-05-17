#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k; cin >> n >> k;
    vector<vector<ll>> v(n, vector<ll>(n)); // 集客効果
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v.at(i).at(j);
        }
    }
    vector<ll> p(n); // 順列
    iota(p.begin(), p.end(), 0);
    ll ans = -1; // 最大値 
    do { // 全探索する
        ll cyc = 0; // サイクル数をカウント
        vector<bool> b(n, false); // 訪問済みかどうか
        for (int i = 0; i < n; i++) { // サイクル数の計算
            if (b.at(i) == false) {
                cyc++;
                ll now = i;
                while (b.at(now) == false) {
                    b.at(now) = true;
                    now = p.at(now);
                }
            }
        }
        if (n - cyc <= k) {
            ll sum = 0;
            for (int i = 0; i < n; i++) {
                sum += v.at(p.at(i)).at(p.at((i + 1) % n));
            }
            ans = max(ans, sum);
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << endl;
    return 0;
}