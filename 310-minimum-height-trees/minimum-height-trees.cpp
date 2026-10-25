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
#define print(x) cout << x; NN
#define INF (1LL << 60)
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vvll adj(n);
        vll vis(n,0);
        vll ans;

        for(auto it: edges)
        {
            ll u = it[0];
            ll v = it[1];

            adj[u].pb(v);
            adj[v].pb(u);
            vis[u]++;
            vis[v]++;
        }
        queue<ll> q;

        for(auto& it: vis) it--;

        FOR(n)
        {
            if(vis[i] == 0)q.push(i);
        }

        while(!q.empty())
        {
            vll a;
            ll sz = sz(q);

            FOR(sz)
            {
                ll u = q.front();
                q.pop();
                a.pb(u);
                for(auto it: adj[u])
                {
                    vis[it]--;
                    if(vis[it] == 0)
                    q.push(it);
                }

            }
            ans = a;
        }

        return ans;
        
    }
};