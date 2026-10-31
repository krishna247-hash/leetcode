#define ll long long
#define F first
#define S second
#define pb push_back
#define mpp make_pair
#define N 300000
#define MOD 998244353
#define all(a) a.begin(),a.end()
#define sz(a) ((int)(a).size())
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
    int jump(vector<int>& nums) {
        ll n = sz(nums);

        vvll adj(n);
        vll dist(n, INF);

        FOR(n)
        {
            ll u = i;

            for(ll j = 1; j <= nums[i] && i + j < n; j++)
            {
                adj[u].pb(i + j);
            }
        }

        priority_queue<pll, vpll, greater<pll>> pq;

        pq.push({0, 0});
        dist[0] = 0;

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            ll d = it.F;
            ll u = it.S;

            if(d != dist[u]) continue;

            for(auto x : adj[u])
            {
                if(dist[x] > d + 1)
                {
                    dist[x] = d + 1;
                    pq.push({dist[x], x});
                }
            }
        }

        return dist[n - 1];
    }
};