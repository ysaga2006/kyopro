#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define ll long long
using namespace std;

int main()
{
    ll n, q;
    cin >> n >> q;
    const ll ma = pow(10, 6) + 2;
    vector<ll> sum(ma);
    vector<ll> cnt(ma);
    rep(i, n)
    {
        ll a;
        cin >> a;
        cnt.at(a)++;
        sum.at(a) += a;
    }
    rep(i, ma - 1)
    {
        cnt.at(i + 1) += cnt.at(i);
        sum.at(i + 1) += sum.at(i);
    }
    rep(i, q)
    {
        ll b;
        cin >> b;
        if (1 + sum.at(b - 1) + ((b - 1) * (n - cnt.at(b - 1))) > sum.at(ma - 1))
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << 1 + sum.at(b - 1) + ((b - 1) * (n - cnt.at(b - 1))) << endl;
        }
    }
}