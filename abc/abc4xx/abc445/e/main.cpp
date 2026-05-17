#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const ll MOD = 998244353;
    ll t; cin >> t;
    for (;t--;) {
        ll n; cin >> n;
        vector<ll> v(n);
        ll mul = 1;
        for (ll i = 0; i < n; i++) {
            cin >> v.at(i);
            mul *= (v.at(i) % MOD);
            mul %= MOD;
        }
        cout << mul << endl;
        for (ll i = 0; i < n; i++) {
            ll val = mul * modinv(v.at(i), MOD) % MOD;
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}