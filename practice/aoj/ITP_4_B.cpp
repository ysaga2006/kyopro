#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double r;
    cin >> r;
    cout << fixed << setprecision(6) << r * r * 3.14159265358979 << " " << fixed << setprecision(6) << 2 * 3.14159265358979 * r << endl;
}