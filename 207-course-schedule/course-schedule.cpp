#define ll int
#define F first
#define S second
#define pb push_back
#define mpp make_pair
#define N 300000
#define MOD 998244353 
#define all(a) a.begin(),a.end()
#define sz(a) ((int) (a).size())
#define SUM accumulate
using pll = pair<ll,ll>;
using vll = vector<ll>;
#define vpll vector<pll>
#define vvpll vector<vpll>
#define vvll vector<vector<ll>>
#define NN cout << "\n";
#define umll unordered_map<ll,ll>
#define mll map<ll,ll>
#define lb lower_bound
#define ub upper_bound
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define FOR(n) for(ll i = 0; i < n; i++)
#define FORJ(n) for(ll j = 0; j < n; j++)
#define FORR(n) for(ll i = n; i >= 0; i--)
#define RFOR(a,b) for(ll i = a; i <= b; i++)
#define RFORR(a,b) for(ll i = b; i >= a; i--)
#define pn(x) cout << x; NN
#define MAX(a) (ll)*max_element(all(a));
#define MIN(a) (ll)*min_element(all(a));

class Solution {
public:
    bool dfs(ll node, vll& vis, vll& path,vvll& adj)
    {
        vis[node] = 1;
        path[node] = 1;
        bool ans = 0;
        for(auto it: adj[node])
        {
            if(path[it]) return true;
            if(vis[it] == 0 && path[it] == 0) 
            {
                if(dfs(it,vis,path,adj)) return true;
            }
        }
        path[node] = 0;
        return ans;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        ll n = numCourses;
        vll vis(n,0);
        vll path(n,0);
        queue<pll> q;
        vvll adj(n);
        for(auto it: prerequisites)
        {
            ll u = it[0];
            ll v = it[1];

            adj[u].pb(v);
        }

        FOR(n)
        {
            if(!vis[i])
            {
                if(dfs(i,vis,path,adj)) return false;
            }
        }
        return true;
    }   
};






