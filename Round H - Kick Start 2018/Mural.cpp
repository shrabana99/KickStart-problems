#include <bits/stdc++.h>
#define ll long long
#define maxn 101
using namespace std;

int main(){
    ll t; cin >> t; for(ll tc=0; tc < t; tc++){
        ll n;
        cin >> n;
        string s; cin >> s;
        ll pre[n+1];
        memset(pre, 0, sizeof(pre));
        for(ll i =1; i<= n; i++){
            pre[i] = pre[i-1] + s[i-1]- '0';
        }
        ll ans = 0;
        ll k = (n+1)/2;
        for(ll i =1; i<= n; i++){
           if(i-k>=0){
                ans = max(ans, pre[i] - pre[i-k]);
            }
        }
        cout << "Case #" << tc+1 << ": " << ans << endl;
    }

}
