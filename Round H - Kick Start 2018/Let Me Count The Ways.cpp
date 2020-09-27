#include <bits/stdc++.h>
#define ll long long
#define maxn 200005
#define MOD 1000000007

using namespace std;

ll f[maxn], finv[maxn];

ll power(ll a, ll b){
    if(b==0) return 1;
    if(b==1) return a;
    ll res = power(a, b/2);
    res = (res*res)%MOD;
    if(b%2==1) res = (res*a)%MOD;
    return res;
}

ll inv(ll a){
    return power(a, MOD-2);
}

void precom(){
    f[0] = 1;
    finv[0] = 1;
    for(ll i = 1; i < maxn; i++){
        f[i] = (f[i-1]*i)%MOD;
        finv[i] = (finv[i-1]*inv(i))%MOD;
    }
}

ll P(ll a, ll b){
    return (f[a]*finv[a-b])%MOD ;
}

ll C(ll a, ll b){
    return (P(a,b)*finv[b])%MOD;
}

int main(){
    precom();
    ll t; cin >> t; for(ll tc=0; tc < t; tc++){
        ll n, m;
        cin >> n >> m;
        ll ans = f[n*2], b = -1;
        for(ll i = 1; i <= m; i++){
            // x = (n*2-i*2+i);
            //ans(i) =  mCi * xPi * 2^i * (n*2-i*2)!
            ll x = (n*2-i*2+i);
            ll ai = (((C(m, i) * P(x, i))%MOD* power(2, i))%MOD* f[n*2-i*2])%MOD;
            ai = ai*b;
            ans = (ans + ai)%MOD;
            if(ans<0) ans += MOD;
            b = -b;
        }
        cout << "Case #" << tc+1 << ": " << ans << endl;
    }

}
