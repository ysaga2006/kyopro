#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
    int n, m, ans;
    cin >> n >> m;
    set<int> A;
    set<int> B;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (A.count(x) == 0 && B.count(y) == 0 && A.count(y) == 0 && B.count(x) == 0)
        {
            A.insert(x);
            B.insert(y);
        }
        if ((A.count(x) == 1 || B.count(y) == 1) && (A.count(y) == 0 && B.count(x) == 0))
        {
            A.insert(y);
            B.insert(x);
        }
        if ((A.count(x) == 0 && B.count(y) == 0) && (A.count(y) == 1 && B.count(x) == 1))
        {
            A.insert(x);
            B.insert(y);
        }
        if ((A.count(x) == 1 && B.count(y) == 1) || (A.count(y) == 1 && B.count(x) == 1))
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}