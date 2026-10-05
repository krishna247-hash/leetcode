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
 #define F first
 #define S second
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode* ,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!(q.empty()))
        {
            auto P = q.front();
            q.pop();
            TreeNode* node = P.F;
            int x = P.S.F;
            int y = P.S.S;

            mp[x][y].insert(node->val);

            if(node->left != NULL) q.push({node->left , {x - 1, y + 1}});
            if(node->right != NULL) q.push({node->right , {x + 1, y + 1}});
        }

        for(auto it: mp)
        {
            vector<int> temp;
            for(auto x : it.S)
            {
                
                for(auto i : x.S)
                {
                    temp.push_back(i);
                }
               
            }
             ans.push_back(temp);
        }

        return ans;
    }
};