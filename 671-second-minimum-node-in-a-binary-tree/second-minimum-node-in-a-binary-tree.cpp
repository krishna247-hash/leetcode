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
    void DFS(TreeNode* root, set<int>& st)
    {
        if(root == nullptr) return;
        st.insert(root->val);
        DFS(root->left,st);
        DFS(root->right,st);
    }
    int findSecondMinimumValue(TreeNode* root) {
        set<int> st;
        DFS(root,st);
        vector<int> ans;
        for(auto it: st)
        ans.push_back(it);
        
        if(ans.size() < 2) return -1;

        return ans[1];
    }
};