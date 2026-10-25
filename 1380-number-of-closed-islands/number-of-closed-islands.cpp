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
    vll dx = {-1,0,1,0};
    vll dy = {0,-1,0,1};

    void dfs(ll x, ll y, vvll& grid)
    {
        grid[x][y] = 1;

        FOR(4)
        {
            ll r = x + dx[i];
            ll c = y + dy[i];

            if(r < 0 || c < 0 || r >= sz(grid) || c >= sz(grid[0]) || grid[r][c] == 1) continue;

            dfs(r,c,grid);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        ll n = sz(grid);
        ll m = sz(grid[0]);

        FOR(n)
        {
            if(grid[i][0] == 0) dfs(i,0,grid);
        }
        FOR(n)
        {
            if(grid[i][m-1] == 0) dfs(i,m-1,grid);
        }
        FOR(m)
        {
            if(grid[n-1][i] == 0) dfs(n-1,i,grid);
        }
        FOR(m)
        {
            if(grid[0][i] == 0) dfs(0,i,grid);
        }

        ll cnt = 0;

        FOR(n)
        {
            FORJ(m)
            {
                if(grid[i][j] == 0)
                {
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }

        return cnt;
    }
};




