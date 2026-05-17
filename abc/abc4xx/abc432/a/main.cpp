#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main()
{
    vector<int> vec(3);
    rep(i, 3) cin >> vec.at(i);
    sort(vec.begin(), vec.end());
    rep(i, 3) cout << vec.at(2 - i);
    cout << endl;
    return 0;
}