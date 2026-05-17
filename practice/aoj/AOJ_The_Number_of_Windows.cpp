#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ll long long
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    vector<ll> a(n); rep(i, n) cin >> a.at(i);
    
    rep(qi, q) {
        ll x; cin >> x;
        ll res = 0;
        int right = 0;
        ll sum = 0;
        rep(left, n) {
            while (right < n && sum + a.at(right) <= x) {
                sum += a.at(right);
                right++;
            }
            res += (right - left);
            if (left == right) right++;
            else sum -= a.at(left);
        }
    }
    return 0;
}