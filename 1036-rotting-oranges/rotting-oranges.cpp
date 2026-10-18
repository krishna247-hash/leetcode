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

    vpll dir = {{1,0},{0,1},{-1,0},{0,-1}};

    int orangesRotting(vector<vector<int>>& grid) {
        ll m = sz(grid);
        ll n = sz(grid[0]);

        queue<pair<ll,ll>> q;
        ll cnt = 0;

        FOR(m)
        {
            FORJ(n)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                    grid[i][j] = -1;
                }
            }
        }

        while(!q.empty())
        {
            ll s = sz(q);
            bool check = false;

            for(ll l = 0; l < s; l++)
            {
                auto p = q.front();
                q.pop();

                ll r = p.F;
                ll c = p.S;

                for(auto it: dir)
                {
                    ll x = r + it.F;
                    ll y = c + it.S;

                    if(x < m && x >= 0 && y >= 0 && y < n && grid[x][y] == 1)
                    {
                        grid[x][y] = -1;
                        q.push({x,y});
                        check = true;
                    }
                }
            }

            if(check) cnt++;
        }

        FOR(m)
        {
            FORJ(n)
            {
                if(grid[i][j] == 1) return -1;
            }
        }

        return cnt;
    }
};