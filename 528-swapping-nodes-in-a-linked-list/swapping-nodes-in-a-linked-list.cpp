class Solution {
public:
    ListNode* solve(ListNode* head , int k)
    {
        vector<ListNode*> arr;

        ListNode* temp = head;
        while(temp != NULL)
        {
            ListNode* node = temp;
            temp = temp->next;
            node->next = NULL;
            arr.push_back(node);
        }

        swap(arr[k-1],arr[arr.size()-k]);
        for(int i = 1; i < arr.size(); i++)
        {
            arr[i-1]->next = arr[i];
        }
        return arr[0];
    }
    ListNode* swapNodes(ListNode* head, int k) {

        return solve(head,k);

    }
};