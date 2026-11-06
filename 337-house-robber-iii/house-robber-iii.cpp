/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
#define L left
#define R right
class Solution {
public:
    bool isLeaf(TreeNode* root)
    {
        return (!root->L && !root->R);
    }
    ll f(TreeNode* root,unordered_map<TreeNode* , ll>& dp)
    {
        if(!root)return 0;
        if(dp.find(root) != dp.end())return dp[root];
        ll t = root->val + ((root->L != NULL)? (f(root->L->L,dp) + f(root->L->R,dp)):0); 
        t += (root->R != NULL)? (f(root->R->L,dp) + f(root->R->R,dp)):0;

        ll nt = f(root->L,dp) + f(root->R,dp);

        return dp[root] = max(t,nt);
    }

    int rob(TreeNode* root) {
        unordered_map<TreeNode* , ll> dp;
        return f(root,dp);
    }
};