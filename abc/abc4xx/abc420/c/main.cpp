#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (n); ++i)
using namespace std;

int main()
{
    long long n, q;
    cin >> n >> q;
    vector<long long> vea(n + 1);
    rep(i, n) cin >> vea.at(i + 1);
    vector<long long> veb(n + 1);
    rep(i, n) cin >> veb.at(i + 1);
    long long sum = 0;
    rep(i, n) sum += min(vea.at(i + 1), veb.at(i + 1));

    rep(i, q)
    {
        char c;
        cin >> c;
        long long x, v;
        cin >> x >> v;
        if (c == 'A')
        {
            long long bea = vea.at(x);
            long long sub = v - vea.at(x);
            long long sab = vea.at(x) - veb.at(x);
            if (sab >= 0)
            {
                vea.at(x) = v;
                if (v <= veb.at(x))
                {
                    sum -= veb.at(x) - vea.at(x);
                }
            }
            if (sab < 0)
            {
                vea.at(x) = v;
                if (v <= veb.at(x))
                {
                    sum += sub;
                }
                if (v > veb.at(x))
                {
                    sum += veb.at(x) - bea;
                }
            }
        }
        if (c == 'B')
        {
            long long beb = veb.at(x);
            long long sub = v - veb.at(x);
            long long sab = veb.at(x) - vea.at(x);
            if (sab >= 0)
            {
                veb.at(x) = v;
                if (v <= vea.at(x))
                {
                    sum -= vea.at(x) - veb.at(x);
                }
            }
            if (sab < 0)
            {
                veb.at(x) = v;
                if (v <= vea.at(x))
                {
                    sum += sub;
                }
                if (v > vea.at(x))
                {
                    sum += vea.at(x) - beb;
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}