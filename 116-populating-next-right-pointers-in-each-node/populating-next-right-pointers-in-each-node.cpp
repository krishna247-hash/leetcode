/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return nullptr;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size() - 1;
            Node* prev = q.front();
            q.pop();
               if(prev->left != NULL) 
                q.push(prev->left);
                if(prev->right != NULL)
                q.push(prev->right);

            for(int i = 0; i < n; i++)
            {
                Node* newnode = q.front();
                q.pop();
                prev->next = newnode;
                prev = newnode;
                if(newnode->left != NULL) 
                q.push(newnode->left);
                if(newnode->right != NULL)
                q.push(newnode->right);
            }

           
        }
        return root;
    }
};