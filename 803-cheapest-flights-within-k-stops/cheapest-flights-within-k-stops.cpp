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
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vvll dis(n,vll(k+2,INT_MAX));
        vvpll adj(n);

        for(auto it: flights)
        {
            ll u = it[0];
            ll v = it[1];
            ll w = it[2];

            adj[u].pb({v,w});
        }
        dis[src][0] = 0;
        priority_queue<pair<ll,pll>, vector<pair<ll,pll>>, greater<pair<ll,pll>>> pq; // {price,{cnt,node}}
        pq.push({0,{0,src}});

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            ll cnt = it.S.F;
            ll u = it.S.S;
            ll p = it.F;

            for(auto x: adj[u])
            {
                ll v = x.F;
                ll y = p + x.S;

                if(cnt+1 <= k+1 && dis[v][cnt+1] > y)
                {
                    dis[v][cnt+1] = y;
                    pq.push({y,{cnt+1,v}});
                }
            }
        }

        ll ans = INT_MAX;
        for(ll i= 0; i <= k+1; i++)
        {
            ans = min(ans,dis[dst][i]);
        }

        return (ans == INT_MAX)? -1:ans;

    }
};