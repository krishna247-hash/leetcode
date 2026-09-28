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
    
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long > ans;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty())
        {
            long long sum = 0;
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                sum += node->val;
            }
            ans.push_back(sum);
        }
        if(ans.size() < k)

            return -1;
        sort(ans.begin(),ans.end(),greater<long long>());

        return ans[k-1];
    }
};