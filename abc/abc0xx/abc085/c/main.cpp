#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ll long long
using namespace std;

int main()
{
    int n, y;
    cin >> n >> y;
    int a = -1, b = -1, c = -1;
    int m = (y / 1000) - n;
    rep(i, (m / 4) + 1)
    {
        if ((m - 4 * i) % 9 == 0)
        {
            b = i;
            a = (m - 4 * i) / 9;
            c = n - a - b;
            if (c >= 0)
            {
                break;
            }
            if (c < 0)
            {
                a = -1;
                b = -1;
                c = -1;
            }
        }
    }
    cout << a << " " << b << " " << c << endl;
    return 0;
}