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
    void DFS(TreeNode* root, vector<int>& arr)
    {
        if(root == NULL) return ;
        arr.push_back(root->val);
        DFS(root->left,arr);
        DFS(root->right, arr);
    }
    bool findTarget(TreeNode* root, int k) {
        int target = k;
        vector<int> arr;
        DFS(root,arr);
        if(arr.size() < 2) return 0;
        sort(arr.begin(),arr.end());
        int low = 0;
        int high = arr.size()-1;
        while(low < high)
        {
            if(arr[low]+arr[high] == target) return 1;
            else if(arr[low]+arr[high] < target) low ++;
            else high--;
        }
        return 0;
    }
};