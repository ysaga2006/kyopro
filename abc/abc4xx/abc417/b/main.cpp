#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ll long long
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a.at(i);
    rep(i, m)
    {
        int b;
        cin >> b;
        rep(j, int(a.size()))
        {
            if (a.at(j) == b)
            {
                a.erase(a.begin() + j);
                break;
            }
        }
    }
    rep(i, int(a.size())) { cout << a.at(i) << " "; }
    cout << endl;
    return 0;
}