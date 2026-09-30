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
    bool checkLeaf(TreeNode* root)
    {
        if(root != nullptr && root->left == nullptr && root->right == nullptr)
        return true;

        return false;
    }

    void DFS(TreeNode* root, int& targetSum , int& sum, vector<vector<int>>& ans, vector<int>& temp)
    {
        if(root == NULL) return;

        sum += root->val;
        temp.push_back(root->val);
        if(sum == targetSum && checkLeaf(root))
        {
            ans.push_back(temp);
        }

        DFS(root->left,targetSum,sum,ans,temp);
        DFS(root->right,targetSum,sum,ans,temp);
        sum -= root->val;
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
         DFS(root,targetSum,sum,ans,temp);

        return ans;
    }
};