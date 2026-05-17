#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    int ans = (x + y) % 12;
    if (ans == 0)
    {
        cout << "12" << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}