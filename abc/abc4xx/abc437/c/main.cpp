#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define ll long long
using namespace std;

int main()
{
    ll t;
    cin >> t;
    rep(qi, t)
    {
        ll n;
        cin >> n;
        ll sum = 0;
        vector<ll> v(n);
        rep(i, n)
        {
            ll w, p;
            cin >> w >> p;
            sum += p;
            v.at(i) = w + p;
        }
        sort(v.begin(), v.end());
        ll ans = 0;
        rep(i, n)
        {
            ans += v.at(i);
            if (ans > sum)
            {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}