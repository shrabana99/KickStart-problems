#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, tc = 0;
    cin >> t;
    while(t--){
        tc++;
        
        ll n, m;
        cin >> n >> m;
        ll a[n];
        for(ll i = 0; i < n; i++) cin >> a[i];

        ll l = 1, r = a[n-1] - a[0], res = 0;
        
        while(l < r){
            ll md = (l + r)/2;
            ll cnt = 0, dif = 0;
            for(int i = 1; i < n; i++){
                dif = a[i] - a[i-1];
                cnt += (dif-1)/md;
            }
            if(cnt <= m)
                r = md, res = min(res, md);
            else
                l = md + 1; 
            // cout << l << " " << r << endl;
        }
        cout << "Case #" << tc << ": " << l << endl;


    }
}
