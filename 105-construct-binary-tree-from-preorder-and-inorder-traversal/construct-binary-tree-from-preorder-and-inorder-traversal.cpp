#define F first
#define S second
#define L left
#define R right
#define Node TreeNode
#define ll int

class Solution {
public:
TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
vector<int>& inorder, int inStart, int inEnd,
unordered_map<ll, ll>& inMP)
{
if(preStart > preEnd || inStart > inEnd) return NULL;

    Node *root = new Node(preorder[preStart]);
    int inRoot = inMP[root->val];
    int numsLeft = inRoot - inStart;
    root->L = build(preorder, preStart+1, preStart+numsLeft,
                    inorder, inStart, inRoot-1, inMP);
    root->R = build(preorder, preStart+numsLeft+1, preEnd,
                    inorder, inRoot+1, inEnd, inMP);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    unordered_map<ll, ll> inMP;
    for(ll i = 0; i < inorder.size(); i++)
        inMP[inorder[i]] = i;
    return build(preorder, 0, preorder.size()-1,
                 inorder, 0, inorder.size()-1, inMP);

}
};