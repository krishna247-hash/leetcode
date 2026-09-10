class Solution {
public:

    int ans = 0;

    pair<int, int> dfs(TreeNode* root)
    {
        if(root == NULL)
            return {0, 0};

        // Get information from left subtree
        pair<int, int> left = dfs(root->left);

        // Get information from right subtree
        pair<int, int> right = dfs(root->right);

        // Sum of current subtree
        int sum = root->val + left.first + right.first;

        // Number of nodes in current subtree
        int count = 1 + left.second + right.second;

        // Average of current subtree
        int avg = sum / count;

        if(root->val == avg)
            ans++;

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root)
    {
        dfs(root);
        return ans;
    }
};