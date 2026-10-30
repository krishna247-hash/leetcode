
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
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vvpll adj(n);
        for(auto it: times)
        {
            ll u = it[0]-1;
            ll v = it[1]-1;
            ll w = it[2];

            adj[u].pb({v,w});
        }

        vll dist(n,1e9+7);
        priority_queue<pll, vpll, greater<pll>> pq; // {time,node}

        dist[k-1] = 0;
        pq.push({0,--k});

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            ll u = it.S;
            ll d = it.F;

            for(auto x: adj[u])
            {
                if(d + x.S < dist[x.F])
                {
                    dist[x.F] = d+x.S;
                    pq.push({d+x.S,x.F});
                }
            }
        }

        ll ans = 0;

        for(auto it: dist) ans = max(ans,it);

        return (ans == 1e9+7)?-1:ans;
    }
};