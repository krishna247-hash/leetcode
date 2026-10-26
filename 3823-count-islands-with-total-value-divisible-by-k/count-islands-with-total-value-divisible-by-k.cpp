#define ll long long
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
    void dfs(ll x, ll y ,vector<vector<int>>& grid,ll& sum)
    {
        ll m = sz(grid);
        ll n = sz(grid[0]);
        sum += grid[x][y];
        grid[x][y] = 0;

        FOR(4)
        {
            ll r = x + dx[i];
            ll c = y + dy[i];

            if(r >= m || r < 0 || c >= n || c < 0 || grid[r][c] == 0)continue;

            dfs(r,c,grid,sum);
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        ll m = sz(grid);
        ll n = sz(grid[0]);
        int cnt = 0;

        FOR(m)
        {
            FORJ(n)
            {
                ll sum = 0;
                if(grid[i][j])
                {
                    dfs(i,j,grid,sum);
                }

                if(sum && sum %k == 0)cnt++;
            }
        }

        return cnt;
    }
};