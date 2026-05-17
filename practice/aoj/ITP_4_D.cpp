#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;
 
int main() {
    long long n, m, s, a;
    a = 0;
    m = -1000000;
    s = 1000000;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec.at(i);
    }
    for (int j = 0; j < n; j++) {
        if (vec.at(j) >= m) {
            m = vec.at(j);
        }
        if (vec.at(j) <= s) {
            s = vec.at(j);
        }
        a = a + vec.at(j);
    }
    cout << s << " " << m << " " << a << endl;
}