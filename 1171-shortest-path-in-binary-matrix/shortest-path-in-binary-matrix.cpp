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
class Solution {
public:
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        ll m = sz(grid);
        ll n = sz(grid[0]);
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};
        vvll dis(sz(grid),vll(n,INT_MAX));
        if(grid[0][0] != 0) return -1;
        dis[0][0] = 0;

      priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> pq;
        pq.push({0,{0,0}});

        while(!pq.empty())
        {
            auto it = pq.top();
            ll d = it.F;
            ll x = it.S.F;
            ll y = it.S.S;
            pq.pop();

            FOR(8)
            {
                ll ndx = x + dx[i];
                ll ndy = y + dy[i];

                if(ndx < 0 || ndy < 0 || ndx >= m || ndy >= n) continue;
                if(dis[ndx][ndy] > d + 1 && grid[ndx][ndy] == 0)
                {
                    dis[ndx][ndy] = d + 1;
                    pq.push({d+1,{ndx,ndy}});
                }
            }
        }

        return (dis[n-1][n-1] == INT_MAX)? -1: dis[n-1][n-1]+1;
    }
};