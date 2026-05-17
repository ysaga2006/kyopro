#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ll long long
using namespace std;

int main()
{
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    set<pair<ll, ll>> occ;
    rep(i, m)
    {
        ll r, c;
        cin >> r >> c;
        vector<pair<ll, ll>> tar = {
            {r, c},
            {r, c + 1},
            {r + 1, c},
            {r + 1, c + 1}};
        bool can = true;
        for (auto cel : tar)
        {
            if (occ.count(cel))
            {
                can = false;
                break;
            }
        }
        if (can)
        {
            for (auto cel : tar)
            {
                occ.insert(cel);
            }
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}