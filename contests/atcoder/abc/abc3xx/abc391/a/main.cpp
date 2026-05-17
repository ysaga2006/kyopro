#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string d; cin >> d;
    if (d == "N") cout << "S" << '\n';
    if (d == "S") cout << "N" << '\n';
    if (d == "W") cout << "E" << '\n';
    if (d == "E") cout << "W" << '\n';
    if (d == "NE") cout << "SW" << '\n';
    if (d == "SW") cout << "NE" << '\n';
    if (d == "NW") cout << "SE" << '\n';
    if (d == "SE") cout << "NW" << '\n';
    return 0;
}
