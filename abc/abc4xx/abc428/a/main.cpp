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

int main() {
    int s, a, b, x;
    cin >> s >> a >> b >> x;
    if (x % (a + b) >= a) {
        cout << (x / (a + b)) * a * s + a * s << endl;
    }
    else {
        cout << (x / (a + b)) * a * s + (x % (a + b)) * s << endl;
    }
    return 0;
}