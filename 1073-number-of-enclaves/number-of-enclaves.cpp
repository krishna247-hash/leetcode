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
class Solution {
public:
   vpll dir= {{1,0},{0,1},{-1,0},{0,-1}};
    bool DFS(ll i, ll j, vvll& g,int& cnt)
    {
        cnt++;
        bool ans = 1;
        ll m = sz(g);
        ll n = sz(g[0]);
        g[i][j] = 0;

        for(auto it: dir)
        {
            ll x = i + it.F;
            ll y = j + it.S;

            if(x < m && x >= 0 && y >= 0 && y < n && g[x][y] == 1)
            {
                if(x == 0 || x == m-1 || y == 0 || y == n-1) ans = false;

                if(!DFS(x,y,g,cnt))
                    ans = false;
            }

        }

        return ans;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        ll m = sz(grid);
        ll n = sz(grid[0]);
        ll cnt = 0;

        for(ll i = 1; i < m -1; i++)
        {
            for(ll j = 1; j < n-1; j++)
            {
                if(grid[i][j] == 1) 
                {
                    ll x = 0;
                    if(DFS(i,j,grid,x)) cnt += x;
                }
            }
        }

        return cnt;
    }
};