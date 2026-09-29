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
    void solve(TreeNode* root ,int targetSum ,int sum,int& ans)
    {
        if(root == NULL) return;
        sum += root->val;
       if(root->left == NULL && root->right == NULL)
       {
         if( sum == targetSum)
        {
            ans = sum;
            return;
        }
       }
        
        solve(root->left, targetSum, sum , ans);
        solve(root->right, targetSum, sum , ans);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        int ans = INT_MIN;
        int sum = 0;
        solve(root,targetSum,sum,ans);
      
        return (ans != INT_MIN);
    }
};