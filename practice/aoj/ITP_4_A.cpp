#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    int a, b, d, r;
    double f;
    cin >> a >> b;
    d = a / b;
    r = a % b;
    f = (double)a / (double)b;
    cout << d << " " << r << " " << fixed << setprecision(9) << f << endl;
}