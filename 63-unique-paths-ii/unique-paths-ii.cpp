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
#define INF (ll)(1LL << 60)
class Solution {
public:
    vll dx = {1,0};
    vll dy = {0,1};
    ll cnt = 0;

    // void dfs(ll x, ll y,vector<vector<int>>& grid)
    // {
    //     if(grid[x][y] == 1)return;
    //     ll m = sz(grid);
    //     ll n = sz(grid[0]);

    //     if(x == m-1 && y == n-1)
    //     {
    //         cnt++;
    //         return;
    //     }

    //     FOR(2)
    //     {
    //         ll ndx = x + dx[i];
    //         ll ndy = y + dy[i];

    //         if(ndx >= m || ndy >= n || grid[ndx][ndy] == 1)continue;
    //         dfs(ndx,ndy,grid);
    //     }
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // dfs(0,0,obstacleGrid);
        ll m = sz(obstacleGrid);
        ll n = sz(obstacleGrid[0]);

        vvll dp(m,vll(n,0));
        for(ll i = 0; i < m; i++)
        {
            if(obstacleGrid[i][0] != 1)
            dp[i][0] = 1;
            else
            {
                dp[i][0] = 0;
                break;
            }
        }
        for(ll i = 0; i < n; i++)
        {
            if(obstacleGrid[0][i] != 1)
            dp[0][i] = 1;
            else
            {
                dp[0][i] = 0;
                break;
            }
        }

        for(ll i = 1; i < m; i++)
        {
            for(ll j = 1; j < n; j++)
            {
                if(obstacleGrid[i][j] != 1)
                {
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
                }
                else dp[i][j] = 0;
            }
        }

        return dp[m-1][n-1];
    }
};