#define ll int
#define vll vector<ll>
#define Node TreeNode
#define L left
#define R right

class Solution {
public:
    void P(Node* root, unordered_map<Node*,Node*>& parent)
    {
        if(!root) return;
        if(root->L) parent[root->L] = root;
        if(root->R) parent[root->R] = root;
        P(root->L,parent);
        P(root->R,parent);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
        unordered_map<Node*,ll> visited;
        unordered_map<Node*,Node*> parent;
        queue<Node*> q;
        P(root,parent);

        q.push(target);
        visited[target] = 1;

        vll ans;
        ll cnt = 0;

        while(!q.empty())
        {
            ll sz = q.size();
            if(cnt++ == k) break;

            for(ll i = 0; i < sz; i++)
            {
                Node* node = q.front();
                q.pop();

                Node* p = parent[node];

                if(p && visited[p] != 1)
                {
                    q.push(p);
                    visited[p] = 1;
                }

                if(node->L && visited[node->L] != 1)
                {
                    q.push(node->L);
                    visited[node->L] = 1;
                }

                if(node->R && visited[node->R] != 1)
                {
                    q.push(node->R);
                    visited[node->R] = 1;
                }
            }
        }

        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};