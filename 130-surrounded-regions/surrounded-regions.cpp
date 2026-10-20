 
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
     
     vpll dir = {{1,0},{0,1},{-1,0},{0,-1}};
    void DFS(ll i, ll j,vector<vector<char>>& board)
    {
        ll m = sz(board);
        ll n = sz(board[0]);
        board[i][j] = '1';

        for(auto it: dir)
        {
            ll x = i + it.F;
            ll y = j + it.S;

            if(x >= 0 && y >= 0 && x < m && y < n && board[x][y] == 'O')
            {
                DFS(x,y,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        ll m = sz(board);
        ll n = sz(board[0]);

        for(ll i = 0; i < n; i++)
        {
            if(board[0][i] == 'O') DFS(0,i,board);
        }
        for(ll i = 0; i < n; i++)
        {
            if(board[m-1][i] == 'O') DFS(m-1,i,board);
        }
        for(ll i = 0; i < m; i++)
        {
            if(board[i][0] == 'O') DFS(i,0,board);
        }
        for(ll i = 0; i < m; i++)
        {
            if(board[i][n-1] == 'O') DFS(i,n-1,board);
        }

        FOR(m)
        {
            FORJ(n)
            {
                if(board[i][j] == 'O') board[i][j] ='X';
            }
        }

        FOR(m)
        {
            FORJ(n)
            {
                if(board[i][j] == '1') board[i][j] = 'O';
            }
        }
    }
};







