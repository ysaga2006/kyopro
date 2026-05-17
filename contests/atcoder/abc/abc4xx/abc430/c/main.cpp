#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main()
{
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;
    vector<int> sa(n + 1);
    vector<int> sb(n + 1);
    rep(i, n)
    {
        sa.at(i + 1) = sa.at(i) + (s.at(i) == 'a');
        sb.at(i + 1) = sb.at(i) + (s.at(i) == 'b');
    }

    ll ans = 0;

    for (int l = 1; l <= n; l++)
    {
        int ta = sa.at(l - 1) + a;
        int tb = sb.at(l - 1) + b;
        auto it1 = lower_bound(sa.begin() + l, sa.end(), ta);     // ta以上なる最小の〜文字目のイテレータ
        auto it2 = lower_bound(sb.begin() + l, sb.end(), tb) - 1; // tb未満なる最大の〜文字のイテレータ
        if (it1 == sa.end())
            continue;
        int r1 = distance(sa.begin(), it1);
        int r2 = distance(sb.begin(), it2);
        ans += max(0, r2 - r1 + 1);
    }
    cout << ans << endl;
    return 0;
}