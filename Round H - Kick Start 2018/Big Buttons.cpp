#include <bits/stdc++.h>
#define ll long long
#define maxn 101
using namespace std;


ll power(ll a, ll b){
    if(b==0) return 1;
    if(b==1) return a;
    ll res = power(a, b/2);
    res = res*res;
    if(b%2==1) res = res*a;
    return res;
}
int main(){
    ll t; cin >> t; for(ll tc=0; tc < t; tc++){
        ll n, p;
        cin >> n >> p;
        vector<string> vec;
        string s, s1;
        ll mark[p];
        memset(mark, 0, sizeof(mark));
        for(ll i =0; i< p; i++){
            cin >> s;
            vec.push_back(s);
            for(ll j = 0; j < i; j++){
                ll l1 = vec[i].size(), l2 = vec[j].size();
                s1 = vec[j];
                if(l1 >= l2){
                    ll f = 1;
                    for(ll l = 0; l < l2; l++){
                        if(s[l]!= s1[l]){f = 0; break;}
                    }
                    if(f) mark[i] = 1;
                }
                else {
                    ll f = 1;
                    for(ll l = 0; l < l1; l++){
                        if(s[l]!= s1[l]){f = 0; break;}
                    }
                    if(f) mark[j] = 1;
                }
            }
        }
        ll ans = 0;
        for(ll i = 0; i < p; i++){
            if(!mark[i]){
                ans += power(2, n-vec[i].length());
            }
        }
        cout << "Case #" << tc+1 << ": " <<power(2,n) - ans << endl;
    }

}
