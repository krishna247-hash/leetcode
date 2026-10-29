
#define ll long long
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
#define RFORJ(a,b) for(ll j = a; j <= b; j++)
#define RFORR(a,b) for(ll i = b; i >= a; i--)
#define print(x) cout << x; NN
#define INF (ll)(1LL << 60)
#define umvll unordered_map<ll,vll>

class Solution {
public:
    vector<vector<ll>> adj;
    vll par, dep, sz, heavy, head, pos, val;
    vll seg;
    ll timer;

    void dfs(ll u, ll p)
    {
        par[u] = p;
        sz[u] = 1;
        heavy[u] = -1;
        ll mx = 0;

        for(ll v : adj[u])
        {
            if(v == p) continue;

            dep[v] = dep[u] + 1;
            dfs(v, u);

            sz[u] += sz[v];

            if(sz[v] > mx)
            {
                mx = sz[v];
                heavy[u] = v;
            }
        }
    }

    void decompose(ll u, ll h)
    {
        head[u] = h;
        pos[u] = timer++;

        if(heavy[u] != -1)
            decompose(heavy[u], h);

        for(ll v : adj[u])
        {
            if(v == par[u] || v == heavy[u])
                continue;

            decompose(v, v);
        }
    }

    void build(ll node, ll l, ll r)
    {
        if(l == r)
        {
            seg[node] = val[l];
            return;
        }

        ll mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
    }

    void update(ll node, ll l, ll r, ll idx, ll x)
    {
        if(l == r)
        {
            seg[node] = x;
            return;
        }

        ll mid = (l + r) / 2;

        if(idx <= mid)
            update(node * 2, l, mid, idx, x);
        else
            update(node * 2 + 1, mid + 1, r, idx, x);

        seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
    }

    ll query(ll node, ll l, ll r, ll ql, ll qr)
    {
        if(qr < l || r < ql)
            return 0;

        if(ql <= l && r <= qr)
            return seg[node];

        ll mid = (l + r) / 2;

        return query(node * 2, l, mid, ql, qr) ^
               query(node * 2 + 1, mid + 1, r, ql, qr);
    }

    ll pathQuery(ll u, ll v, ll n)
    {
        ll ans = 0;

        while(head[u] != head[v])
        {
            if(dep[head[u]] < dep[head[v]])
                swap(u, v);

            ans ^= query(1, 0, n - 1, pos[head[u]], pos[u]);

            u = par[head[u]];
        }

        if(dep[u] > dep[v])
            swap(u, v);

        ans ^= query(1, 0, n - 1, pos[u], pos[v]);

        return ans;
    }

    vector<bool> palindromePath(
        int n, vector<vector<int>>& edges,
        string s, vector<string>& queries)
    {
        adj.assign(n, {});
        par.assign(n, -1);
        dep.assign(n, 0);
        sz.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        val.assign(n, 0);
        seg.assign(4 * n, 0);
        timer = 0;

        for(auto it : edges)
        {
            ll u = it[0], v = it[1];
            adj[u].pb(v);
            adj[v].pb(u);
        }

        for(ll i = 0; i < n; i++)
            val[i] = 1LL << (s[i] - 'a');

        dfs(0, -1);
        decompose(0, 0);

        vll base(n);

        for(ll i = 0; i < n; i++)
            base[pos[i]] = val[i];

        val = base;
        build(1, 0, n - 1);

        vector<bool> ans;

        for(auto it : queries)
        {
            stringstream ss(it);
            string op;
            ss >> op;

            if(op == "update")
            {
                ll u;
                char ch;
                ss >> u >> ch;

                s[u] = ch;

                ll mask = 1LL << (ch - 'a');

                update(1, 0, n - 1, pos[u], mask);
            }
            else if(op == "query")
            {
                ll u, v;
                ss >> u >> v;

                ll mask = pathQuery(u, v, n);

                ans.pb((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};