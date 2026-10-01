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
        if(root->left == nullptr && root->right == NULL) return true;

        return false;
    }
    void DFS(TreeNode* root, int cnt, int& ans)
    {
        if(root == nullptr) return;
        if(isLeaf(root))
        {
            ans = min(ans,cnt);
            return;
        }

        DFS(root->left,cnt+1,ans);
        DFS(root->right,cnt+1,ans);
    }
    int minDepth(TreeNode* root) {
        int ans = INT_MAX;
        int cnt = 1;
        if(root == NULL) return 0;
        DFS(root,cnt,ans);
        return ans;
    }
};