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
    int n, m, k;
    cin >> n >> m >> k;
    map<int, int> counts;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        counts[a]++;
        if (counts[a] == m)
        {
            cout << a << " ";
        }
    }
    cout << endl;
    return 0;
}