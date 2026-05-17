#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    struct human {
        ll id;
        ll score;
    };

    ll n; cin >> n;
    vector<human> v(n);
    for (int i = 0; i < n; ++i) {
        ll num; cin >> num;
        v[i].id = i;
        v[i].score = num;
    };

    sort(v.begin(), v.end(), [](const human& a, const human& b) {
        if (a.score == b.score) {
            return (a.id < b.id);
        } else {
            return (a.score > b.score);
        }
    });

    vector<ll> ans(n); // 人iの順位をもつ。
    ll now = 0, pre = 0, cnt = 0, r = 1;
    for (int i = 0; i < n; ++i) {
        now = v[i].score;
        if (now == pre) {
            cnt++;
            r--;
            ans[v[i].id] = r;
            r++;
        } else {
            ans[v[i].id] = r + cnt;
            r++;
            r += cnt;
            cnt = 0;
        }
        pre = now;
    }
    for (auto ele : ans) {
        cout << ele << '\n';
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    struct Human {
        ll score;
        int id;
    };

    int n; cin >> n;
    vector<Human> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].score;
        v[i].id = i;
    }

    sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
        return a.score != b.score ? a.score > b.score : a.id < b.id;
    });

    vector<ll> ans(n);  // ans[i] = 人iの順位
    for (int i = 0; i < n; ++i) {
        ans[v[i].id] = (i > 0 && v[i].score == v[i - 1].score)
                           ? ans[v[i - 1].id]
                           : i + 1;
    }

    for (ll r : ans) cout << r << '\n';
    return 0;
}
*/
