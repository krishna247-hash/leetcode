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
#define umvll unordered_map<ll,vll>
class Solution {
public:

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bitset<1024>>> dp(
            m, vector<bitset<1024>>(n)
        );

        dp[0][0][grid[0][0]] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                if (i > 0) {
                    for (int x = 0; x < 1024; x++) {
                        if (dp[i-1][j][x]) {
                            dp[i][j][x ^ grid[i][j]] = 1;
                        }
                    }
                }

                if (j > 0) {
                    for (int x = 0; x < 1024; x++) {
                        if (dp[i][j-1][x]) {
                            dp[i][j][x ^ grid[i][j]] = 1;
                        }
                    }
                }
            }
        }

        for (int x = 0; x < 1024; x++) {
            if (dp[m-1][n-1][x]) return x;
        }

        return -1;
    }

};