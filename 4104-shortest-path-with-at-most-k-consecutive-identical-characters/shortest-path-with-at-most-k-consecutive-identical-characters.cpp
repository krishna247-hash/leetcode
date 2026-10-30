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
#define RFORJ(a,b) for(ll j = a; j <= b; j++)
#define RFORR(a,b) for(ll i = b; i >= a; i--)
#define print(x) cout << x; NN
#define INF (ll)(1LL << 60)
#define umvll unordered_map<ll,vll>
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vvpll adj(n);

        for(auto it: edges)
        {
            ll u = it[0];
            ll v = it[1];
            ll w = it[2];

            adj[u].pb({v,w});
        }

        vvll dist(n,vll(k+1,INT_MAX));
        priority_queue<pair<ll,pll>,vector<pair<ll,pll>>, greater<pair<ll,pll>>> pq; // {d,{k,node}}
        pq.push({0,{1,0}});
        dist[0][1] = 0;

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            ll d = it.F;
            ll cnt = it.S.F;
            ll node = it.S.S;
            char ch = labels[node];

            for(auto x: adj[node])
            {
                ll v = x.F;
                ll w = x.S;

                ll y = (labels[v] == ch)?cnt+1:1;

                if(y <= k && d + w < dist[v][y])
                {
                    dist[v][y] = d + w;
                    pq.push({dist[v][y],{y,v}});
                }
            
            }
        }

        ll ans = INT_MAX;

        for(ll i = 1; i <= k; i++)
        {
            ans = min(ans,dist[n-1][i]);
        }

        return (ans == INT_MAX)?-1:ans;
    }
};