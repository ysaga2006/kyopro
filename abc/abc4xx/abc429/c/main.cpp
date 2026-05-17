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
    const int N = 200000;
    long long n;
    long long ans = 0;
    cin >> n;
    vector<long long> v(N);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.at(x - 1)++;
    }
    for (int i = 0; i < N; i++)
    {
        ans += (v.at(i) * (v.at(i) - 1) / 2) * (n - v.at(i));
    }
    cout << ans << endl;
    return 0;
}