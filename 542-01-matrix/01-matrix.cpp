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
#define pn(x) cout << x; NN
#define MAX(a) (ll)*max_element(all(a));
#define MIN(a) (ll)*min_element(all(a));
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        ll m = sz(mat);
        ll n = sz(mat[0]);

        queue<pair<ll,ll>> q;
        FOR(m)
        {
            FORJ(n)
            {
                if(mat[i][j] == 0)
                {
                    q.push({i,j});
                }
            }
        }

        ll ct = 1;
        ll dx[] = {1,-1,0,0};
        ll dy[] = {0,0,1,-1};

        while(!q.empty())
        {
            ll k = q.size();

            FOR(k)
            {
                auto it = q.front();
                q.pop();

                ll x = it.F;
                ll y = it.S;
                FORJ(4)
                {
                    ll nx = x + dx[j];
                    ll ny = y + dy[j];
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && mat[nx][ny] == 1)
                    {
                        mat[nx][ny] = -ct;
                        q.push({nx,ny});
                    }
                }
            }
            ct++;
        }

        FOR(m)
        {
            FORJ(n)
            {
                mat[i][j] = -mat[i][j];
            }
        }

        return mat;
    }
};


