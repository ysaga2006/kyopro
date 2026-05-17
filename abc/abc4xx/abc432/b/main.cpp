#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main()
{
    int x;
    cin >> x;
    vector<int> vec(0);
    int y = x;
    int count = 0;
    while (y != 0)
    {
        vec.push_back(y % 10);
        if (y % 10 == 0)
            count++;
        y /= 10;
    }
    int l = vec.size();
    if (count == 0)
    {
        sort(vec.begin(), vec.end());
        rep(i, l) cout << vec.at(i);
        cout << endl;
    }
    else
    {
        sort(vec.begin(), vec.end());
        cout << vec.at(count);
        rep(i, count) cout << "0";
        rep(i, l - 1 - count) cout << vec.at(i + 1 + count);
        cout << endl;
    }
    return 0;
}