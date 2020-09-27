
#include <bits/stdc++.h>
#define maxn 100005
#define INF 100000
using namespace std;
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair <int, piii>
#define ft first
#define sd second

vector<int> v[maxn];
int ans;

int dfs(int u, int p){
    int c = 1;
    for(auto x: v[u]){
        if(x!=p){
            int k = dfs(x, u);
            if(k%2){
                c += k;
            }
            else{
                ans++;
            }
        }
    }
    return c;
}

int main()
{
    int t = 1, tc = 0;cin >>t;
    while(t--){
        tc++;
        int n, m;
        cin >> n>> m;
        int arr[n];
        for(int i = 0; i  <n; i++) cin >> arr[i];
        sort(arr, arr+n);
        int c = 0, cn = 0;
        for(int i = 0; i < n; i++){
            c += arr[i];
            if(c>m) break;
            else cn++;
        }
        cout << "Case #" << tc  << ": " << cn << endl;
    }
}
