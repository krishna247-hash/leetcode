#define L left
#define R right
class Solution {
public:
    void parentMP(TreeNode* root,unordered_map<TreeNode* , TreeNode* >& parent)
    {
        if(!root) return;

        if(root->L) parent[root->L] = root;
        if(root->R) parent[root->R] = root;

        parentMP(root->L,parent);
        parentMP(root->R,parent);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode* , TreeNode* > parent;
        parent[root] = NULL;
        parentMP(root,parent);
        unordered_map<TreeNode* , int> mp;

        queue<TreeNode*> pq;
        pq.push(p);
        mp[p] = 1;
        mp[root] = 1;

        while(!pq.empty())
        {
            int sz = pq.size();
            for(int i=0; i<sz; i++)
            {
                TreeNode* node = parent[pq.front()];

                if(node)
                {
                    mp[node] = 1;
                    pq.push(node);
                }
                pq.pop();
            }
        }

        if(mp[q] == 1) return q;
        pq.push(q);

        while(!pq.empty())
        {
            int sz = pq.size();
            for(int i = 0; i < sz; i++)
            {
                TreeNode* node = pq.front();
                if(mp[node] == 1)
                {
                    return node;
                }
                if(parent[node])
                {
                pq.push(parent[node]);
                }
                pq.pop();
            }
        }

        return root;

    }
};