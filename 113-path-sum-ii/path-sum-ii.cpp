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
class Solution {
public:
    bool isLeaf(TreeNode* root)
    {
        if(root != nullptr && root->left == nullptr && root->right == nullptr)
        return true;

        return false;
    }

    void DFS(TreeNode* root, int sum, int targetSum, vector<int>& temp,vector<vector<int>>& ans )
    {
        if(root == nullptr) return ;
        if(sum == targetSum && isLeaf(root))
        {
            ans.push_back(temp);
            return;
        }
        if(root->left)
        {
            temp.push_back(root->left->val);
        DFS(root->left,sum+root->left->val,targetSum,temp,ans);
        temp.pop_back();
        }

        if(root->right)
        {
            temp.push_back(root->right->val);
        DFS(root->right,sum+root->right->val,targetSum,temp,ans);
        temp.pop_back();
        }
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        int sum = root->val;
        vector<int> temp;
        temp.push_back(root->val);
        DFS(root,sum,targetSum,temp,ans);


        return ans;
    }
};