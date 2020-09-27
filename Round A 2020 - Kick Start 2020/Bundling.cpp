#include <bits/stdc++.h>

using namespace std;

#define ll int
#define mem(dp,a) memset(dp,a,sizeof dp)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
#define f(n) for(ll i=0;i<n;i++)
#define pb(x) push_back(x)
#define mle 52
ll n, m, numm1, ans;

string s;

struct trie
{
    int leaf;
    trie* child[mle];
};

trie* create()
{
    trie* temp=new trie();
    temp->leaf=0;
    mem(temp->child,NULL);
    return temp;
}

void add(trie* root,string &s)
{
    rep(i,0,s.length())
    {
        if(root->child[s[i]-'A']==NULL)
            root->child[s[i]-'A']=create();
        root=root->child[s[i]-'A'];
    }
    root->leaf++;
}

ll print(trie* root,string &a)
{
    ll child =  0; //= tim++; //cout << tim << " ";
    if(root->leaf){
        child += root->leaf;
        root->leaf=0;
    }
    rep(i,0,mle)
    	{
    		if(root->child[i]!=NULL)
    		{
    			a = a+(char)('A'+i); //cout << "1\n";
    			child += print(root->child[i],a); //cout << "2\n";
    			a=a.substr(0,a.length()-1);
    		}
    	}

            ll  k = child / m;
            child = child % m;
            //cout << k*(a.length()/2)*(a.length()/2) << " ";
            ans += k*a.length();
            return child;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, tc = 0;
    cin >> t;
    while(t--){
        tc++;
        trie* root;
        root=create();
        cin >> n >> m;
        ans = 0;
        for(ll i = 0; i < n; i++){
            cin >> s;
            add(root,s);
        }
        string a; //cout << a << " ";
        print(root, a);
        cout << "Case #" << tc << ": " << ans << endl;


    }
}
