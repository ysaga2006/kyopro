#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (c >= a && d < b)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}