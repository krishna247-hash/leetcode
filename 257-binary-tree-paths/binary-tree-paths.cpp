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
        if(root->right == NULL && root->left == NULL) 
        return true;

        return false;
    }

    void DFS(TreeNode* root, string temp,vector<string>& ans)
    {
        if(root == NULL) return;
        if(isLeaf(root))
        {
            ans.push_back(temp);
            return;
        }

        if(root->left)
    DFS(root->left, temp + "->" + to_string(root->left->val), ans);

if(root->right)
    DFS(root->right, temp + "->" + to_string(root->right->val), ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> ans;
        string temp = to_string(root->val);
        DFS(root,temp,ans);

        return ans;
    }
};