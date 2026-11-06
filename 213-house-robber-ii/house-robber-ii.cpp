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
    ll f1(ll i, vll& a,vll& dp1)
    {
        if(i == 0)return a[i];
        if(i < 0) return 0;
        if(dp1[i] != -1)return dp1[i];

        return dp1[i] = max(a[i]+f1(i-2,a,dp1), f1(i-1,a,dp1));
    }
    ll f2(ll i, vll& a,vll& dp2)
    {
        if(i == 1)return a[i];
        if(i < 1) return 0;
        if(dp2[i] != -1)return dp2[i];

        return dp2[i] = max(a[i]+f2(i-2,a,dp2), f2(i-1,a,dp2));
    }
    int rob(vector<int>& nums) {
         ll n = sz(nums);
        if(n == 1)return nums[0];
        vll dp1(n,-1);
        vll dp2(n,-1);

        return max(f1(n-2,nums,dp1),f2(n-1,nums,dp2));
    }
};

// 1 2
// f(i) = max(a[i]+f(i-2) , f(i-1))


