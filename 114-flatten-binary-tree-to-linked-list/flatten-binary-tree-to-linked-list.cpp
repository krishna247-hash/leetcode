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
    void preOrder(TreeNode* root, vector<TreeNode* > & arr)
    {
        if(root == NULL) return ;
        arr.push_back(root);
        preOrder(root->left,arr);
        preOrder(root->right,arr);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode* > arr;
        preOrder(root,arr);
        for(int i = 1; i < arr.size(); i++)
        {
            arr[i-1]->right = arr[i];
            arr[i-1]->left = NULL;
        }

    }
};