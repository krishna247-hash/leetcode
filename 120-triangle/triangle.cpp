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
#define MIN (ll)*min_element
#define MAX (ll)*max_element
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define FOR(n) for(ll i = 0; i < n; i++)
#define FORJ(n) for(ll j = 0; j < n; j++)
#define FORR(n) for(ll i = n; i >= 0; i--)
#define RFOR(a,b) for(ll i = a; i <= b; i++)
#define RFORJ(a,b) for(ll j = a; j <= b; j++)
#define RFORR(a,b) for(ll i = b; i >= a; i--)
#define ff(a) for(auto& it: a)
#define print(x) cout << x; NN
#define INF (ll)(1LL << 60)
#define umvll unordered_map<ll,vll>
#define Dpq  priority_queue<pll, vpll, greater<pll>>
class Solution {
public:

    ll f(ll i,ll j, vvll& mat, unordered_map<ll,umll>&dp)
    {
        if(i == 0 && j == 0)return mat[i][j];
        ll n = sz(mat[i]);
        if(i < 0 || j < 0 || j >= n)return 1e7;
        if(dp.find(i) != dp.end() && dp[i].find(j) != dp[i].end())return dp[i][j];

        ll up = mat[i][j] + f(i-1,j,mat,dp);
        ll dia = mat[i][j] + f(i-1,j-1,mat,dp);

        return dp[i][j] = min(up,dia);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        ll m = sz(triangle);
        ll n = sz(triangle[m-1]);

        ll ans = INT_MAX;
        FOR(n)
        {
            unordered_map<ll,umll> dp;
            ans = min(ans,f(m-1,i,triangle,dp));
        }

        return ans;
    }
};

// 
//
//
//
//