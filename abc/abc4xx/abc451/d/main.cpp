#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector good(10, set<ll>{}); // i桁の良い整数をもつ
    vector beki(10, vector<ll>{}); // i桁の2の冪乗をもつ
    vector<ll> ten(11); // 10のi乗、i+1桁の数をもつ

    ll num = 1; // tenの初期化
    for (int i = 0; i <= 10; i++) {
        ten[i] = num;
        num *= 10;
    }

    num = 1; // bekiの計算
    for (int i = 0; i < 10; i++) {
        while (num < ten[i]) {
            beki[i].push_back(num);
            num *= 2;
        }
    }

    good[0].insert(0);
    
    for (int i = 1; i < 10; i++) {
        for (auto ele : beki[i]) {
            good[i].insert(ele);
        }
    }

    for (int i = 1; i <= 9; i++) { // i桁の良い整数を作る
        for (int j = 1; j <= i; j++) {
            for (auto num : good[j]) {
                for (auto bek : beki[i - j]) {
                    good[i].insert(num * ten[i - j] + bek);
                }
            }
        }
    }

    vector<ll> result{};
    for (int i = 0; i < 10; i++) {
        for (auto ele : good[i]) {
            result.emplace_back(ele);
        }
    }

    sort(result.begin(), result.end());

    int n; cin >> n;
    cout << result[n] << endl;
    return 0;
}