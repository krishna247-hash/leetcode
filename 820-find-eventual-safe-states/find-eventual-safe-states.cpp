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
    bool dfs(ll node, vll& vis, vll& path, vvll& adj,vll& a)
    {
        vis[node] = 1;
        path[node] = 1;

        for(auto it: adj[node])
        {
            if(path[it]) return true;

            if(!vis[it])
            {
                if(dfs(it,vis,path,adj,a)) return true;
            }
        }

        a.pb(node);
        path[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vll a;
        vll vis(sz(graph),0);
        vll path(sz(vis),0);

        FOR(sz(vis))
        {
            if(!vis[i] && !path[i])
            {
                dfs(i,vis,path,graph,a);
            }
        }

        sort(all(a));
        return a;
    }
};