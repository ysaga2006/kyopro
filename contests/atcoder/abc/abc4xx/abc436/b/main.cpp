#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));

    v.at(0).at((n - 1) / 2) = 1;
    int r = 0, c = ((n - 1) / 2), k = 1;
    for (int i = 0; i < (n * n - 1); i++)
    {
        if (v.at((r - 1 + n) % n).at((c + 1 + n) % n) == 0)
        {
            v.at((r - 1 + n) % n).at((c + 1 + n) % n) = k + 1;
            k++;
            r = (r - 1) % n;
            c = (c + 1) % n;
        }
        else if (v.at((r - 1 + n) % n).at((c + 1 + n) % n) != 0)
        {
            v.at((r + 1 + n) % n).at(c) = k + 1;
            k++;
            r = (r + 1) % n;
        }
    }
    rep(i, n)
    {
        rep(j, n)
        {
            cout << v.at(i).at(j) << " ";
        }
        cout << endl;
    }
    return 0;
}