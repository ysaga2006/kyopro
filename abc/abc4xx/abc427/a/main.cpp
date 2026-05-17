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
    int l;
    string s, s_f, s_l;
    cin >> s;
    l = s.size();
    s_f = s.substr(0, (l - 1) / 2);
    s_l = s.substr((l + 1) / 2);
    cout << s_f + s_l << endl;
    return 0;
}