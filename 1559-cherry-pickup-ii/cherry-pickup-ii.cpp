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
#define vvvll vector<vvll>
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
    vll dx = {-1,0,1};
    // ll f(ll i, ll j1,ll j2, vvll& grid, vvvll& dp)
    // {
    //     ll m = sz(grid), n = sz(grid[0]);
    //     if(i >= m || j1 >= n || j1 < 0 || j2 >= n || j2 < 0)return -1e6;
    //     if(i == m-1)return dp[i][j1][j2] = (j1 != j2)? (grid[i][j1]+grid[i][j2]) : grid[i][j1];
    //     if(dp[i][j1][j2] != -1)return dp[i][j1][j2];

    //     ll x = INT_MIN;
    //     ll y = (j1 != j2)? (grid[i][j1]+grid[i][j2]) : grid[i][j1];
    //     for(ll l = 0; l < 3; l++)
    //     {
    //         FORJ(3)
    //         {
    //             x = max(x, y + f(i+1,j1+dx[l],j2+dx[j],grid,dp));
    //         }
    //     }

    //     return dp[i][j1][j2] = x;

    // }
    int cherryPickup(vector<vector<int>>& grid) {
        ll m = sz(grid), n = sz(grid[0]);
        vvvll dp(m,vvll(n,vll(n,-1e7)));

        for(ll i = m-1; i >= 0; i--)
        {
            for(ll j1 = 0; j1 < n; j1++)
            {
                for(ll j2 = 0; j2 < n; j2++)
                {
                    if(i == m-1)dp[m-1][j1][j2] = (j1 != j2)? (grid[i][j1]+grid[i][j2]) : grid[i][j1];
                    else 
                    {
                        ll y = (j1 != j2)? (grid[i][j1]+grid[i][j2]) : grid[i][j1];

                        for(ll l = 0; l < 3; l++)
                        {
                            for(ll k = 0; k < 3; k++)
                            {
                                ll c1 = j1 + dx[l];
                                ll c2 = j2 + dx[k];
                                ll r = i+1;

                                if(r >= m || c1 < 0 || c2 < 0 || c1 >= n || c2 >= n)continue;

                                dp[i][j1][j2] = max(dp[r][c1][c2] ,dp[i][j1][j2]);
                            }
                        }

                        dp[i][j1][j2] += y;
                    }
                }
            }
        }
        return dp[0][0][n-1];
    }
};


// dp[m-1][j1][j2] = (j1 != j2)? (grid[i][j1]+grid[i][j2]) : grid[i][j1];

// dp[i][j1][j2] = ((j1 != j2)? (grid[i][j1]+grid[i][j2]) : grid[i][j1];) + max(dp[i-1][j1+dx[l]][j2+dx[k]]);

// f(i-1,j-1),f(i-1,j),f(i-1,j+1)