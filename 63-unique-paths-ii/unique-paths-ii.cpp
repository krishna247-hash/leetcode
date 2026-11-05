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
#define INF (ll)(1LL << 60)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        ll m = sz(obstacleGrid);
        ll n = sz(obstacleGrid[0]);

        vll dp(n,0);

        FOR(m)
        {
            vll temp(n,0);
            FORJ(n)
            {
                if(obstacleGrid[i][j] == 1)temp[j] = 0;
                else if(i == 0 && j== 0)temp[j] = 1;
                else
                {
                    ll l = 0;
                    if(j > 0) l = temp[j-1];
                    temp[j] = dp[j] + l;
                }
            }

            dp = temp;
        }

        return dp[n-1];
    }
};