#define F first
#define S second
#define L left
#define R right
#define NN TreeNode
#define ll long long

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        queue<pair<NN*, ll>> q;
        ll ans = 0;

        q.push({root, 0});

        while(!q.empty())
        {
            ll sz = q.size();
            ll start = q.front().S;
            ll maxi = 0;

            for(ll i = 0; i < sz; i++)
            {
                auto x = q.front();
                q.pop();

                NN* node = x.F;
                ll r = x.S - start;

                maxi = r;

                if(node->L != NULL)
                    q.push({node->L, 2 * r + 1});

                if(node->R != NULL)
                    q.push({node->R, 2 * r + 2});
            }

            ans = max(ans, maxi + 1);
        }

        return ans;
    }
};