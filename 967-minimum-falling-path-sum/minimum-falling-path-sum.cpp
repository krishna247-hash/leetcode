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
#define MIN (ll)*min_element
#define MAX (ll)*max_element
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define FOR(n) for(ll i = 0; i < n; i++)
#define FORJ(n) for(ll j = 0; j < n; j++)
#define FORR(n) for(ll i = n; i >= 0; i--)
#define RFOR(a,b) for(ll i = a; i <= b; i++)
#define RFORJ(a,b) for(ll j = a; j <= b; j++)
#define RFORR(a,b) for(ll i = b; i >= a; i--)
#define ff(x,a) for(auto& x: a)
#define print(x) cout << x; NN
#define INF (ll)(1LL << 60)
#define umvll unordered_map<ll,vll>
#define Dpq  priority_queue<pll, vpll, greater<pll>>

class Solution {
public:
    // ll f(ll i , ll j,vvll& grid, unordered_map<ll,umll>& dp)
    // {
    //     ll n = sz(grid);
    //     if(i < 0 || j < 0 || i >= n || j >= n)return (1e4+7);
    //     if(i == 0)return grid[i][j];
    //     if(dp.find(i) != dp.end() && dp[i].find(j) != dp[i].end())return dp[i][j];

    //     ll up = grid[i][j] + f(i-1 , j,grid,dp);
    //     ll left = grid[i][j] + f(i-1,j-1,grid,dp);
    //     ll right = grid[i][j] + f(i-1,j+1,grid,dp);

    //     return dp[i][j] = min({up,left,right});
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        ll n = sz(matrix);
        ll ans = INT_MAX;
        // for(ll i = 0; i < n; i++)
        // {
        //     unordered_map<ll,umll> dp;
        //     ans = min(ans, f(n-1,i,matrix,dp));
        // }

        vll dp(n,0);

        FOR(n)
        {
            vll curr(n,INT_MAX);
            FORJ(n)
            {
                if(i == 0)curr[j] = matrix[0][j];
                else
                {
                    if(i > 0)
                    {
                        curr[j] = min(curr[j] , matrix[i][j] + dp[j]);
                    }
                    if(i > 0 && j > 0)
                    {
                        curr[j] = min(curr[j], matrix[i][j] + dp[j-1]);
                    }
                    if(i > 0 && j < n-1)
                    {
                        curr[j] = min(curr[j],matrix[i][j] + dp[j+1]);
                    }
                }
            }
            dp = curr;
        }

       ff(x,dp)ans = min(ans,x);
        return ans;
    }
};

// dp[0][0] =  mat[0][0]
// dp[i][j] = grid[i][j] + min(dp[i-1][j] ,dp[i-1][j-1],dp[i-1][j+1])


        // ll up = grid[i][j] + f(i-1 , j,grid,dp); dp[i-1[j]
        // ll left = grid[i][j] + f(i-1,j-1,grid,dp);
        // ll right = grid[i][j] + f(i-1,j+1,grid,dp);