#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ll long long
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n + 1); rep(i, n) cin >> a.at(i + 1);
    vector<int> ap(n + 1); rep(i, n) ap.at(i + 1) = a.at(i + 1) + (i + 1);
    vector<int> am(n + 1); rep(i, n) am.at(i + 1) = -a.at(i + 1) + (i + 1);
    
    return 0;
}