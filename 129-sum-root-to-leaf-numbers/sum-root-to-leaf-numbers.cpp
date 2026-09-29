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
        if(root != NULL && root->left == NULL && root->right == NULL) return true;

        return false;
    }

    void BST(TreeNode* root, vector<vector<int>>& ans, vector<int>& temp)
    {
        if(root == NULL) return;
        temp.push_back(root->val);
        if(isLeaf(root))
        {
            ans.push_back(temp);
            temp.pop_back();
            return;
        }

        BST(root->left,ans,temp);
        BST(root->right,ans,temp);
        temp.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        BST(root,ans,temp);
        for(auto it: ans)
        {
            int tempSum = 0;
            for(auto x: it)
            {
                tempSum = tempSum * 10 + x;
            }
            sum += tempSum;
        }

        return sum;
    }
};