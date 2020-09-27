
#include <bits/stdc++.h>
#define maxn 100005
#define INF 100000
using namespace std;
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair <int, piii>
#define ft first
#define sd second


int table[55][55], dp[55][2000];
int n, k, p;

int solve(int pos, int rem){
    //
    if(rem < 0) return -10000;
    if(dp[pos][rem] != -1) return dp[pos][rem];

    if(pos == n){
        if(rem > k)return -10000;
        else {
            dp[pos][rem] = table[pos][rem];return dp[pos][rem];
        }
    }
    int res = 0;
    for(int i  =0; i <= k; i++){
        if(rem-i >= 0)res  = max(res, solve(pos+1, rem-i)+table[pos][i]);
    }//cout << pos << " " << rem << " " << res << endl;
    dp[pos][rem] = res;
    return res;

}
int main()
{
    int t = 1, tc = 0;cin >>t;
    while(t--){
        tc++;

        cin >> n>> k >> p;
        int arr[n];
        memset(table, 0, sizeof(table));
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i  <n; i++)
        {
            for(int j = 0; j < k; j++)
            {
                int x; cin >> x;
                table[i][j+1] = table[i][j] + x;
            }
        }
        solve(0, p);
        /*for(int i = 0; i  <n; i++)
        {
            for(int j = 0; j <= k; j++)
            {
                cout << dp[i][j] << " ";
            }cout << endl;
        }*/

        cout << "Case #" << tc  << ": " << dp[0][p] << endl;
    }
}
