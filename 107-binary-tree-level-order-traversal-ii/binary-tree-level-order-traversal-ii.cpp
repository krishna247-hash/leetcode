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
 #define vll vector<int>
 #define ll int
 #define pb push_back
 #define sz(a) (int)a.size()
 #define TN TreeNode
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TN*> q;
        vector<vll> ans;
        if(root == NULL) return ans;
        q.push(root);
        while(!q.empty())
        {
            vll a;
            ll n = sz(q);
            for(ll i = 0; i < n; i++)
            {
                auto it = q.front();
                q.pop();
                a.pb(it->val);
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
            ans.pb(a);
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};