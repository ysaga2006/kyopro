#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

ll powmod(ll a, ll n, ll mod){ll res=1; a%=mod; while(n){if(n&1) res=res*a%mod; a=a*a%mod; n>>=1;} return res;}
ll gyakugen(ll a, ll mod){return powmod(a, mod-2, mod);}
ll kaizyo(ll n, ll mod){ll res=1; for(ll i=1;i<=n;i++) res=res*i%mod; return res;}
ll conbi(ll n, ll m){return (kaizyo(n, MOD) * gyakugen((kaizyo(m, MOD) * kaizyo((n - m), MOD)), MOD));}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  ll x, y, z; cin >> x >> y >> z;
  ll ans = 0;

  for (ll i = 0; i < min(y, 2 * min(x, z)); ++i) { // 切り替わりの数
    ll cnt = 0, run = i + 1;
    cnt += conbi(x - 1, ((run + 1) / 2) - 1) * conbi(z - 1, (run / 2) - 1) % MOD;
    cnt += conbi(x - 1, (run / 2) - 1) * conbi(z - 1, ((run + 1) / 2) - 1) % MOD;

    ans += cnt * conbi(x + y + z - i, x + z) % MOD;

  }
  
  cout << ans << '\n';
  return 0;
}
