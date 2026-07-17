#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ll long long
using namespace std;

int main()
{
    int d, f;
    cin >> d >> f;
    while (d >= f)
    {
        f += 7;
    }
    cout << f % d << endl;
    return 0;
}