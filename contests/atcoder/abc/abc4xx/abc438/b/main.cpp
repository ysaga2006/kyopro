#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ll long long
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int ans = 10000000;
    rep(i, n - m + 1)
    {
        int count = 0;
        rep(l, m)
        {
            count += (int(s[i + l] - '0') + 10 - int(t[l] - '0')) % 10;
        }
        if (count < ans)
        {
            ans = count;
        }
    }
    cout << ans << endl;
    return 0;
}