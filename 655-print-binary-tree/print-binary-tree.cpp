#define F first
#define S second
#define L left
#define R right
class Solution {
public:
    
    int DFS(TreeNode* root)
    {
        if(!root) return 0;

        return 1+max(DFS(root->left),DFS(root->right));
    }
    vector<vector<string>> printTree(TreeNode* root) {
        
        int m = DFS(root);
        int n = (1<<m) - 1;
        vector<vector<string>> ans(m,vector<string>(n));
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,n/2}});

        while(!q.empty())
        {
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                auto it = q.front();
                q.pop();
                int x = it.S.F;
                int y = it.S.S;
                TreeNode* node = it.F;
                ans[x][y] = to_string(node->val);

                if(node->left) q.push({node->L,{x+1,y-(1<<m-1-x-1)}});
                if(node->R) q.push({node->R,{x+1,y+(1<<m-1-x-1)}});

            }
        }
        return ans;
    }

    
};