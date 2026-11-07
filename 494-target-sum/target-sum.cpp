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
#define ff(x,a) for(auto& x: a)
#define print(x) cout << x; NN
#define INF (ll)(1LL << 60)
#define umvll unordered_map<ll,vll>
#define Dpq  priority_queue<pll, vpll, greater<pll>>

class Solution {
public:
    ll f(ll i , ll x, vll& a,unordered_map<ll,umll>& dp)
    {
        if(i == -1 && x == 0)return dp[i][x] = 1;
        if(i <= -1)return 0;
        if(dp.find(i) != dp.end() && dp[i].find(x) != dp[i].end())return dp[i][x];

        ll t = f(i-1,x+a[i],a,dp);
        ll nt = f(i-1,x-a[i],a,dp);

        return dp[i][x] = t+nt;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<ll,umll> dp;
        return f(sz(nums)-1,abs(target),nums,dp);
    }
};