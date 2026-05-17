#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define ll long long
using namespace std;

int main()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> sum(n + 1);
    rep(i, n) cin >> sum.at(i);
    rep(i, n) sum.at(i + 1) += sum.at(i);
    ll sumc = 0;
    rep(qi, q)
    {
        ll num;
        cin >> num;
        if (num == 1)
        {
            ll c;
            cin >> c;
            sumc += c;
        }
        else if (num == 2)
        {
            ll l, r;
            cin >> l >> r;
            l--;
            r--;
            l += sumc;
            r += sumc;
            l = l % n;
            r = r % n;
            ll res = 0;
            if (l == 0)
            {
                res = sum.at(r);
            }
            else if (l > r)
            {
                res = sum.at(n - 1) - sum.at(l - 1) + sum.at(r);
            }
            else if (l <= r)
            {
                res = sum.at(r) - sum.at(l - 1);
            }
            cout << res << endl;
        }
    }
}