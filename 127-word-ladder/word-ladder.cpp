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
#define MAX(a) (ll)*max_element(all(a));
#define MIN(a) (ll)*min_element(all(a));
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(all(wordList));
        queue<pair<string,ll>> q;
        q.push({beginWord,1});
        if(st.find(beginWord) != st.end()) st.erase(beginWord);

        while(!q.empty())
        {
            string org = q.front().F;
            ll x = q.front().S;
            q.pop();
            if(org == endWord) return x;
            string w = org;
            for(ll j = 0; j < sz(w); j++)
            {
              for(char i = 'a'; i <= 'z'; i++)
              {
                 w[j] = i;
                 if(st.find(w) != st.end())
                 {
                    st.erase(w);
                    q.push({w,x+1});
                 }
              } 

              w = org; 
            }
            

        }

        return 0;
    }
};