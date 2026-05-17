#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main()
{
    long long n, l;
    cin >> n;
    vector<long long> vec(2 * n + 1);
    for (int i = 1; i < n + 1; i++)
    {
        cin >> vec.at(i);
    }
    for (int i = 1; i < n + 1; i++)
    {
        vec.at(i) += i - 1;
    }
    l = vec.at(1);
    for (int i = 2; i < n + 1; i++)
    {
        if (i > l)
        {
            break;
        }
        l = max(l, vec.at(i));
    }
    cout << min(l, n) << endl;
    return 0;
}